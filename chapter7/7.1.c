#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int c;

8    if (argc > 1) {

        if (strcasecmp(argv[1], "upper") == 0)
        {
            while((c = getchar()) != 27)
            {
                putchar(toupper(c));
            }
        }
        else if (strcasecmp(argv[1], "lower") == 0)
        {
            while((c = getchar()) != 27)
            {
                putchar(tolower(c));
            }
        }
    }
    else
    {
        while((c = getchar()) != 27)
        {
            putchar(c);
        }
    }
}