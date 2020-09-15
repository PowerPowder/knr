#include <stdio.h>

#define swap(t, x, y) t = x, x = y, y = t

int main()
{
    int x = 5;
    int y = 4;
    int t;

    printf("%g %g\n", x, y);
    swap(t, x, y);
    printf("%g %g\n", x, y);
}