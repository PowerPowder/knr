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

// strcat: copies t to the end of s - p48
void astrcat(char s[], char t[])
{
    int i, j;

    i = j = 0;
    while (s[i] != '\0')
        i++;
    while ((s[i++] = t[j++]) != '\0')
        ;
}

void pstrcat(char *s, char *t)
{
    while (*++s != '\0')
        ;

    while (*s++ = *t++)
        ;
}

// Write the function strend(s,t), which returns 1 if the string t occurs at the
// end of the string s, and zero otherwise.
int strend(char *s, char *t)
{
    // find same character in t which is in s
    // cycle through t to see if it is all in s
    // if the sequence of characters matched in both s and t
    // then return 1
    // othereise return 0

    // another way is to start at the end, and reverse t and see if it matches s

    int i = 0;

    while (*s++ != '\0')
        ;

    while (*t++ != '\0')
        i++;

    s--, t--;
    while (i-- >= 0)
        if (*s-- != *t--)
            return 0;

    return 1;
}

// strncpy, strncat, strncmp
void pstrncpy(char *s, char *t, int n)
{
    while (n-- > 0)
        *t++ = *s++;
}

void pstrncat(char *s, char *t, int n)
{
    s += n+1;

    while (*s++ = *t++)
        ;
}

int pstrncmp(char *s, char *t, int n)
{
    for (; *s == *t && n > 0; s++, t++, n--)
        if (*s == '\0')
            return 0;
    
    return *s - *t;
}

int main()
{
    char *s = "Hello there man";
    char *t = "Hello ";
    printf("%d", pstrncmp(s, t, 5));

    /*
    char s[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char *t = "hehehe";
    pstrncat(s, t, 5);
    printf("%s\n", s);
    */

    /*
    char *s = "Boi I am not hungry";
    char t[100];
    strncpy(s, t, 5);
    printf("%s", t);
    */

    /*
    char *s = "Hi, hello there, how do you do?";
    char *t = " do?";
    char *v = "ehrm";

    printf("%d", strend(s, t));
    */

    /*
    char s[100] = "hello there";
    char *t = ", my boi";

    pstrcat(s, t);
    printf("%s", s);
    */

    /*
    char *pmessage;
    pmessage = "now is the time";

    printf("%c", *(pmessage + 1));
    char s[100];
    char *t = "Hello there!";

    pstrcpy2(s, t);
    printf("%s\n%s\n", t, s);
    */
}