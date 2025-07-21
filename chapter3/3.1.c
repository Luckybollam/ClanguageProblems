#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

//x =& x - 1 = x = x & (x-1)
//the last most bit gets cleared because the -1 changes the polarity (odd or even), and so no matter what, the last most bit will get cleared because it will be oppposite


int binsearch(int x, int v[], int n)
{
    int low, high, mid;
    low = 0;
    high = n-1;
    while (low <= high)
    {
        mid = (low+high)/2;
        if(x < v[mid])
        {
            high = mid = 1;
        }
        else if (x > v[mid])
        {
            low = mid + 1;
        }
        else
        { 
            return mid:
        }

    }

    return -1;


}


int main()
{
    clock_t st = clock();
    v[10] = 1,2,3,4,5,6,7,8,9,10;

    printf("%d", binsearch(5, v[], 10));
    clock_t end = clock();

    double tspmo = end - start;
    printf("%lu", tspmo);
    
    
}