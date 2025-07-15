#include <stdio.h>

#define MAXLINE 1000

int main(){

    int i, lim;
    char c;
    lim = 12;
    char s[MAXLINE];

    for (i = 0; i < lim-1; i++)
    {
        if((c = getchar()) != '\n')
        {
            if (c != EOF)
            {
                s[i] = c;
            }
        }

    }

    for (i = 0; i < lim; i++)
    {
        printf("%c", s[i]);
    }
}