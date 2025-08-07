#include <stdio.h>
#include <string.h>


#include <stdio.h>
#include <string.h>



char* strcat2(char* s, char *t, int n)
{
    int i = strlen(s);
    char* l = s + i;
    int j = 0;
    while((*l++ = *t++) != '\0' && j != (n-1))
    {
        j++;
    }
    return s;

}

void strcpy1(char *s, char t[], int n)
{
    int j = 0;
    char *k = t; 

    while (j < n - 1 && *s != '\0') {
        *k++ = *s++;
        j++;
    }
    *k = '\0';  

    printf("%s\n", k);  
}

int strcmp1(char *s, char *t, int n)
{
    int i = 0;
    int j = strlen(s);
    int state = 0;
    for (; i < j; i++)
    {
        if (i == n)
        {
            break;
        }
        if (*s == *t)
        {
            state++;
        }
    }

    return (state == i) ? 0 : -1;
}



int main()
{
    char s[25] = "Hello";
    char *t = "World";
    char *l = "Hello";
    printf("%s\n", strcat2(s, t, 5));
    printf("%d\n", strcmp1(s, l, 5));
    
}
