#include <stdio.h>

void swap(int *px, int *py)
{
    int temp;

    temp = *px;
    *px = *py;
    *py = temp;
}

int strlen(char *s)
{
    int n;

    for (n = 0; *s != '\0'; s++)
        n++;
    return n;
}

int main()
{
    /*
    int x = 5;
    int *pa = &x;

    printf("%p, %d\n", pa, *(pa+100));
    */

    //printf("%d\n", strlen("abcdefg"));
    //printf("%d\n", strlen("hello there"));

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

    /*
    int x, y;
    x = 5, y = 8;

    printf("%d %d\n", x, y);
    swap(&x, &y);
    printf("%d %d\n", x, y);
    */

    /*
    int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int *pa = &a[0];

    printf("%p\n%d\n", pa, *(a+1));
    */

    /*
    int x;
    x = *pa;

    int i;
    for (i = 0; i < 10; i++)
        printf("%p, %d\n", (pa+i), *(pa+i));
    */
}