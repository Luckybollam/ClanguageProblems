#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASHSIZE 101

struct nlist {               
    struct nlist *next;      
    char *name;              
    char *defn;              
};

static struct nlist *hashtab[HASHSIZE]; 

unsigned hash(char *s) {
    unsigned hashval;
    for (hashval = 0; *s != '\0'; s++) {
        hashval = *s + 31 * hashval;
    }
    return hashval % HASHSIZE;
}

struct nlist *lookup(char *s) {
    struct nlist *np;
    for (np = hashtab[hash(s)]; np != NULL; np = np->next) {
        if (strcmp(s, np->name) == 0)
            return np; 
    }
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

int undef(char *name) {
    unsigned hashval = hash(name);
    struct nlist *np = hashtab[hashval];
    struct nlist *prev = NULL;

    while (np != NULL) {
        if (strcmp(name, np->name) == 0) {
            if (prev == NULL) {
                hashtab[hashval] = np->next; 
            } else {
                prev->next = np->next; 
            }
            free(np->name);
            free(np->defn);
            free(np);
            return 1;
        }
        prev = np;
        np = np->next;
    }
    return 0;
}

void print_table() {
    printf("Current symbol table:\n");
    for (int i = 0; i < HASHSIZE; i++) {
        for (struct nlist *np = hashtab[i]; np != NULL; np = np->next) {
            printf("  %s = %s\n", np->name, np->defn);
        }
    }
    printf("\n");
}

int main() {
    install("x", "100");
    install("y", "200");
    install("z", "300");

    print_table();

    printf("Undefining 'y'...\n");
    undef("y");

    print_table();

    printf("Looking up 'x':\n");
    struct nlist *np = lookup("x");
    if (np != NULL)
        printf("Found: %s = %s\n", np->name, np->defn);
    else
        printf("'x' not found.\n");

    return 0;
}
