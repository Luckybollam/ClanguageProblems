#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#define BUFSIZ 1024
#define MY_OPEN_MAX 20
#define PERMS 0666

enum _flags {
    _READ  = 01,
    _WRITE = 02,
    _UNBUF = 04,
    _EOF   = 010,
    _ERR   = 020
};

typedef struct _iobuf {
    int cnt;           // characters left
    char *ptr;         // next character position
    char *base;        // location of buffer
    struct {
        unsigned is_read  : 1;
        unsigned is_write : 1;
        unsigned is_unbuf : 1;
        unsigned is_eof   : 1;
        unsigned is_err   : 1;
    } flags;
    int fd;            // file descriptor
} FILE;

FILE _iob[MY_OPEN_MAX] = {
    { 0, NULL, NULL, {1, 0, 0, 0, 0}, 0 },
    { 0, NULL, NULL, {0, 1, 0, 0, 0}, 1 },
    { 0, NULL, NULL, {0, 1, 1, 0, 0}, 2 }
};

#define stdin  (&_iob[0])
#define stdout (&_iob[1])
#define stderr (&_iob[2])

#define feof(p)     ((p)->flags.is_eof)
#define ferror(p)   ((p)->flags.is_err)
#define fileno(p)   ((p)->fd)

#define getc(p)     (--(p)->cnt >= 0 ? (unsigned char) *(p)->ptr++ : _fillbuf(p))
#define putc(x,p)   (--(p)->cnt >= 0 ? *(p)->ptr++ = (x) : _flushbuf((x), p))
#define getchar()   getc(stdin)
#define putchar(x)  putc((x), stdout)

int _fillbuf(FILE *fp) {
    int bufsize;

    if (!fp->flags.is_read || fp->flags.is_eof || fp->flags.is_err)
        return -1;

    bufsize = fp->flags.is_unbuf ? 1 : BUFSIZ;

    if (fp->base == NULL) {
        fp->base = (char *) malloc(bufsize);
        if (fp->base == NULL) {
            fp->flags.is_err = 1;
            return -1;
        }
    }

    fp->ptr = fp->base;
    fp->cnt = read(fp->fd, fp->ptr, bufsize);

    if (fp->cnt <= 0) {
        if (fp->cnt == 0)
            fp->flags.is_eof = 1;
        else
            fp->flags.is_err = 1;

        fp->cnt = 0;
        return -1;
    }

    fp->cnt--;
    return (unsigned char) *fp->ptr++;
}

int _flushbuf(int c, FILE *fp) {
    int bufsize;
    int n;

    if (!fp->flags.is_write)
        return -1;

    bufsize = fp->flags.is_unbuf ? 1 : BUFSIZ;

    if (fp->base == NULL) {
        fp->base = (char *) malloc(bufsize);
        if (fp->base == NULL) {
            fp->flags.is_err = 1;
            return -1;
        }
        fp->ptr = fp->base;
        fp->cnt = bufsize - 1;
    } else {
        n = fp->ptr - fp->base;
        if (write(fp->fd, fp->base, n) != n) {
            fp->flags.is_err = 1;
            return -1;
        }
        fp->ptr = fp->base;
        fp->cnt = bufsize - 1;
    }

    *fp->ptr++ = c;
    return c;
}

int fflush(FILE *fp) {
    if (fp == NULL) {
        for (fp = _iob; fp < _iob + MY_OPEN_MAX; fp++) {
            if (fp->flags.is_write)
                fflush(fp);
        }
        return 0;
    }

    if (!fp->flags.is_write || fp->base == NULL)
        return 0;

    int n = fp->ptr - fp->base;

    if (write(fp->fd, fp->base, n) != n) {
        fp->flags.is_err = 1;
        return -1;
    }

    fp->ptr = fp->base;
    fp->cnt = fp->flags.is_unbuf ? 0 : BUFSIZ;

    return 0;
}

int fclose(FILE *fp) {
    if (fp == NULL)
        return -1;

    if (fp->flags.is_write) {
        if (fflush(fp) == -1)
            return -1;
    }

    free(fp->base);
    fp->base = NULL;
    fp->ptr = NULL;
    fp->cnt = 0;

    fp->flags.is_read = 0;
    fp->flags.is_write = 0;
    fp->flags.is_unbuf = 0;
    fp->flags.is_eof = 0;
    fp->flags.is_err = 0;

    return close(fp->fd);
}

int fseek(FILE *fp, long offset, int origin) {
    if (fp->flags.is_write) {
        if (fflush(fp) == -1)
            return -1;
    } else if (fp->flags.is_read) {
        if (origin == SEEK_CUR)
            offset -= fp->cnt;
    }

    long pos = lseek(fp->fd, offset, origin);
    if (pos == -1) {
        fp->flags.is_err = 1;
        return -1;
    }

    fp->cnt = 0;
    fp->ptr = fp->base;
    fp->flags.is_eof = 0;

    return 0;
}

FILE *fopen(const char *name, const char *mode) {
    int fd;
    FILE *fp;

    if (*mode != 'r' && *mode != 'w' && *mode != 'a') return NULL;

    for (fp = _iob; fp < _iob + MY_OPEN_MAX; fp++) {
        if (!fp->flags.is_read && !fp->flags.is_write)
            break;
    }
    if (fp >= _iob + MY_OPEN_MAX) return NULL;

    if (*mode == 'w')
        fd = creat(name, PERMS);
    else if (*mode == 'a') {
        if ((fd = open(name, O_WRONLY)) == -1)
            fd = creat(name, PERMS);
        lseek(fd, 0L, SEEK_END);
    } else {
        fd = open(name, O_RDONLY);
    }

    if (fd == -1) return NULL;

    fp->fd = fd;
    fp->cnt = 0;
    fp->base = NULL;
    fp->flags.is_read = (*mode == 'r');
    fp->flags.is_write = (*mode != 'r');
    fp->flags.is_unbuf = 0;
    fp->flags.is_eof = 0;
    fp->flags.is_err = 0;

    return fp;
}

// Simple test
int main(int argc, char *argv[]) {
    FILE *fp;
    int c;

    if (argc == 2) {
        fp = fopen(argv[1], "r");
        if (fp == NULL) {
            write(2, "Error: cannot open file\n", 25);
            return 1;
        }

        while ((c = getc(fp)) != -1) {
            putchar(c);
        }

        fclose(fp);
    } else {
        const char *msg = "Hello from putchar!\n";
        while (*msg) {
            putchar(*msg++);
        }
        fflush(stdout);
    }

    return 0;
}
