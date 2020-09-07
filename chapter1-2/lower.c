#include <stdio.h>

int lower(int c)
{
    /*
    if (c >= 'A' && c <= 'Z')
        return c + 'a' - 'A';
    else
        return c;
    */

    int result = (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c;
    return result;
}

int main()
{
    printf("%c", lower('D'));
}