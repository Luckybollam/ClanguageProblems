#include <stdio.h>



int getline1(char *s, int lim) {
    int c;
    char *start = s;

    while (--lim > 0 && (c = getchar()) != EOF && c != '\n') {
        *s++ = c;
    }
    if (c == '\n') {
        *s++ = c;
    }
    *s = '\0';

    return s - start;
}

int atoi1(const char *s) {
    int n = 0, sign = 1;

    while (*s == ' ' || *s == '\t' || *s == '\n') s++;

    if (*s == '+' || *s == '-') {
        sign = (*s == '-') ? -1 : 1;
        s++;
    }

    while (*s >= '0' && *s <= '9') {
        n = 10 * n + (*s - '0');
        s++;
    }

    return sign * n;
}

void reverse1(char *s) {
    char *end = s;
    while (*end) end++;
    end--;  

    while (s < end) {
        char temp = *s;
        *s = *end;
        *end = temp;
        s++;
        end--;
    }
}


void itoa1(int n, char *s) {
    int sign = n;
    char *start = s;

    if (n < 0) {
        n = -n;
    }

    do {
        *s++ = n % 10 + '0';
    } while ((n /= 10) > 0);

    if (sign < 0) {
        *s++ = '-';
    }

    *s = '\0';
    reverse1(start);
}


int main() {
    char buffer[100];

    printf("Enter a line: ");
    getline1(buffer, 100);
    printf("You entered: %s", buffer);

    int num = atoi1("   -1234");
    printf("\n %d\n", num);

    char str[20];
    itoa1(-5678, str);
    printf("String from int: %s\n", str);

    reverse1(str);
    printf("Reversed string: %s\n", str);

    return 0;
}

