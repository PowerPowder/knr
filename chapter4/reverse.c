#include <stdio.h>

void reverse(char s[])
{
    static int i = 0;

    if (s[i++] == '\0')
        putchar(s[--i]);
    else
    {
        reverse(s);
        putchar(s[--i]);
    }
}

int main()
{
    char s[] = "abcdefg";
    reverse(s);
}