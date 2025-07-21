#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

//x =& x - 1 = x = x & (x-1)
//the last most bit gets cleared because the -1 changes the polarity (odd or even), and so no matter what, the last most bit will get cleared because it will be oppposite


int bitcount(unsigned x)
{
    int b;

    for (b = 0; x != 0; x &= (x-1))
    {
        b++;
    }
    return b;

}


int main()
{
    int x = 0b11111111;
    printf("%d", bitcount(x));
    
}