#include <stdio.h>
#define MAXLINE 1000
#define COLUMN 25

//FOLD

int get_line(char s[], int lim)
{
    int c, i, count, j;
    count = 0;
    int count1 = 0;
    for (i = 0; i < (lim-1) && (c = getchar()) != EOF && c != '\n'; i++)
    {
        s[i] = c;
    }
    s[i] = '\0';

    for (j = 0; j < i; j++)
    {
        if (s[j] == '{' || s[j] == '}')
        {
            count1++;
        }
        else if (s[j] == '(' || s[j] == ')')
        {
            count++;
        }
    }

    if (count1 %2 != 0 || count %2 !=0)
    {
        printf("\n Syntax Error\n");
    }

    



    return i;

}


int main()
{
    int len;
    int max = 0;
    char line[MAXLINE];
    char longest[MAXLINE];
    int c;
    int j;
    while ((len = get_line(line, MAXLINE)) > 0)
    {
        if ((c = getchar()) ==  27)
        {
            break;
        }
    }


    return 0;
}
