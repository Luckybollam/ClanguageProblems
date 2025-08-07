#include <stdio.h>
#include <string.h>



char* strcat2(char* s, char *t)
{
    int i = strlen(s);
    char* l = s + i;
    while((*l++ = *t++) != '\0')
    {
        ;
    }
    return s;

}


int main()
{

    char s[25] = "Hello";
    char *t = "World";
    printf("%s", strcat2(s, t));
    

}
