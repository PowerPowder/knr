#include <stdio.h>
#include <ctype.h>
#include <string.h>

/*
    Rewrite appropriate programs from earlier chapters and exercises with
    pointers instead of array indexing. Good possiblilities include getline,
    atoi, itoa, reverse, strindex, getop.
*/

int agetline(char s[], int lim)
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

int pgetline(char *s, int lim)
{
    int c, i;

    for (i = 0; --lim > 0 && (c=getchar()) != EOF && c != '\n'; i++)
        *s++ = c;
    if (c == '\n')
    {
        *s++ = c;
        i++;
    }

    *s = '\0';
    return i;
}

int aatoi(char s[])
{
    int i, n, sign;

    for (i = 0; isspace(s[i]); i++)
        ;

    sign = (s[i] == '-') ? -1 : 1;

    if (s[i] == '+' || s[i] == '-')
        i++;

    for (n = 0; isdigit(s[i]); i++)
        n = 10 * n + (s[i] - '0');

    return sign * n;
}

int patoi(char *s)
{
    int n, sign;

    while (isspace(*s))
        s++;

    sign = (*s == '-') ? -1 : 1;

    if (*s == '+' || *s == '-')
        s++;

    for (n = 0; isdigit(*s); s++)
        n = 10 * n + (*s - '0');

    return sign * n;
}

void areverse(char s[])
{
    int c, i, j;

    for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

void preverse(char *s)
{
    char *start = s;
    char *end = s;

    while (*end != '\0')
        end++;
    end--;

    int len = strlen(s) / 2;

    int i;
    for (i = 0; i < len; i++, start++, end--)
    {
        char tmp = *start;
        *start = *end;
        *end = tmp;
    }
}

void aitoa(int n, char s[])
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
    preverse(s);
}

void pitoa(int n, char *s)
{
    int i, sign;

    if ((sign = n) < 0)
        n = -n;

    do {
        *s++ = n % 10 + '0';
        i++;
    } while ((n /= 10) > 0);

    if (sign < 0)
    {
        *s++ = '-';
        i++;
    }

    *s = '\0';

    preverse(s - i);
}

int astrindex(char s[], char t[])
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

int pstrindex(char *s, char *t)
{
    int i, k;
    for (i = 0; *s != '\0'; s++, i++)
    {
        for (k = 0; *(t+k) != '\0' && *(s+k) == *(t+k); k++)
            ;
        if (k > 0 && *(t+k) == '\0')
            return i;
    }
    return -1;
}

int main()
{
    char s[] = "hello there";
    char t[] = "there";
    
    printf("%d", pstrindex(s, t));

    /*
    char s[100];
    pitoa(100, s);
    printf("%s", s);
    */

    /*
    char s[1000];
    int i;
    while(i = pgetline(s, 1000))
    {
        printf("i is %d\n", i);
        printf("%s\n", s);
    }
    */
}