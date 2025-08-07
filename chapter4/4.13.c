#include <stdio.h>
#include <string.h>

void reverser(char s[], int left, int right)
{
    if (left >= right)
    {
        return;
    }
    char temp;
    temp = s[left];    
    s[left] = s[right];
    s[right] = temp;

    reverser(s, left + 1, right - 1);
}

int main()
{
    char s[6] = {'h', 'e', 'l', 'l', 'o', '\0'}; 

    int len = strlen(s);
    reverser(s, 0, len - 1); 
    printf("Reversed string: %s\n", s);
    return 0;
}
