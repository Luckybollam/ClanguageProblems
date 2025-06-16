#include <stdio.h>

int fahrcels(int fahr)
{
    int celsius = 0;
    celsius = (5 * (fahr - 32.0))/9;
    return celsius;
}


int main()
{
    int fahr, celsius;
    int lower, upper, step;
    lower = 0;
    upper = 300;
    step = 20;
    fahr= lower;
    while(fahr <= upper)
    {
        celsius= (5.0/9.0) * (fahr- 32.0);
        printf("%d %d\n", fahr, fahrcels(fahr));
        fahr = fahr + step;

    }
}



