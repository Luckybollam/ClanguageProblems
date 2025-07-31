#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>


//The issue with the largest negative number (for a 32-bit int, that's -2147483648) is that its positive counterpart (2147483648) is out of range for a signed 32-bit integer (int maxes out at 2147483647).

void reverse (char s[])
{
    int c, i, j;
    for (i = 0, (j = (strlen(s)-1)); i < j; i++, j--)
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
    printf("%s", s);

}

void itoa(int n, char s[])
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
    reverse(s);
    
}



int main()
{
    char s[20];
    int n = 89;
    itoa(n, s);

}
