#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXLINES 5000
char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines, int dec);

void qsort1(void *lineptr[], int left, int right, int (*comp)(void *, void *));

int numcmp(char *, char*);

int char_case;
int direc;
int width;
int left_bound[100];
int right_bound[100];
int bound_index = 0;
int bound_index1 = 0;

int wrapper_strcmp(void *a, void *b) {
    const char *s1 = *(const char **)a;
    const char *s2 = *(const char **)b;

    if (width == 1) {
        s1 = s1 + left_bound[bound_index1];
        s2 = s2 + left_bound[bound_index1];
    }

    while (*s1 != '\0' || *s2 != '\0') {
        char c1 = *s1;
        char c2 = *s2;

        if (direc) {
            while (*s1 && !isalnum(*s1) && *s1 != ' ') s1++;
            while (*s2 && !isalnum(*s2) && *s2 != ' ') s2++;
            c1 = *s1;
            c2 = *s2;
        }

        if (char_case) {
            c1 = tolower(c1);
            c2 = tolower(c2);
        }

        if (c1 != c2) {
            return c1 - c2;
        }

        if (*s1) s1++;
        if (*s2) s2++;
    }
    return 0;
}



int wrapper_numcmp(void *a, void *b) {
    char *s1 = *(char **)a;
    char *s2 = *(char **)b;
    if (width == 1)
    {
        s1 = s1 + left_bound[bound_index1];
        s2 = s2 + left_bound[bound_index1];
    }
    return numcmp(s1, s2);
}


int main(int argc, char* argv[])
{
    int nlines;
    int numeric = 0;
    int dec = 0;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-n") == 0)
        {
            numeric = 1;
        }
        else if (strcmp(argv[i], "-r") == 0)
        {
            dec = 1;
        }
        else if (strcmp(argv[i], "-f") == 0)
        {
            char_case = 1;
        }
        else if (strcmp(argv[i], "-d") == 0)
        {
            direc = 1;

        }
        else if (strcmp(argv[i], "-w") == 0)
        {
            width = 1;
            left_bound[bound_index] = atoi(argv[i+1]);
            right_bound[bound_index] = atoi(argv[i+2]);
            bound_index++;
            i += 2;  
        }
    }

    if ((nlines = readlines(lineptr, MAXLINES)) >= 0)
    {
        bound_index1 = 0;
        switch (numeric){
            case 1:
                qsort1((void **)lineptr, 0, nlines-1, wrapper_numcmp);
                break;
            default:
                qsort1((void **)lineptr, 0, nlines-1, wrapper_strcmp);
                break;
        }
        
        writelines(lineptr, nlines, dec);
        return 0;
    }
    else
    {
        printf("input too big to sort\n");
        return 1;
    }
}

int numcmp(char *s1, char*s2)
{
    
    double v1, v2;
    int i = 0;
    char temp1[1000], temp2[1000];

    if (width == 1) {
        int len = right_bound[bound_index1] - left_bound[bound_index1];
        strncpy(temp1, s1, len);
        temp1[len] = '\0';
        strncpy(temp2, s2, len);
        temp2[len] = '\0';
        v1 = atof(temp1);
        v2 = atof(temp2);
    }
    else
    {
        v1 = atof(s1);
        v2 = atof(s2);
    }
    if (v1 < v2) {
        return -1;
    }
    else if (v1 > v2) {
        return 1;
    }
    else {
        return 0;
    }
}

void swap(void *v[], int i, int j)
{
    void *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

void qsort1(void *v[], int left, int right, int (*comp)(void *, void *)) {
    int i, last;
    void swap(void *v[], int, int);

    if (left >= right){
        return;
    }
    swap(v, left, (left+right)/2);
    last = left;
    for (i = left+1; i <= right; i++){
        if ((*comp)(v[i], v[left]) < 0){
            swap(v, ++last, i);
        }
    }
    swap(v, left, last);
    qsort1(v, left, last-1, comp);
    qsort1(v, last+1, right, comp);
}

#define MAXLEN 1000

int getline1(char *s, int lim) {
    int c, i;
    for (i = 0; i < lim - 1 && (c = getchar()) != 27 && c != '\n'; i++)
        s[i] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}

char *alloc(int n);
#define ALLOCSIZE 10000
static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

char *alloc(int n) {
    if (allocbuf + ALLOCSIZE - allocp >= n) {
        allocp += n;
        return allocp - n;
    } else {
        return 0;
    }
}

int readlines(char *lineptr[], int maxlines) {
    int len, nlines = 0;
    char *p, line[MAXLEN];

    while ((len = getline1(line, MAXLEN)) > 0) {
        if (nlines >= maxlines || (p = alloc(len)) == NULL)
            return -1;
        line[len - 1] = '\0';  
        strcpy(p, line);
        lineptr[nlines++] = p;
    }
    return nlines;
}

void writelines(char *lineptr[], int nlines, int dec) {
    
    if (dec == 1)
    {
        for (int i = (nlines-1); i >= 0; i--){
            printf("%s\n", lineptr[i]);
        }
    }
    else
    {
        for (int i = 0; i < (nlines); i++){
            printf("%s\n", lineptr[i]);
        }
    }
    
}
