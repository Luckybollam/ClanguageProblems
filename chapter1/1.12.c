#include <stdio.h>


#define OUT 1
#define IN 0
//Print each word on a new line

int main()
{
    int c, nl, nw, nc, state;
    state = OUT;
    nl = nw = nc = 0;
    while ((c = getchar()) !=  EOF)
    {
        if (c == '\n')
        {
            ++nl;
        }
        if (c == ' ' || c == '\n' || c == '\t')
        {
            state = OUT;
        }
        else if (state == OUT)
        {
            state = IN;
            ++nw;
            printf("\n");
        }
        putchar(c);
        


    }

    
} 