#include <stdio.h>

int main () 
{
    int c;
    int space = 0, tab = 0, newline = 0;

    while ((c = getchar()) != EOF)
    {
        if (c == ' ')
            ++space;
        if (c == '\t')
            ++tab;
        if (c == '\n')
            ++newline;
    }

    //c = getchar();
    //printf("%d", c);

    printf("%d Spaces\n%d Tabs\n%d Newlines\n", space, tab, newline);

    // space is 32
    // tab is 9
    // newline is 10
}