#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

#define MAXLINE 1000



void htsi(char s[])
{
    int cond = 0;
    int j = 0;
    int i = 0;
    int n = 0;
    int it = 0;
    
    
    
    for (; i < strlen(s); i++){
        if (s[i-2] == '0' && (s[i-1] == 'x' || s[i-1 == 'X']))
        {
            cond = 1;
        }

        if (cond == 1)
        {
            if (s[i] <= '9' && s[i] >= '0' && s[i+1] <= '9' && s[i+1] >= '0')
            {
                n = ((s[i+1] - '0') * 1) + ((s[i]- '0') * 16);
            }
            else if (s[i+1] >= 'a' && s[i+1] <= 'f' && s[i] <= '9'  && s[i]  >= '0')
            {
                n = (((s[i+1] - 'a') + 10) * 1) + ((s[i]- '0') * 16);
            }
            else if (s[i] >= 'a' && s[i] <= 'f' && s[i+1] <= '9'  && s[i+1]  >= '0')
            {
                n = (((s[i] - 'a') + 10) * 16) + ((s[i+1]- '0') * 1);
            }
            else
            {
                n = (((s[i] - 'a') + 10) * 16) + ((s[i+1] - 'a') +10);
            }
            
            cond = 0;
            it++;
        }
    }
    printf("\n it is %d", n);

}

int main()
{
    char s[MAXLINE] = "0Xff";


    htsi(s);
    
    
}