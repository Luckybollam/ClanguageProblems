#include <stdio.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 80

int main() {
    int c;
    int col = 0;

    while ((c = getchar()) != EOF) {
        if (isprint(c)) {
            putchar(c);
            col++;
        } else if (c == '\n') {
            putchar('\n');
            col = 0;
        } else {
            printf("\\x%02X", (unsigned char)c);
            col += 4; 
        }

        if (col >= MAX_LINE_LENGTH) {
            putchar('\n');
            col = 0;
        }
    }

    return 0;
}
