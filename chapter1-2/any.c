#include <stdio.h>

int any(char s1[], char s2[]);
int contains(char s[], int c);

int main()
{
    char s1[] = "BCAAAAADEAAAF";
    char s2[] = "A";

    printf("%d", any(s1, s2));
}

int any(char s1[], char s2[])
{
    int i, j, k;
    for (i = 0; s1[i] != '\0'; i++)
        for (j = 0; s2[j] != '\0'; j++)
            if (s1[i] == s2[j])
                return i;

    return -1;
}

int contains(char s[], int c)
{
    int i;
    for (i = 0; s[i] != '\0'; ++i)
        if (s[i] == c)
            return 1;

    return 0;
}
