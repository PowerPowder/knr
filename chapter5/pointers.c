#include <stdio.h>

void swap(int *px, int *py)
{
    int temp;

    temp = *px;
    *px = *py;
    *py = temp;
}

int main()
{
    /*j
    int x = 1, y = 2, z[10];
    int *ip;            // ip is a pointer to int
    int *iq;

    ip = &x;            // ip now points to x
    y = *ip;            // y is now 1
    *ip = 0;            // x is now 0
    //ip = &z[0];         // ip now points to z[0]

    iq = ip;
    printf("%d %d", *ip, *iq);
    */

    int x, y;
    x = 5, y = 8;

    printf("%d %d\n", x, y);
    swap(&x, &y);
    printf("%d %d\n", x, y);
}