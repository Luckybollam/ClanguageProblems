#include <stdio.h>

//tab, space and new line counter

int main()
{
    int c;
    int i = 0;

    
    while ((c = getchar()) != EOF)
    {
        if (c == 9)
        {
            c = ' ';
        }

        if (c == ' ')
        {
            i++;
            if (i > 1)
            {
                c = '\b';
                i = 0;
            }
        }
        if (c != ' ')
        {
            i = 0;
        }
        putchar(c);
    }
    
} 