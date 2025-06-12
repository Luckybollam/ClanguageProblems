#include <stdio.h>

//tab, space and new line counter

int main()
{
    int c;
    int nl = 0;
    int space = 0;
    int tab = 0;
    
    while ((c = getchar()) != EOF)
    {
        if (c == '\n')
        {
            ++nl;
        }
        if (c == ' ')
        {
            ++space;
        }
        if (c == 9)
        {
            ++tab;
        }


        printf("%d %d %d\n", nl, space, tab);
    }

    
} 