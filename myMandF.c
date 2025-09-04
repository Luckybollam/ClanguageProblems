#include <stdio.h>
#include <stddef.h>

#define MAXALLOC 1000000 //1 megabyte 
#define MAXNUMALLOC 50

size_t allocedbits = 0;
int i = 0;

struct ptrs {
    void *ptr;
    size_t size;
    bool open;
} ptrs[MAXNUMALLOC];



void *my_malloc(size_t size)
{
    
    if (MAXALLOC <= allocedbits+size) {
        printf("Too big, cannot allocate");
        return NULL;
    }
    if (MAXNUMALLOC >= i) {
        printf("Too many allocated chunks, please free");
        return NULL;
    }

    void* ptr = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

    if (ptr == MAP_FAILED) {
        printf("Failed to allocate");
        return NULL;
    }

    for (int k = 0; k < MAXNUMALLOC; k++) {
        if (ptrs[k].open == true) {
            ptrs[k].ptr = ptr;
            ptrs[k].size = size;
            ptrs[k].open = false;
        }
        i++;
    }
    return ptr;
}

int my_free(void * ptr) {
    for (int j = 0; j < i; j++) {
        if(ptrs[j].ptr == ptr) {
            if(munmap(ptrs[j].ptr,ptrs[j].size) == -1){
                printf("Could not free");
                return 1;
            }
            else {
                allocedbits = allocedbits - ptrs[j].size;
                ptrs[j].open = true;
                return 0;
            }
        }
        
    }
    printf("Size not found");
    return 2;
}

int main()
{
    for (int j = 0; j < MAXNUMALLOC; j++) {
        ptrs[j].open = true;
    }

}