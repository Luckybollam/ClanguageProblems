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

    while ((c = getchar()) != 27)
    {

        line[i] = c;
        i++; 
        
    }
    for (j = 0; j < i; j++)
    {
        longest[j] = line[(i-1)-j];
    }
    printf("%s", longest);
    return 0;
}
