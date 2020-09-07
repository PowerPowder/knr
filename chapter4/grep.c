#include <stdio.h>

#define MAXLINE 1000    /* maximum input line length */

int getLine(char line[], int max);
int strIndex(char source[], char searchfor[]);
int strRIndex(char source[], char searchfor[]);

//char pattern[] = "ould";    /* pattern to search for */
char pattern[] = "aaZ";    /* pattern to search for */

/* find all lines matching pattern */
int main()
{
    char line[MAXLINE];
    int found = 0;

    int index = 0;
    while (getLine(line, MAXLINE) > 0)
        if ((index = strRIndex(line, pattern)) >= 0)
        {
            printf("%d\n%s", index, line);
            found++;
        }

    return found;
}

/* getline: get line into s, return length */
int getLine(char s[], int lim)
{
    int c, i;

    i = 0;
    while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
        s[i++] = c;

    if (c == '\n')
        s[i++] = c;

    s[i] = '\0';

    return i;
}

/* strindex: return index of t in s, -1 if none */
int strIndex(char s[], char t[])
{
    int i, j, k;

    for (i = 0; s[i] != '\0'; i++)
    {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;

        if (k > 0 && t[k] == '\0')
            return i;
    }

    return -1;
}

/* strRIndex: return index of the rightmost t in s, -1 if none */
int strRIndex(char s[], char t[])
{
    int result = -1;
    int i, j, k;

    for (i = 0; s[i] != '\0'; i++)
    {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;

        if (k > 0 && t[k] == '\0')
            result = i;
    }

    return result;
}