#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    int i;
    for (i = 1; i < argc; i++)
    {
        printf("%s ", argv[i]);
    }
    int stack[100];
    int *sp = stack;
    int val;

    
    for (i = 1; i < argc; i++)
    {
        if ((isdigit(argv[i][0]) || (argv[i][0] == '-' && isdigit(argv[i][1]))))
        {
            *sp++ = atoi(argv[i]);
            
        }
        else if (strcmp(argv[i], "+") == 0)
        {
            int op2 = *--sp;
            int op1 = *--sp;
            val = op1 + op2;
            *sp++ = val;

        }
        else if (strcmp(argv[i], "-") == 0)
        {
            int op2 = *--sp;
            int op1 = *--sp;
            val = op1 - op2;
            *sp++ = val;

        
        }
        else if (strcmp(argv[i], "*") == 0)
        {
            int op2 = *--sp;
            int op1 = *--sp;
            val = op1 * op2;
            *sp++ = val;
        }
        
    }
    printf("\n%d", *(sp-1));

}