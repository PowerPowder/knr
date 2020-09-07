#include <stdio.h>
#define MAXLINE 1000

int getLine(char line[], int maxLine);
void reverse(char s[], int len);

int main()
{
    int len, max;
    char line[MAXLINE];

    while ((len = getLine(line, MAXLINE)) > 0)
    {
        reverse(line, len);
        //printf("%s", line);
    }

    return 0;
}

int getLine(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim-1 && (c = getchar()) != EOF && c !='\n'; ++i)
        s[i] = c;
    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';
    return i;
}

void reverse(char s[], int len)
{
    /*
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
    */

    int i = 0;
    for (i = 0; i < len-1; ++i)
        printf("%c", s[(len-2)-i]);
    printf("\n");
}