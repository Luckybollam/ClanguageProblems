#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>

#define MAXOP 100    
#define NUMBER '0'   
#define MAXVAL 100  
#define BUFSIZE 100

//4.3 - 4.10


int sp = 0;              
double val[MAXVAL];      
char buf[BUFSIZE];       
int bufp = 0;            

int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
    if (bufp >= BUFSIZE) {
        printf("ungetch: too many characters\n");
    } else {
        buf[bufp++] = c;
    }
}

int getop(char s[]) {
    int i = 0;
    int c;
    static int last_char = ' ';  

    while ((s[0] = c = last_char) == ' ' || c == '\t')
        last_char = getchar();

    s[1] = '\0';

    if (!isdigit(c) && c != '.') {
        last_char = getchar();  
        return c;
    }

    if (isdigit(c)) {
        while (isdigit(s[++i] = c = getchar()))
            ;
    }

    if (c == '.') {
        while (isdigit(s[++i] = c = getchar()))
            ;
    }

    s[i] = '\0';
    last_char = c;  
    return NUMBER;
}


void push(double f) {
    if (sp < MAXVAL) {
        val[sp++] = f;
    } else {
        printf("error: stack full, can't push %g\n", f);
    }
}

double pop(void) {
    if (sp > 0) {
        return val[--sp];
    } else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

int main() {
    int temp = 0;
    int type;
    double op2;
    char s[MAXOP];
    int temp1 = 0;
    int temp2 = 0;
    int i = 0;

    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0) {
                    push(pop() / op2);
                } else {
                    printf("error: divide by zero\n");
                }
                break;
            case '%':
                op2 = pop();
                push((int)pop() % (int)op2);
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            case 't':
                if (sp > 1)
                {
                    printf("Top: %f   Next: %f", val[sp-1], val[sp-2]);
                }
                else
                {
                    printf("error: not enough elements in stack");
                }
                break;
            case 's':
                if (sp > 1)
                {
                    val[sp-1] = val[sp-3];
                    val[sp-2] = val[sp-4];

                }
                break;
            case 'l':
                temp1 = val[sp-1];
                val[sp-1] = val[sp-2];
                val[sp-2] = temp1;
                break;
            case 'c':
                for (i = 0; i < sp; i++)
                {
                    val[i] = '\0';
                }
                break;
            case '^':
                op2 = pop();
                for (int i = 0; i < op2; i++)
                {
                    temp = temp + pop() * pop();
                }
            default:
                printf("error: unknown command %s\n", s);
                break;
        }

        int asdf = 0;
        if (asdf > 5)
        {
            break;
            asdf++;
        }
    }

    return 0;
}
