#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXWORD 100

#define BUFSIZE 100
char buf[BUFSIZE];
int bufp = 0;
int count;
int var = 0;

char *types[] = {"int", "float", "char", "double", "long", "short", "unsigned", "signed", "void", "struct"};
int ntypes = sizeof(types) / sizeof(types[0]);



struct tnode {
    char *word;
    int count;
    struct tnode *left;
    struct tnode *right;
};

int getword(char *, int);
int getch(void);
void ungetch(int);
struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);
struct tnode *talloc(void);
char *strdup1(char *);
int is_type(char *);

int getword(char *word, int lim) {
    int c;
    char *w = word;
    char quote;
    int prev = 0;

    while (isspace(c = getch())) ;

    if (c == '/') {
        if ((c = getch()) == '/') {
            while ((c = getch()) != '\n' && c != EOF);
            return getword(word, lim);
        } else if (c == '*') {
            while (1) {
                c = getch();
                if (c == EOF) break;
                if (prev == '*' && c == '/') break;
                prev = c;
            }
            return getword(word, lim);
        } else {
            ungetch(c);
            c = '/';
        }
    } else if (c == '#') {
        while (1) {
            c = getch();
            if (c == EOF) break;
            if (prev != '\\' && c == '\n') break;
            prev = c;
        }
        return getword(word, lim);
    } else if (c == '\'' || c == '\"') {
        quote = c;
        while (true) {
            c = getch();
            if (c == EOF) break;
            if (c == '\\') {
                c = getch();
            } else if (c == quote) {
                break;
            }
        }
        return getword(word, lim);
    }

    if (c == EOF) return EOF;

    if (!isalpha(c) && c != '_') {
        *w++ = c;
        *w = '\0';
        return c;
    }

    *w++ = c;
    for (; --lim > 0; w++) {
        c = getch();
        if (!isalnum(c) && c != '_') {
            ungetch(c);
            break;
        }
        *w = c;
    }
    *w = '\0';
    return word[0];
}

int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetch(int c) {
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

struct tnode *talloc(void) {
    return (struct tnode *) malloc(sizeof(struct tnode));
}
char *strdup1(char *s) {
    char *p = (char *) malloc(strlen(s) + 1);
    if (p != NULL)
        strcpy(p, s);
    return p;
}

struct tnode *addtree(struct tnode *p, char *w) {
    int cond;

    if (p == NULL) {
        p = talloc();
        p->word = strdup1(w);
        p->count = 1;
        p->left = p->right = NULL;
    } else if ((cond = strcmp(w, p->word)) == 0) {
        p->count++;
    } else if (cond < 0) {
        p->left = addtree(p->left, w);
    } else {
        p->right = addtree(p->right, w);
    }
    return p;
}

void treeprint(struct tnode *p) {
    if (p != NULL) {
        treeprint(p->left);
        printf("%4d %s\n", p->count, p->word);
        treeprint(p->right);
    }
}

int is_type(char *word) {
    for (int i = 0; i < ntypes; i++) {
        if (strcmp(word, types[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int main(int argc, char* argv[]) {
    count = atoi(argv[1]);
    struct tnode *root = NULL;
    char word[MAXWORD];
    char temp[20];
    int i;
    int first = 1;
    int six = 0;

    while (getword(word, MAXWORD) != EOF) {
        
        if (first == 1 && var == 1) {
            strcpy(temp, word);
            first++;
            var = 0;
        }
        else if (var == 1) {
            var = 0;
            six = 0;
            for (i = 0; i < count; i++) {
                if(temp[i] == word[i]) {
                    six++;
                }
            }
            if (six == count) {
                root = addtree(root, word);
            }
        }
        if (is_type(word)) {
            var = 1;
        }
    }

    treeprint(root);
    return 0;
}
