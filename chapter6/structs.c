#include <stdio.h>

#define min(a, b) (a < b ? a : b)
#define max(a, b) (a > b ? a : b)

struct point
{
    int x;
    int y;
};

struct rect
{
    struct point p1;
    struct point p2;
};

// makepoint: make a point from x and y components
struct point makepoint(int x, int y)
{
    struct point temp;

    temp.x = x;
    temp.y = y;
    return temp;
}

// addpoint: add two points
struct point addpoint(struct point p1, struct point p2)
{
    p1.x += p2.x;
    p1.y += p2.y;
    return p1;
}

// ptinrect: return 1 if p in r, 0 if not
int ptinrect(struct point p, struct rect r)
{
    return p.x >= r.p1.x && p.x < r.p2.x
        && p.y >= r.p1.y && p.y < r.p2.y;
}

// canonrect: canonicalize coordinates of rectangle
struct rect canonrect(struct rect r)
{
    struct rect temp;

    temp.p1.x = min(r.p1.x, r.p2.x);
    temp.p1.x = min(r.p1.y, r.p2.y);
    temp.p2.x = max(r.p1.x, r.p2.x);
    temp.p2.x = max(r.p1.y, r.p2.y);

    return temp;
}

int main()
{
    struct point origin, *pp;
    pp = &origin;

    origin = makepoint(10, 5);
    printf("origin is (%d,%d)\n", pp->x, pp->y);

    /*
    struct rect screen;
    struct point middle;
    struct point makepoint(int, int);

    screen.p1 = makepoint(0, 0);
    screen.p2 = makepoint(20, 10);

    middle = makepoint((screen.p1.x + screen.p2.x) / 2,
                       (screen.p1.y + screen.p2.y) / 2);

    screen.p2 = addpoint(screen.p2, makepoint(100, 50));

    printf("(%d %d) is in rectangle: %d", middle.x, middle.y, ptinrect(makepoint(100, 1000), screen));
    */
}