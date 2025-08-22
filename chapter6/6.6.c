#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define HASHSIZE 101
#define MAXWORD 100
#define BUFSIZE 100

struct nlist {
    struct nlist *next;
    char *name;
    char *defn;
};

static struct nlist *hashtab[HASHSIZE];
char buf[BUFSIZE];
int bufp = 0;

unsigned hash(char *s) {
    unsigned hashval;
    for (hashval = 0; *s != '\0'; s++)
        hashval = *s + 31 * hashval;
    return hashval % HASHSIZE;
}

struct nlist *lookup(char *s) {
    struct nlist *np;
    for (np = hashtab[hash(s)]; np != NULL; np = np->next)
        if (strcmp(s, np->name) == 0)
            return np;
    return NULL;
}

struct nlist *install(char *name, char *defn) {
    struct nlist *np;
    unsigned hashval;
    if ((np = lookup(name)) == NULL) {
        np = (struct nlist *) malloc(sizeof(*np));
        if (np == NULL || (np->name = strdup(name)) == NULL)
            return NULL;
        hashval = hash(name);
        np->next = hashtab[hashval];
        hashtab[hashval] = np;
    } else {
        free(np->defn);
    }
    if ((np->defn = strdup(defn)) == NULL)
        return NULL;
    return np;
}

int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
    if (bufp < BUFSIZE)
        buf[bufp++] = c;
}

int getword(char *word, int lim) {
    int c;
    char *w = word;
    while (isspace(c = getch()))
        ;
    if (c != EOF)
        *w++ = c;
    if (!isalpha(c) && c != '_' && c != '#') {
        *w = '\0';
        return c;
    }
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

int main() {
    char word[MAXWORD];
    char name[MAXWORD];
    char defn[MAXWORD];
    struct nlist *np;
    while (getword(word, MAXWORD) != EOF) {
        if (strcmp(word, "#define") == 0) {
            getword(name, MAXWORD);
            getword(defn, MAXWORD);
            install(name, defn);
        } else if (isalpha(word[0])) {
            if ((np = lookup(word)) != NULL)
                printf("%s", np->defn);
            else
                printf("%s", word);
        } else {
            printf("%s", word);
        }
    }
    return 0;
}
