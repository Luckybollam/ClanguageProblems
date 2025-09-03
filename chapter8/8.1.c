#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>  


#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s file1 [file2 ...]\n", argv[0]);
        return 1;
    }

    char buffer[BUFFER_SIZE];
    size_t bytesRead;
    int f1, f2, n;

    if ((f1  = open(argv[1], O_RDONLY, 0)) == -1)
    {
        printf("Error: can't open %s\n", argv[1]);
        return 1;
    }
    if ((f2 = creat(argv[2], 0666)) == -1)
    {
        close(f1);
        printf("Error: can't open %s\n", argv[2]);
        return 1;
    }

    while((n = read(f1, buffer, BUFFER_SIZE)) > 0)
    {
        if (write(f2, buffer, n) != n)
        {
            close(f1);
            close(f2);
            printf("Error: write error on file %s\n", argv[2]);
            return 1;
        }
    }

    close(f1);
    close(f2);

    return 0;
}
