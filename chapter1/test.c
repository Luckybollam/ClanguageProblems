#include <stdio.h>
#define MAXLINE 1000

//INPUT REVERSER

int main()
{
    int len;
    int max = 0;
    char line[MAXLINE];
    char longest[MAXLINE];
    int c;
    int i = 0;
    int j = 0;
    int k = 0;

    while ((c = getchar()) != 27)
    {

        line[i] = c;
        i++; 
        
    }
    line[i] = '\0';
    printf("%d\n", i);

    for (j = 0; j < i; j++)
    {
        if (line[j] != 32)
        {
            longest[j-k] = line[j];
        }
        else
        {
            k++;
        }
    }


    printf("%s\n", line);
    printf("%s\n", longest);
    return 0;
}
