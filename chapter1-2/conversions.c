#include <stdio.h>

int atoi(char s[]);
long int htoi(char s[]);

int main()
{
    /*
        0-9: 48-57  |   s[i] - '0'
        A-F: 65-70  |   10 + (s[i] - 'A')
        a-f: 97-102 |   10 + (s[i] - 'a')

        A:65 B:66 C: 67 D: 68 E: 69 F: 70
        DEADBEEF = 1314101311141415
    */

    printf("%ld\n", htoi("0xDEADBEEF"));
}

int atoi(char s[])
{
    int i, n;

    n = 0;
    for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
        n = 10 * n + (s[i] - '0');

    return n;
}

long int htoi(char s[])
{
    int i;
    long int n;

    n = 0;

    for (i = 0; s[i] != '\0'; ++i)
    {
        if (s[i] == '0' || s[i] == 'X' || s[i] == 'x')
            continue;

        if (s[i] >= '0' && s[i] <= '9')
            n = 100 * n + (s[i] - '0');
        else if (s[i] >= 'A' && s[i] <= 'F')
            n = 100 * n + (s[i] - 'A' + 10);
        else if (s[i] >= 'a' && s[i] <= 'f')
            n = 100 * n + (s[i] - 'a' + 10);
    }

    return n;
}