#include <unistd.h>
#include <stddef.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

#define NALLOC 1024
#define SIZE_MAP_LIMIT 50

typedef long Align;

struct {
    void *ptr;
    unsigned size;
} sizes_map[SIZE_MAP_LIMIT];

int incr = 0;

union header {
    struct {
        union header *ptr;
        unsigned size;
    } s;
    Align x;
};

typedef union header Header;

static Header base;
static Header *freep = NULL;

void free(void *ap) {
    Header *bp, *p;

    bp = (Header *)ap - 1;
    bool found = false;
    for (int i = 0; i < incr; i++) {
        if (ap == sizes_map[i].ptr && bp->s.size == sizes_map[i].size) {
            found = true;
            break;
        }
    }
    if (!found) {
        printf("Invalid free: pointer not tracked or wrong size\n");
        return;
    }

    for (p = freep; !(bp > p && bp < p->s.ptr); p = p->s.ptr) {
        if (p >= p->s.ptr && (bp > p || bp < p->s.ptr)) {
            break;
        }
    }

    if (bp + bp->s.size == p->s.ptr) {
        bp->s.size += p->s.ptr->s.size;
        bp->s.ptr = p->s.ptr->s.ptr;
    } else {
        bp->s.ptr = p->s.ptr;
    }

    if (p + p->s.size == bp) {
        p->s.size += bp->s.size;
        p->s.ptr = bp->s.ptr;
    } else {
        p->s.ptr = bp;
    }

    freep = p;
}

static Header *morecore(unsigned nu) {
    char *cp;
    Header *up;
    if (nu < NALLOC)
        nu = NALLOC;

    cp = mmap(NULL, nu * sizeof(Header),
              PROT_READ | PROT_WRITE,
              MAP_PRIVATE | MAP_ANONYMOUS,
              -1, 0);

    if (cp == (char *)-1)
        return NULL;

    up = (Header *)cp;
    up->s.size = nu;
    free((void *)(up + 1));
    return freep;
}

void *malloc(size_t nbytes) {
    if (nbytes > SIZE_MAX - sizeof(Header)) {
        printf("Too big\n");
        return NULL;
    }

    Header *p, *prevp;
    unsigned nunits;
    nunits = (nbytes + sizeof(Header) - 1) / sizeof(Header) + 1;

    if ((prevp = freep) == NULL) {
        base.s.ptr = freep = prevp = &base;
        base.s.size = 0;
    }

    for (p = prevp->s.ptr;; prevp = p, p = p->s.ptr) {
        if (p->s.size >= nunits) {
            if (p->s.size == nunits) {
                prevp->s.ptr = p->s.ptr;
            } else {
                p->s.size -= nunits;
                p += p->s.size;
                p->s.size = nunits;
            }
            freep = prevp;

            if (incr < SIZE_MAP_LIMIT) {
                sizes_map[incr].ptr = (void *)(p + 1);
                sizes_map[incr].size = nunits;
                incr++;
            }

            return (void *)(p + 1);
        }

        if (p == freep) {
            if ((p = morecore(nunits)) == NULL)
                return NULL;
        }
    }
}

void *calloc(size_t nbytes, size_t size) {
    size_t fullsize = nbytes * size;
    void *p = malloc(fullsize);
    if (p == NULL)
        return NULL;

    char *ptr = p;
    for (size_t i = 0; i < fullsize; i++) {
        *ptr++ = 0;
    }
    return p;
}

void bfree(p, n)
{
    
}

int main() {
    return 0;
}
