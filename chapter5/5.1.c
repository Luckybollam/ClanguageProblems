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


int getint(int *pn)
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
        c = getch();
        if (!isdigit(c))
        {
            ungetch(c);
            ungetch(sign);
            return 0;
        }
    }
    for (*pn = 0; isdigit(c); c = getch())
    {
        *pn = 10 * *pn + (c - '0');
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
    int n, array[25], getint(int *);
    for (n = 0; n < 25 && getint(&array[n]) != EOF; n++)
    {
        ;
    }
    
}
