#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

unsigned setbits(unsigned x, int p, int n,unsigned y)
{
    unsigned ybits = 0;
    unsigned xbits = 0;
    ybits = (1 << n) - 1;
    ybits = y & ybits;
    ybits = (ybits << (p-(n-1)));
    
    printf("%d\n", ybits);
    xbits = (1 << n) - 1;
    xbits = xbits << (p-(n));
    xbits = ~xbits;
    printf("xbits is %d\n", xbits);

    x = x & xbits;
    printf("x is: %d", x);
    x = x | ybits;
    return x;
}

int main()
{
    printf("\n%d" ,setbits(0b10101010,4,3,0b11110000));
    
}