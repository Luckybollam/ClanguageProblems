#include <stdio.h>
#include <stddef.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/mman.h>

#define _GNU_SOURCE
#define MAXALLOC 1000000 //1 megabyte 
#define MAXNUMALLOC 50

size_t allocedbytes = 0;

struct ptrs {
    void *ptr;
    size_t size;
    bool open;
} ptrs[MAXNUMALLOC];

int my_free(void *);

void *my_malloc(size_t size)
{
    int k;
    if (MAXALLOC < allocedbytes+size) {
        printf("Too big, cannot allocate\n");
        return NULL;
    }
    if (size == 0) {
        printf("Cannot allocate 0 bytes\n");
        return NULL;
    }

    void* ptr = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

    if (ptr == MAP_FAILED) {
        printf("Failed to allocate\n");
        return NULL;
    }
    allocedbytes += size;

    for (k = 0; k < MAXNUMALLOC; k++) {
        if (ptrs[k].open == true) {
            ptrs[k].ptr = ptr;
            ptrs[k].size = size;
            ptrs[k].open = false;
            return ptr;
        }
    }
    munmap(ptr, size);
    allocedbytes -= size;
    printf("too many allocated chunks, please free\n");
    return NULL;
}

int my_free(void * ptr) {
    for (int j = 0; j < MAXNUMALLOC; j++) {
        if(!ptrs[j].open && ptrs[j].ptr == ptr) {
            if(munmap(ptrs[j].ptr,ptrs[j].size) == -1){
                printf("Could not free\n");
                return 1;
            }
            else {
                allocedbytes -= ptrs[j].size;
                ptrs[j].open = true;
                ptrs[j].ptr = NULL;
                ptrs[j].size = 0;
                return 0;
            }
        }
        
    }
    printf("Size not found\n");
    return 2;
}

int main()
{
    for (int j = 0; j < MAXNUMALLOC; j++) {
        ptrs[j].open = true;
    }
    int* test;
    test = my_malloc(sizeof(int));
    if(test == NULL)
    {
        printf("Malloc failed\n");
        return 1;
    }
    printf("Total allocated: %zu bytes\n", allocedbytes);
    *test = 20;
    printf("%d\n", *test);
    my_free(test);
    return 0;
}