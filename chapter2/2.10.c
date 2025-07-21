#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>



char lower(char b)
{
    int a = 0;

    b = (b > 'A'  && b < 'Z') ? (b - 'A' + 'a') : b;

    return b;

}


int main()
{
    char b = 'l';

    printf("%c", lower(b));
    
}