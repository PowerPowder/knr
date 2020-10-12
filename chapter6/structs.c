#include <stdio.h>

int main()
{
    struct point
    {
        int x;
        int y;
    };

    struct point pt;
    pt.x = 3;
    pt.y = 4;

    struct rect
    {
        struct point p1;
        struct point p2;
    };

    struct rect screen;
    screen.p1 = pt;
    screen.p2.x = pt.x + 2;
    screen.p2.y = pt.y;

    printf("p1.x %d\n", screen.p1.x);
    printf("p1.y %d\n", screen.p1.y);
    printf("p2.x %d\n", screen.p2.x);
    printf("p2.y %d\n", screen.p2.y);
}