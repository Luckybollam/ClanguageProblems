#include <stdio.h>
#include <stdarg.h>
#include <ctype.h>

void miniprintf(char *fmt, ...)
{
    va_list ap;
    char *p, *sval;
    int ival;
    double dval;

    va_start(ap, fmt);
    for (p = fmt; *p; p++) {
        if (*p != '%') {
            putchar(*p);
            continue;
        }

        p++;  

        int decimal = 6;

        if (*p == '.' && isdigit(*(p + 1))) {
            decimal = *(p + 1) - '0';  
            p += 2; 
        }

        switch (*p) {
            case 'd':
                ival = va_arg(ap, int);
                printf("%d", ival);
                break;
            case 'f': {
                dval = va_arg(ap, double);
                char format[10];
                sprintf(format, "%%.%df", decimal);
                printf(format, dval);
                break;
            }
            case 's':
                sval = va_arg(ap, char *);
                while (*sval)
                    putchar(*sval++);
                break;
            case 'c':
                ival = va_arg(ap, int);
                putchar(ival);
                break;
            case '%':
                putchar('%');
                break;
            default:
                putchar('%');
                putchar(*p);
                break;
        }
    }
    va_end(ap);
}

int main() {
    miniprintf("This is an integer: %d\n", 42);
    miniprintf("This is a float: %f\n", 3.1415);
    miniprintf("This is a string: %s\n", "Hello, world!");
    miniprintf("Mixing types: %s %d %f\n", "Number:", 7, 2.71828);
    miniprintf("Literal percent sign: %%\n");
    miniprintf("This is a character: %c\n", 'c');
    miniprintf("This is a float with limited decimal: %.2f\n", 3.14159);
    return 0;
}
