
#include <stdio.h>


static int nonleap[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
static int leap[]    = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
static int *daytab[] = {nonleap, leap};

int day_of_year(int year, int month, int day)
{
    if(month > 12 || day > 31 || day < 0 || month < 0 || year < 0)
    {
        printf("invalid value\n");
        return -1;
    }
    int i, leap;
    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    int *p = *(daytab + leap);
    for (i = 1; i < month; i++) {
        day += *(p + i);
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

   int *p = *(daytab + leap);
    for (i = 1; yearday  > *(p+i); i++) {
        yearday -= *(p + i);
    }

    *pmonth = i;
    *pda = yearday;
}

int main()
{
    int month, day, year;
    year = 2024;
    month = 11;
    day = 9;
    printf("%d\n", day_of_year(year, month, day));
}