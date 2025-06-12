#include <stdio.h>

int main()
{
    int c;
    int i = 0;

    while((c = getchar()) != EOF)
    {    
        printf("%d", c != EOF);
        putchar(c);
        i++;
        if (i == 10)
        {
            break;
        }
    }
    printf("\n%d", c != EOF);


}   
//getchar() != EOF is 1