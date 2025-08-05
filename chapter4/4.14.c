#include <stdio.h>
#include <string.h>



#define swap(t,x,y) {t temp = x; x = y; y = temp}

int main()
{
    int x = 10;
    int y = 20;
    swap(int,x,y);
}
 