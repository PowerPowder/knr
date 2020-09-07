#include <stdio.h>
#define MAXLINE 1000

int getLine(char line[], int maxLine);

int main()
{
    int len;
    char line[MAXLINE];

    while ((len = getLine(line, MAXLINE)) > 0)
    {
        printf("%s", line);
    }

    return 0;
}

int getLine(char s[], int lim)
{
    int c, i;

    int spaces = 0;
    int newlines = 0;

    i = 0;
    while ((c = getchar()) != EOF && i < lim-1)
    {
        if (c != ' ')
            spaces = 0;
        else
            ++spaces;

        if (c != '\n')
            newlines = 0;
        else
            ++newlines;

        if (c != '\t' && spaces <= 1 && newlines <= 1)
        {
            s[i] = c;
            ++i;
        }
    }

    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';
    return i;
}