#include <stdio.h>


#define OUT 1
#define IN 0
//testing word count program
//To test this program, my input would contain multiple words with tabs, spaces and new lines to ensure each test case is covered and handled appropriately.

int main()
{
    int c, nl, nw, nc, state;
    state = OUT;
    nl = nw = nc = 0;
    while ((c = getchar()) !=  EOF)
    {
        ++nc;
        if (c = '\n')
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
        }
    }
    printf("%d %d %d\n", nl, nw, nc);

    
} 