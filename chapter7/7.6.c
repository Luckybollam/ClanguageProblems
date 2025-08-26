#include <stdio.h>
#include <string.h>


void filecmp(FILE *ifp, FILE *ofp)
{
    int maxline = 1000;
    char line1[maxline];
    char line2[maxline];
    int lineno = 0;
    while ((fgets(line1, maxline, ifp)) && (fgets(line2, maxline, ofp)))
    {
        
        if (strcmp(line1, line2) == 0)
        {
            ;
        }
        else
        {
            printf("Line %d are different:%s %s\n", lineno, line1, line2);
        }
        lineno++;
    }

    while (fgets(line1, maxline, ifp)) 
    {
        printf("Line %d extra in first file: %s", lineno++, line1);
    }

    while (fgets(line2, maxline, ofp)) 
    {
        printf("Line %d extra in second file: %s", lineno++, line2);
    }
    
}

int main(int argc, char * argv[])
{
    FILE *fp1;
    FILE *fp2;
    void filecmp(FILE*, FILE*);

    if (argc > 1) {
        if (--argc > 0) {
            if ((fp1 = fopen(*++argv, "r")) == NULL ||  (fp2 = fopen(*++argv, "r")) == NULL){
                printf("Cat: Can't open %s\n", *argv);
                return 1;
            }
            else {
                filecmp(fp1, fp2);
                fclose(fp1);
                fclose(fp2);
            }
        }
    }
    return 0;
}

