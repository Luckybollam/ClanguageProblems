#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PAGE_LINES 50   
#define TITLE_WIDTH 40  

void print_file(FILE *fp, const char *filename) {
    int line_count = 0;
    int page_number = 1;
    char line[1024];

    printf("\f"); 
    printf("File: %-*s Page: %d\n\n", TITLE_WIDTH, filename, page_number);

    while (fgets(line, sizeof(line), fp)) {
        printf("%s", line);
        line_count++;

        if (line_count >= PAGE_LINES - 2) { 
            line_count = 0;
            page_number++;
            printf("\f");  
            printf("File: %-*s Page: %d\n\n", TITLE_WIDTH, filename, page_number);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s file1 [file2 ...]\n", argv[0]);
        return 1;
    }

    for (int i = 1; i < argc; ++i) {
        FILE *fp = fopen(argv[i], "r");
        if (!fp) {
            fprintf(stderr, "Could not open file: %s\n", argv[i]);
            continue;
        }

        print_file(fp, argv[i]);
        fclose(fp);
    }

    return 0;
}
