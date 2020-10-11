#include <stdio.h>

int add2to3(int (*funcptr)(int, int))
{
    return (*funcptr)(2, 3);
}

int addInt(int n, int m)
{
    return n + m;
}

int main()
{
    int (*funcptr)(int, int);
    funcptr = addInt;
    int sum = funcptr(2, 3);
    printf("%d", sum);
}