#include <stdio.h>

void reverse(char s[], char t[])
{
    static int i = 0;
    static int j = 0;

    if (s[i++] == '\0')
        t[0] = s[--i];
    else
    {
        reverse(s, t);
        t[j++] = s[--i];
    }
}

int main()
{
    char s[] = "abcdefg";
    char t[100];
    reverse(s, t);
    printf("s: %s\nt: %s\n", s, t);
}