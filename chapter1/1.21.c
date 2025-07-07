#include <stdio.h>
#define MAXLINE 1000

//ENTAB COMPLETE
//the tab should be given priority

int get_line(char s[], int lim)
{
    int c, i, count, j;
    char p[MAXLINE];
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

    for (j = 0; j < i; j++)
    {
        p[j] = s[j];
        //printf("%c", p[j]);
    }
    
    for (j = 0; j < i; j++)
    {
        if (p[j] == ' ')
        {
            count++;
        }
        else
        {
            if (count == 4){
                p[j-4] = '\t';
                p[j-3] = '\0';
                p[j-2] = '\0';
                p[j-1] = '\0';
            }
            count = 0; 
        }
    
    }

    for (j = 0; j < i; j++)
    {
        printf("%c", p[j]);
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
