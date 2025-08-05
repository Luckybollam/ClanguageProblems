#include <stdio.h>
#include <string.h>

void reverse(char s[], int left, int right)
{
    if (left >= right)
        return;

    char temp = s[left];
    s[left] = s[right];
    s[right] = temp;

    reverse(s, left + 1, right - 1);
}

int main()
{
    char s[6] = {'h', 'e', 'l', 'l', 'o', '\0'}; 

    int len = strlen(s);
    reverse(s, 0, len - 1); 

    printf("Reversed string: %s\n", s);

    return 0;
}
