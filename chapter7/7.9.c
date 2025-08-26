#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

int main()
{
    int c = 'a';
    int start;
    int end;
    start = clock();
    printf("Nonzero if its upper, 0 if not: %d\n", isupper(c));
    end = clock();
    int total = end - start;
    printf("Time to run in ms: %d\n", total);

    start = clock();
    printf("Nonzero if its upper, 0 if not: %d\n" ,(64 < c && c < 91) ? 1 : 0);
    end = clock();
    total = end - start;
    printf("Time to run in ms: %d\n", total);

}