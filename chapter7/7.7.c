#include <stdio.h>
#include <string.h>

#define MAXLINE 1000 

int main(int argc, char *argv[]) {
    char line[MAXLINE];
    int incr = 0;

    if (argc < 1) {
        printf("Usage: %s pattern\n", argv[0]);
        return 1;
    }
    else if (argc == 1)
    {
        char *pattern = argv[1];
        while (fgets(line, MAXLINE, stdin) != NULL) {
        if (strstr(line, pattern) != NULL) {
            printf("%s", line);
        }
        incr++;
            if (incr == 10)
            {
                break;
            }
        }
    }
    else
    {
        char *pattern = argv[1];
        FILE *fp = fopen(argv[2], "r");
        if (fp == NULL)
        {
            printf("File open error\n");
            return 1;
        }
        while (fgets(line, MAXLINE, fp) != NULL) {
            if (strstr(line, pattern) != NULL) {
                printf("%s", line);
            }
            incr++;
            if (incr == 10)
            {
                break;
            }
        }
    }

    

    return 0;
}
