#include <stdio.h>
#include <limits.h>


//int is between -2147483648 and 2147483648, unsigned is 4294967295
//long is between -9223372036854775808127 and 9223372036854775808127, unsigned is 1.84467441e22
//char is between 127 and -128 and unsigned is 255
//float max is same as int
int main()
{
    float a;
    int b = 0;
    b = sizeof(a);
    printf("int max is: %d\n", INT_MAX);
    printf("int min is: %d\n", INT_MIN);
    printf("Unsigned int max is %u\n", UINT_MAX);
    printf("long max is %ld\n", LONG_MAX);
    printf("long min is %ld\n", LONG_MIN);
    printf("long unsigned max is %ld\n", ULONG_MAX);
    printf("char max is %d\n", CHAR_MAX);
    printf("char max is %d\n", CHAR_MIN);
    printf("unsigned char max is %d\n", UCHAR_MAX);
    printf("float max is:  %d\n", b);


}