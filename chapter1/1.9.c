#include <stdio.h>

// convert multiple blanks into single blank and tabs

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
                c = '\0';
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