#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

//complete

int any(char s1[], char s2[])
{
    int i = 0;
    int j = 0;
    int loc = 0;
    

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 25; j++)
        {
            if (s1[i] == s2[j] && ((j < loc) || loc == 0))
            {
                loc = j;
                
            }
        }
    }

    if (loc == 0)
    {
        loc = -1;
    }
    return loc;


}


int main()
{
    
    char s[100] = "audioaudioaudioaudioaudio";
    char c[5] = "io";
    printf("%d", any(c,s));

}