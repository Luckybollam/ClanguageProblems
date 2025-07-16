#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>


void squeeze (char s[], char c[])
{
    int i = 0;
    int j = 0;
    

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 25; j++)
        {
            if (c[i] == s[j])
            {
                s[j] = '\0';
            }
        }
    }

    for (i = 0; i < 25; i++)
    {
        printf("%c", s[i]);
    }

   

   



}

int main()
{
    
    char s[25] = "audioaudioaudioaudio";
    char c[5] = "d";
    squeeze(s,c);

}