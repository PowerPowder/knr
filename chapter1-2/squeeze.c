#include <stdio.h>

void squeeze(char s[], char c[]);
int contains(char s[], int c);

int main()
{
    //char s1[100], s2[100];
    char s1[] = "BAD";
    char s2[] = "ABC";

    squeeze(s1, s2);

    int i;
    for (i = 0; s1[i] != '\0'; ++i)
        printf("%c", s1[i]);
}

//void squeeze(char s[], int c)
void squeeze(char s1[], char s2[])
{
    int i, j;

    /*
    for (i = j = 0; s[i] != '\0'; i++)
    {
        if (s[i] != c)
            s[j++] = s[i];
    }
    */

    for (i = j = 0; s1[i] != '\0'; i++)
    {
        int h;
        for (h = 0; s2[h] != '\0'; h++)
        {
            if (!contains(s1, s2[h]))
            {
                printf("%c", s2[h]);
                s1[j++] = s1[i];
                break;
            }
        }
    }

    s1[j] = '\0';
}

int contains(char s[], int c)
{
    int i;
    for (i = 0; s[i] != '\0'; ++i)
        if (s[i] == c)
            return 1;

    return 0;
}