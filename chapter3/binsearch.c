#include <stdio.h>

int binsearch(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;

    int i = 0;
    while (low <= high)
    {
        printf("iteration: %d\n", ++i);

        mid = (low+high) / 2;
        if (x < v[mid])
            high = mid - 1;
        else if (x > v[mid])
            low = mid + 1;
        else
            return mid;
    }

    return -1;
}

int main()
{
    int primes[] = {1, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 39};

    int i = binsearch(38, primes, 14);
    printf("%d is at index %d\n", primes[i], i);
    //printf("%d", primes[10000]);
}