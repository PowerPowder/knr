#include <stdio.h>
#include <ctype.h>
#include "calc.h"

/*
    Modify getop so that it doesn't need to use ungetch. Hint:
    use an internal static variable.
*/

int getop(char s[])
{
    int i;
    static int c = ' ';

    while (c == ' ' || c == '\t')
        c = getchar();

    s[0] = c;
    s[1] = '\0';

    if (!isdigit(c) && c != '.')
    {
        int res = c;
        c = ' ';
        return res; /* not a number */
    }

    i = 0;

    if (isdigit(c)) /* collect integer part */
        while (isdigit(s[++i] = c = getch()))
            ;

    if (c == '.') /* collect fraction part */
        while (isdigit(s[++i] = c = getch()))
            ;

    s[i] = '\0';

    if (c != EOF)
        ungetch(c);

    return NUMBER;
}