#include <stdio.h>

// astrcpy: copy t to s; array subscript version
void astrcpy(char *s, char *t)
{
    int i;

    i = 0;
    while ((s[i] = t[i]) != '\0')
        i++;
}

// pstrcpy1: copy t to s; pointer version 1
void pstrcpy1(char *s, char *t)
{
    while ((*s = *t) != '\0')
    {
        s++;
        t++;
    }
}

// pstrcpy2: copy t to s; pointer version 2
void pstrcpy2(char *s, char *t)
{
    while ((*s++ = *t++) != '\0')
        ;
}

// pstrcpy3: copy t to s; pointer version 3
void pstrcpy3(char *s, char *t)
{
    while (*s++ = *t++)
        ;
}

// strcmp: return <0 if s<t, 0 if s==t, >0 if s>t
int strcmp(char *s, char *t)
{
    int i;

    for (i = 0; s[i] == t[i]; i++)
        if (s[i] == '\0')
            return 0;

    return s[i] - t[i];
}

// strcmp: return <0 if s<t, 0 if s==t, >0 if s>t
int pstrcmp(char *s, char *t)
{
    for (; *s == *t; s++, t++)
        if (*s == '\0')
            return 0;
    
    return *s - *t;
}

int main()
{
    /*
    char *pmessage;
    pmessage = "now is the time";

    printf("%c", *(pmessage + 1));
    */
    char s[100];
    char *t = "Hello there!";

    pstrcpy2(s, t);
    printf("%s\n%s\n", t, s);
}