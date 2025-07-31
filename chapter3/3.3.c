#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>


void expand(char s1[], char s2[])
{
    printf("%s\n", s1);

    int i, j, k, iter;

    for (i = 0; i < strlen(s1); i++)
    {
        if (s1[i] == '-' && s1[i-1] > 47 && s1[i-1] < 'z')
        {
            iter = s1[i+1] - s1[i-1];
            k = 0;
            for (j = 0; j < (iter+1); j++)
            {
                s2[j] = s1[i-1] + j;

            }
            printf("%s", s2);
        }
        for (j = 0; j < (iter+1); j++)
        {
            s2[j] = '\0';
        }
        printf("\n");
    }
   

}

int main()
{
    char s1[20] = {'a','-','z','0','-','9'};
    char s2[200];
    expand(s1, s2);

}
