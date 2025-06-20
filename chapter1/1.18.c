#include <stdio.h>
#define MAXLINE 1000

int get_line(char s[], int lim)
{
    int c, i;
    for (i = 0; i < (lim-1) && (c = getchar()) != EOF && c != '\n'; i++)
    {
        s[i] = c;
    }

    if (c == '\n')
    {
        s[i] = c;
        i++;
    }
    s[i] = '\0';
    return i;
}

void copy(char to[], char from[])
{
    int i = 0;
    while ((to[i] = from[i]) != '\0')
    {
        ++i;
    }
}

int main()
{
    int len;
    int max = 0;
    char line[MAXLINE];
    char longest[MAXLINE];
    int c;

    while ((len = get_line(line, MAXLINE)) > 0)
    {
        printf("%d\n", len+1);
        if (len > 80)
        {
            copy(longest, line);
            printf("%s", longest);
        }
        if ((c = getchar()) ==  27)
        {
            break;
        }
    }

    if (max > 0)
    {
        printf("%s", longest);
    }

    return 0;
}
