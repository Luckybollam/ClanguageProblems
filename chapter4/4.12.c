#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

int j = 0;

void itoa(int n)
{
    static int j = 0;
    char s[100];

    if (n < 0)
    {
        putchar('-');
        n = -n;
    }
    if (n/10)
    {
        itoa(n/10);
        j++;
    }
    //printf("%d", j);
    
    s[j] = n % 10 + '0';
    printf("%c", s[j]);
    
    

}

int main()
{
    int n = 108;
    itoa(n);    

}
