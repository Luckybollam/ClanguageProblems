#include <stdio.h>
#include <string.h>


int strend(char* s, char* t)
{
    int i  = strlen(t);
    int k = strlen(s);
    int j;
    int state = 0;

    for (j = 0; j < i; j++)
    {
        if (*(t+(i-j)) == s[k - j])
        {
            state++;
        }
    }
    if (state == i)
        {
            return 1;
        }
        else
        {
            return 0;
        }
}


int main()
{

    char s[25] = "HelloWorld";
    char *t = "World";

    printf("%d", strend(s, t));
    

}
