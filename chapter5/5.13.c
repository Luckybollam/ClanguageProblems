#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define DEFAULT 10

int main(int argc, char* argv[])
{
    int i = argc-1;
    int val;
    val = atoi(argv[1]);

   //printf("val is %d, argc is: %d, I is: %d ", val, argc, i);
    int j  = i;

    for (i = (argc-1); i > (j-val); i--)
    {
        printf("%s ", argv[i]);
    }
}