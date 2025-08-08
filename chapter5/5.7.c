#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAXLINES 5000   
#define MAXLEN 1000     

char *lineptr[MAXLINES]; 

int readlines(char *lineptr[], int maxlines, char *linestor);
void writelines(char *lineptr[], int nlines);
void qsort_lines(char *v[], int left, int right);
int get_line(char *line, int maxlen);

#define MAXSTORAGE 5000 * 1000  
char linestor[MAXSTORAGE];     

int main() {
    int nlines;

    if ((nlines = readlines(lineptr, MAXLINES, linestor)) >= 0) {
        qsort_lines(lineptr, 0, nlines - 1);
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("error: input too big to sort\n");
        return 1;
    }
}


int readlines(char *lineptr[], int maxlines, char *linestor) {
    int len, nlines = 0;
    char line[MAXLEN];
    char *p = linestor;
    char *end = linestor + MAXSTORAGE;

    while ((len = get_line(line, MAXLEN)) > 0) {
        if (nlines >= maxlines || p + len >= end) {
            return -1;
        } else {
            line[len - 1] = '\0'; 
            strcpy(p, line);
            lineptr[nlines++] = p;
            p += len;
        }
    }
    return nlines;
}


void writelines(char *lineptr[], int nlines) {
    for (int i = 0; i < nlines; i++) {
        printf("%s\n", lineptr[i]);
    }
}

int get_line(char *s, int maxlen) {
    int c, i = 0;
    while (--maxlen > 0 && (c = getchar()) != EOF && c != '\n') {
        s[i++] = c;
    }
    if (c == '\n') {
        s[i++] = c;
    }
    s[i] = '\0';
    return i;
}

void swap(char *v[], int i, int j) {
    char *temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

void qsort_lines(char *v[], int left, int right) {
    if (left >= right)
        return;

    swap(v, left, (left + right) / 2);
    int last = left;

    for (int i = left + 1; i <= right; i++) {
        if (strcmp(v[i], v[left]) < 0) {
            swap(v, ++last, i);
        }
    }

    swap(v, left, last);
    qsort_lines(v, left, last - 1);
    qsort_lines(v, last + 1, right);
}
