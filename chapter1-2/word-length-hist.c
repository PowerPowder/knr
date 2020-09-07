/*
    Write a program to print a histogram of the lengths of words in its input.
    It is easy to draw the histogram with the bars horizontal; a vertical 
    orientation is more challenging.
*/

#include <stdio.h>

int main ()
{
    int lengths[10];
    int c, wl = 0;

    int i;
    for (i = 0; i < 10; ++i)
        lengths[i] = 0;

    while ((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\t' || c == '\n' || c == ',')
        {
            ++lengths[wl - 1];
            wl = 0;
        }
        else
            ++wl;
    }

    printf("y-axis: frequency of word lengths\nx-axis: word lengths\n\n");

    for (i = 10; i > 0; --i)
    {
        printf("%6d\t|", i);

        int j;
        for (j = 0; j < 10; ++j)
        {
            if (lengths[j] >= i)
                printf(" # ");
            else
                printf("   ");
        }
        printf("\n");
    }

    printf("\t  ");

    for (i = 0; i < 10; ++i)
        printf("%d  ", i+1);

    printf("\n");
}