#include <stdio.h>
#include <stdarg.h>
#include <ctype.h>



int miniscanf(char *fmt, ...)
{
    va_list ap;
    char *p, *sval;
    int ival;
    double dval;
    char c;
    int d;
    float f;
    int num = 0;
    int i = 0;


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
            case 'd':{
                int *ip = va_arg(ap, int *);
                int val = 0;
                int c;

                do {
                    c = getchar();
                } while (isspace(c));

                int negative = 0;
                if (c == '-') {
                    negative = 1;
                    c = getchar();
                }

                while (isdigit(c)) {
                    val = val * 10 + (c - '0');
                    c = getchar();
                }

                if (c != EOF) {
                    ungetc(c, stdin);
                }

                if (negative) val = -val;

                *ip = val;
                break;
            }
            case 'f': {
                    double *ip = va_arg(ap, double *);
                    float val = 0;
                    int c;

                    do {
                        c = getchar();
                    } while (isspace(c));

                    int negative = 0;
                    if (c == '-') {
                        negative = 1;
                        c = getchar();
                    }

                    while (isdigit(c)) {
                        val = val * 10 + (c - '0');
                        c = getchar();
                    }
                    if (c == '.') {
                        double frac = 0.0, base = 0.1;
                        c = getchar();
                        while (isdigit(c))
                        {
                            frac += (c - '0') * base;
                            base *= 0.1;
                            c = getchar();
                        }
                        val += frac;
                    }

                    if (c != EOF) {
                        ungetc(c, stdin);
                    }

                    if (negative) val = -val;

                    *ip = val;
                    break;
            }
            case 's': {
                char *ip = va_arg(ap, char *);
                do {
                        c = getchar();
                    } while (isspace(c));

                while(c != EOF && !(isspace(c)))
                {
                    ip[i++] = c;
                    c = getchar();
                    if (i >= 49)
                    {
                        break;
                    }
                }
                ip[i] = '\0';

                if (c != EOF && isspace(c)) {
                    ungetc(c, stdin);
                }
                break;
            }
            case 'c':
                break;
            default:
                break;
        }
        num++;
    }
    va_end(ap);
    return num;
}

int main()
{
    char word[100];  
    int i;
    double d;

    miniscanf("What is her name?%s What is her age?%d What is her GPA?%f", word, &i, &d);

    printf("Name: %s\nAge: %d\nGPA: %.2f\n", word, i, d);
    return 0;
}
