#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void head(int n)
{
    // get new line
    // put it as last element
    // move each element up the array by swapping with the previous
    // do until EOF

    char lines[n][100];
    char s[1000];
    int i = 0, j = 0;

    int c;
    while ((c = getchar()) != EOF)
    {
        s[i++] = c;

        if (c == '\n')
        {
            s[i] = '\0';
            i = 0;

            if (j >= n)
            {
                int k;
                for (k = 0; k < n; k++)
                    strcpy(lines[k], lines[k+1]);

                strcpy(lines[k-1], s);
            }
            else
                strcpy(lines[j++], s);
        }
    }

    printf("\n");

    for (i = 0; i < n && i < j; i++)
        printf("%s", lines[i]);
}

int main(int argc, char *argv[])
{
    if (argc > 1)
        head(atoi(argv[1]));
    else
    head(10);
}