#include <stdio.h>

char noleap[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
char leap[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

static char *daytab[2] = {
    noleap, leap
};

// day_of_year: set day of year from month & day
int day_of_year(int year, int month, int day)
{
    int i, leap;

    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;

    if ((month > 12) || (day > *(*(daytab+leap)+month)))
        return 0;

    for (i = 1; i < month; i++)
        day += *(*(daytab+leap)+i);

    return day;
}

// month_day: set month, day from day of year
void month_day(int year, int yearday, int *pmonth, int *pday)
{
    int i, leap;

    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;

    if ((yearday > 365 && !leap) || (yearday > 366 && leap))
        return;

    for (i = 1; yearday > *(*(daytab+leap)+i); i++)
        yearday -= *(*(daytab+leap)+i);

    *pmonth = i;
    *pday = yearday;
}

int main()
{
    int month, day;
    month = day = 1;
    month_day(1989, 365, &month, &day);
    printf("%d %d\n", month, day);
    printf("day of year is: %d\n", day_of_year(2020, 2, 29));

    //printf("%d\n", *(*(daytab+1)+3));

    //printf("%p\n%p", daytab2, daytab2 + 2);

    /*
    int test[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int test2[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int *testiboi[2] = {
        test, test2
    };
    */

    //printf("%d", *(testiboi[0]+2));
    //printf("%d", testiboi[0][2]);
}