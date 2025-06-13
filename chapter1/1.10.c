#include <stdio.h>

//replace all tabs with /t, backspaces with /b, and backslash with '//'

int main()
{
    int c;
    int nl = 0;
    int space = 0;
    int tab = 0;
    
    while ((c = getchar()) != EOF)
    {
        if (c == 9)
        {
            c = '\0';
            printf("\\t");
        }
        if (c == 8)
        {
            printf("\\b");
        }
        if (c == 92)
        {
            printf("\\");
        }
        putchar(c);
    }

    
} 