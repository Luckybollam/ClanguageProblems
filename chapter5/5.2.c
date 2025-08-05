#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define BUFSIZE 100

char buf[BUFSIZE];  
int bufp = 0;       

int getch(void)  
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)  
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}


int getfloat(float *pn)
{
    int c, sign;
    while (isspace(c = getch()))
    {
        ;
    }
    if (!isdigit(c) && c != EOF && c != '+' && c != '-')
    {
        ungetch(c);
        return 0;
    }

    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
    {
        int signchar = c;
        c = getch();
        if (!isdigit(c) && c != '.')
        {
            ungetch(c);
            ungetch(signchar);
            return 0;
        }
    }
    for (*pn = 0; isdigit(c); c = getch())
    {
        *pn = 10 * *pn + (c - '0');

    }
    if (c == '.')
    {
        c = getch();
        float power = 1.0;
        for (;isdigit(c); c = getch())
        {
            *pn = *pn + (c - '0')/(power *= 10.0);
        }
    }

    *pn *= sign;
    if (c != EOF)
    {
        ungetch(c);
    }

    return c;
}

int main()
{
    int n; float array[25];
    for (n = 0; n < 25 && getfloat(&array[n]) != EOF; n++)
    {
        ;
    }
    
}
