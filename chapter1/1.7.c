#include <stdio.h>

int main()
{
    int c;
    int i = 0;

    while((c = getchar()) != EOF)
    {    
        putchar(c);
        i++;
        if (i == 10)
        {
            break;
        }
    }
    printf("\n%d", EOF);

    //eof is -1
}   