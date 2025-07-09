#include <stdio.h>
#define MAXLINE 1000
#define COLUMN 25

//FOLD

int get_line(char s[], int lim)
{
    int c, i, count, j;
    count = 0;

    char temp = ' ';

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
    
    //printf("I is %d\n", i);
    for (j = 0; j < i; j++)
    {
        if(s[j] == ' ' && count >! COLUMN)
        {
            s[j] = '\n';
            count = 0;
        }

        if(s[j] != ' ' && count > COLUMN)
        {
            //printf("\nbonk\n");
            count = 0;
            temp = s[i-1];
            s[j] = '\n';

            for (j=j+2; j < (i-(count-1)); j ++)
            {                
                s[j] = s[j-1];
            }
        }
        count++;
    
    }
    //printf("\ncount is %d", count);

    for (j = 0; j < i; j++)    
    {
        printf("%c", s[j]);
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
