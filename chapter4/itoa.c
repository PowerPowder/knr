#include <stdio.h>

// Adapt the ideas of printd to write a recursive version of itoa; that is,
// convert an integer into a string by calling a recursive routine.
void itoa(int n, char s[])
{
    if (n < 0)
    {
        putchar('-');
        n = -n;
    }

    if (n / 10)
        itoa(n / 10, s);
    putchar(n % 10 + '0');
}

/*
void itoa(int n, char s[])
{
    int i, sign;

    if ((sign = n) < 0)
        n = -n;
    
    i = 0;
    do {
        s[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);

    if (sign < 0)
        s[i++] = '-';
    
    s[i] = '\0';
}
*/

int main(void)
{
    char s[100];
    itoa(-189, s);
    //printf("%s", s);
}