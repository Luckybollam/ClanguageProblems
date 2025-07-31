#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>


void itob(int n, char s[], int b)
{
    int i = n;
    float r = b;
    int j = 0;
    int k = 0;
    int m = 0;
    char p[20];
    char test;

    do
    {
        k = i % b;
        if (k > 9)
        {
            k = 'A' + (k-10);
        }
        printf("k is %d\n", k);
        i = i / b;
        printf("i is: %d\n", i);
        if (k > 9)
        {
            test = k;
            p[m] = test;
        }
        else
        {
            p[m] = k + '0';
        }
        m++;     

    } while (i % b != 0);

    printf("m is: %d\n", m);

    for (j = (m-1); j > -1; j--)
    {
        printf("%c",p[j]);
    }
    



}

int main()
{
    char s1[20] = {};
    int n = 7562;
    int b = 16;
    itob(n, s1, b);

}
