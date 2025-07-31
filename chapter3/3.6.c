#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

void reverse (char s[], int w)
{
    int c, i, j;
    for (i = 0, (j = (strlen(s)-1)); i < j; i++, j--)
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }

    j = strlen(s);
    
    
    if (j < w)
    {
        for (;j < w; j++)
        {
            printf(" ");
        }
    }

    printf("%s", s);

}

void itoa(int n, char s[], int w)
{
    int i, sign;
    unsigned y;
    if ((sign = n) < 0)
    {
        y = -n;
    }
    else
    {
        y = n;
    }
    i = 0;
    do {
        s[i++] = (y % 10) + '0';
    } while ((y /= 10) > 0);
    if (sign < 0)
    {
        s[i++] = '-';
    }
    s[i++] = '\0';
    reverse(s, w);
    
}



int main()
{
    int w = 5;
    char s[20];
    int n = 89;
    itoa(n, s, w);

}
