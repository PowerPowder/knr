#include <stdio.h>

// printd: print n in decimal
void printd(int n)
{
    if (n < 0)
    {
        putchar('-');
        n = -n;
    }

    if (n / 10)
        printd(n / 10);
    putchar(n % 10 + '0');
}

// qsort: sort v[left] ... v[right] into increasing order
void qsort(int v[], int left, int right)
{
    int i, last;

    if (left >= right)      // do nothing if array contains
        return;             // fewer than two elements

    swap(v, left, (left + right)/2);    // move partition element
    last = left;                        // to v[0]

    for (i = left+1; i <= right; i++)   // partition
        if (v[i] < v[left])
            swap(v, ++last, i);

    swap(v, left, last);        // restore partition element
    qsort(v, left, last-1);
    qsort(v, last+1, right);
}

// interchange v[i] and v[j]
void swap(int v[], int i, int j)
{
    int temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

int main(void)
{
    //int v[] = {3, 5, 2, 7, 6, 8, 11, 1, 13, 21, 18, 78, 66, 54};
    int arr[] = {3, 5, 1, 2, 4};
    int i;

    for (i = 0; i < 5; i++)
        printf("%d\n", arr[i]);

    printf("Now sorting:\n");
    qsort(arr, 0, 5);

    for (i = 0; i < 5; i++)
        printf("%d\n", arr[i]);
}