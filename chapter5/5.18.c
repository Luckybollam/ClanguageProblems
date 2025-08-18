#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXTOKEN1 100
#define BUFSIZE 5000

enum { NAME, PARENS, BRACKETS, QUALIFIER };

const char *qualifiers[]
{
    "const",
    "volatile",
    "restrict",
    "_Atomic",
    NULL
};

void(dcl(void));
void dirdcl(void);
void ungetch(int);
int getch(void);
int gettoken(void);
int tokentype;
char token[MAXTOKEN1];
char name[MAXTOKEN1];
char dataype[MAXTOKEN1];
char out[1000];



int isqualifier(const char *s)
{
    const char **q;
    for (q = qualifiers; *q != NULL; q++) {
        if (strcmp(s, *q) == 0)
            return 1;
    }
    return 0;
}


int main()
{
    int type;
    char temp1[MAXTOKEN1];

    while(gettoken() != EOF)
    {
        strcpy(out, token);
        while ((type = gettoken()) != '\n'){
            if (type == PARENS || type == BRACKETS){
                strcat(out, token);
            }
            else if (type == '*'){
                sprintf(temp1, "(*%s)", out);
                strcpy(out, temp1);
            }
            else {
                printf("invalid input as %s\n", token);
            }
        }
        printf("%s\n", out);
    }
    return 0;
}

void dcl(void)
{
    int ns;
    for (ns = 0; gettoken() == '*'; ){
        ns++;
    }
    dirdcl();
    while (ns-- > 0)
    {
        strcat(out, " pointer to");
    }
}

void dirdcl(void)
{
    int type;

    if (tokentype == '('){
        dcl();
        if (tokentype != ')')
        {
            printf("error: Missing )\n");
        }
        else if (tokentype == "(")
        {
            printf("error: Extra )\n");
        }
    }
    else if (tokentype == '[')
    {
        dcl();
        if (tokentype != ']')
        {
            printf("error: Missing )\n");
        }
    }
    else if (tokentype == NAME){
        strcpy(name, token);
    }
    else {
        printf("error: expectated name or (dcl)\n");
    }
    while ((type = gettoken()) == PARENS || type == BRACKETS)
    {
        if(type == PARENS){
            strcat(out, " function returning");
        }
        else {
            strcat(out, " array");
            strcat(out, token);
            strcat(out, " of");
        }
    }
}


int gettoken(void)
{
    int c, getch(void);
    char *p = token;
    while ((c = getch()) == ' '  || c == '\t')
    {
        ;
    }
    if (c == '('){
        if ((c = getch()) == ')')
        {
            strcpy(token, "()");
            return tokentype = PARENS;
        }
        else  {
            ungetch(c);
            return tokentype = '(';
        }
    }
    else if (c == '[')
    {
        for (*p++ = c; (*p++ = getch()) != ']';)
        {
            ;
        }
        *p = '\0';
        return tokentype = BRACKETS;
    }
    else if (isalpha(c)) {
        for (*p++ = c; isalnum(c = getch()) ;) {
            *p++ = c;
        }
        *p = '\0';
        ungetch(c);

        if (isqualifier(token))
        {
            return tokentype = QUALIFIER;
        }
        return tokentype = NAME;
    }
    else {
        return tokentype = c;
    }
}
     
char buf[BUFSIZE];       
int bufp = 0;            

void ungetch(int c) {
    if (bufp >= BUFSIZE) {
        printf("ungetch: too many characters\n");
    } else {
        buf[bufp++] = c;
    }
}

int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}