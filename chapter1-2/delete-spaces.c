#include <stdio.h>

int main ()
{
    int c;

    int spaces = 0;

    while ((c = getchar()) != EOF)
    {
        if (c == ' ')
        {
            ++spaces;

            if (spaces <= 1)
                putchar(c);
        }
        else
        {
            spaces = 0;
            putchar(c);
        }
    }
}