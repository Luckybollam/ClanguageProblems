#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

void escape(char s[], char t[]) {
    int i = 0;  
    int j = 0; 

    while (t[i] != '\0') {
        switch (t[i]) {
            case '\n':
                printf("I see a newline at %d\n", i);
                s[j++] = '\\';
                s[j++] = 'n';
                break;
            case '\t':
                printf("I see a tab at %d\n", i);
                s[j++] = '\\';
                s[j++] = 't';
                break;
            default:
                s[j++] = t[i];
                break;
        }
        i++;
    }

    s[j] = '\0';

    
    printf("%s\n", s);
}


int main()
{
    char arr[20] = {'h','i','\n','m','y','n','a','m','e','i','s','\t','\0'};
    char arr2[20];

    escape(arr2,arr);

}