#include <stdio.h>

//letter counter

#define OUT 1
#define IN 0

int main()
{
    int c, nl, nw, nc, state, it;
    int i = 0;
    int word[26];

    for (i = 0; i < 26; i++)
    {
        word[i] = 0;   
    }

    state = OUT;
    nl = nw = nc = it = 0;
    
    while ((c = getchar()) !=  EOF)
    {
        if (c == ' ' || c == '\n' || c == '\t')
        {
            state = OUT;
        }
        else if (state == OUT)
        {
            state = IN;
        }
        else if (c < 'a')
        {
            ++word[c-'A'];
        }
        else
        {
            ++word[c-'a'];
        }

        //break from loop
        if (c == 27)
        {
            break;
        }
        
    }

    for (i = 0; i < 26; i++)
        {
            printf("%d", word[i]);  
        }
    
    

    
} 