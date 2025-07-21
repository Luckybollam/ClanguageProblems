#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

unsigned reverse(unsigned x, int p, int n)
{
    unsigned ybits = 0;
    unsigned xbits = 0;
    int i = 0;

    for (i = 0; i < n; i++)
    {
        ybits |= (1 << (p-(i+1)));
    }

    xbits = x;

  
    x = x & ~ybits;
    x = x | ybits;

    if (xbits == x)
    {
        x = x | ybits;
        x = x & ~ybits;
        
    }

    printf("%d", ybits);
    
    return x;
}

int main()
{
    printf("\n%d" ,reverse(0b11111111,4,3));
    //1111 111 1
    //0000 111 0


    

    //1111 000 1
    


    




    
    
}