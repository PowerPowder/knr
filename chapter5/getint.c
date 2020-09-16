#include <stdio.h>
#include <ctype.h>

int getch(void);
void ungetch(int);

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
    int n, array[100];
    for (n = 0; n < 100 && getint(&array[n]) != EOF; n++)
        ;

    printf("\n");

    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d", array[i]);

        if (i+1 < n)
            printf(", ");
    }

    printf("\n");

    return 0;
}