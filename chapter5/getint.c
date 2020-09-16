#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int getch(void);
void ungetch(int);

// getfloat: get next floating-point analog from input into *pf
float getfloat(float *pf)
{
    int c, sign;

    while (isspace(c = getch()))
        ;
    
    if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.')
    {
        ungetch(c);
        return 0;
    }

    sign = (c == '-') ? -1 : 1;

    if (c == '+' || c == '-')
        while (isspace(c = getch()) || c == '+' || c == '-')
            ;
    
    for (*pf = 0.0f; isdigit(c); c = getch())
        *pf = 10 * *pf + (c - '0');

    float frac;
    if (c == '.')
    {
        char s[40];
        int i;
        for (i = 1; i < 40 && isdigit(c = getch()); i++)
            s[i] = c;

        s[0] = '.';
        s[i] = '\0';

        frac = atof(s);
    }
    
    *pf += frac;
    
    *pf *= sign;

    if (c != EOF)
        ungetch(c);

    return c;
}

// getint: get next integer from input into *pn
int getint(int *pn)
{
    int c, sign;

    while (isspace(c = getch()))
        ;
    
    if (!isdigit(c) && c != EOF && c != '+' && c != '-')
    {
        ungetch(c);
        return 0;
    }

    sign = (c == '-') ? -1 : 1;

    if (c == '+' || c == '-')
        while (isspace(c = getch()) || c == '+' || c == '-')
            ;
    
    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');
    
    *pn *= sign;

    if (c != EOF)
        ungetch(c);

    return c;
}

int main()
{
    /*
    int n, array[100];
    for (n = 0; n < 100 && getint(&array[n]) != EOF; n++)
        ;
    */

    int n;
    float array[100];
    for (n = 0; n < 100 && getfloat(&array[n]) != EOF; n++)
        ;

    printf("\n");

    int i;
    for (i = 0; i < n; i++)
    {
        printf("%g", array[i]);

        if (i+1 < n)
            printf(", ");
    }

    printf("\n");

    return 0;
}