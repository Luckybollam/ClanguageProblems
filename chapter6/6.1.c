#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h> 

#define MAXWORD 100
#define NKEYS (sizeof keytab / sizeof keytab[0])

struct key {
    char *word;
    int count;
};

int getword(char *, int);
int binsearch(char *, struct key tab[], int);  
struct key keytab[] = {
    {"auto", 0},
    {"break", 0},
};



int main(){
    int n;
    char word[MAXWORD];

    while(getword(word, MAXWORD) != EOF){
        if (isalpha(word[0]))
        {
            if ((n = binsearch(word, keytab, NKEYS)) >= 0)
            {
                keytab[n].count++;
            }
        }
    }
    for (n = 0; n < NKEYS; n++)
    {
        if (keytab[n].count > 0)
        {
            printf("%4d %s\n", keytab[n].count, keytab[n].word);
        }
    }
    return 0;
}

int binsearch(char *word, struct key tab[], int n)
{
    int cond;
    int low, high, mid;

    low = 0;
    high = n-1;
    while (low <= high){
        mid = (low+high)/2;
        if ((cond = strcmp(word, tab[mid].word)) < 0) {
            high = mid - 1;
        }
        else if (cond > 0){
            low = mid + 1;
        }
        else {
            return mid;
        }
    }
    return -1;
}

int getword(char *word, int lim) {
    int c, getch(void);
    void ungetch(int);
    char *w = word;
    char quote;
    int prev = 0;


    while (isspace(c = getch()))
    {
        ;
    }
    if (c == '/'){
        if ((c = getch()) == '/') {
            while ((c = getch()) != '\n'){
                if (c == EOF) {
                    break;
            }
            }
            return getword(word, lim);
        }
        else if (c == '*') {
            while (true) {
            c = getch();
                if (c == EOF) {
                    break;
                }
                if (prev == '*' && c == '/') {
                    break;
                }
            prev = c;
            }
            return getword(word, lim);
        }
    }
    else if (c == '#') {
        while (1) {
            c = getch();
                if (c == EOF) {
                    break;
                }
                if (prev != '\\' && c == '\n') {
                    break;
                }
            prev = c;
        }
        return getword(word, lim);
    }
    else if (c == '\''   || c == '\"') {
        quote = c;
        while (true) {
            c = getch();
            if (c == EOF) {
                break;
            }
            if (c == '\\') {
                c = getch();
                ;
            }
            else if (c == quote) {
                break;
            }
            else {
                ;
            }
        }
        return getword(word, lim);
    }



    if (c == EOF) {
        return EOF;
    }
    if (!(isalpha(c)  || c == '_')) {
        *word++ = c;
        *word = '\0';
        return c;
    }

    for (; --lim > 0; w++) {
        c = getch();
        if (!(isalnum(c) || c == '_')) {
            ungetch(c);
            break;
        }
    *w++ = c;
    }

    *w = '\0';
    return word[0];
}

#define BUFSIZE 100

char buf[BUFSIZE];   // buffer for ungetch
int bufp = 0;         // next free position in buf

int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
