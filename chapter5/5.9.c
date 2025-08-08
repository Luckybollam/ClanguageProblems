
#include <stdio.h>

//NOT COMPLETE YET

static char *name[13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
};

int day_of_year(int year, int month, int day)
{
    if(month > 12 || day > 31 || day < 0 || month < 0 || year < 0)
    {
        printf("invalid value\n");
        return -1;
    }
    int i, leap;
    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    for (i = 0; i < month; i++)
    {
        day+= daytab[leap][i];
    }
    return day;
}

void month_day(int year, int yearday, int *pmonth, int *pda)
{
    int i, leap;
    
    if(*pmonth > 12 || *pda > 31 || year < 0 || yearday < 0|| *pmonth < 0|| *pda < 0)
    {
        printf("invalid value\n");
        return;
    }
    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;

    for (i = 1; yearday > daytab[leap][i]; i++)
    {
        yearday -= daytab[leap][i];
    }
    *pmonth = i;
    *pda = yearday;
}

int main()
{
    int month, day, year;
    year = 2024;
    month = 13;
    day = 9;
    printf("%d\n", day_of_year(year, month, day));
}