#include <stdio.h>

#define IN  1
#define OUT 0

int main () 
{
    int c, state, nw;

    state = OUT;
    nw = 0;

    while ((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\n' || c == '\t')
            state = OUT;
        else if (state == OUT)
        {
            ++nw;
            state = IN;

            if (nw > 1)
                printf("\n");
        }

        putchar(c);
    }
}