#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>


int strrindex(char s, char t[])
{
    int i;
    int temp = 0;

    for (i = 0; i < strlen(t); i++)
    {
        if (s == t[i])
        {
            temp = i;
            if (temp < i)
            {
                temp = i;
            }
            
        }
    }

    if (temp > -1)
    {
        return temp;
    }
    else
    {
        return -1;
    }
    

}

int main()
{
    char s = 's';

    char t[26];

    for (int i = 0; i < 26; i++)
    {
        t[i] = 'a' + i;
    }
    

    printf("%d", strrindex(s,t));

}
