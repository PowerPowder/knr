#include <stdio.h>

unsigned getbits(unsigned x, int p, int n)
{
    return (x >> (p+1-n) & ~(~0 << n));
}

/*  Write a function setbits(x,p,n,y) that returns x with 
    the n bits that begin at position p set to the 
    rightmost n bits of y, leaving the other bits unchanged. */
unsigned setbits(unsigned x, int p, int n, int y)
{
    //(p+1-n)
    return ;
}

/*
    Write a function invert(x,p,n) that returns x with the n
    bits that begin at position p inverted (ie. 1 changed 
    into 0 and vice versa), leaving the others unchanged.
*/
unsigned invert(unsigned x, int p, int n)
{

}

/*
    Write a function rightrot(x,n) that returns the value of
    the integer x rotated to the right by n bit positions.
*/
unsigned rightrot(unsigned x, int n)
{

}

int bitcount(unsigned x)
{
    int b;

    for (b = 0; x != 0; x >>= 1)
        if (x & 01)
            b++;
    return b;
}

int main()
{
    unsigned i = 19;
    printf("%d", bitcount(i));
    //unsigned i = 96;
    //printf("%d", getbits(i, 6, 4));
}

/*
    (x & ((~0 << (p+1)) | (~(~0 << (p+1-n)))))

    x = 29638, y = 999, p = 10, n = 8

    (29638 & ((~0 << (10+1)) | (~(~0 << (10+1-8)))))
    (29638 & ((~0 << 11) | (~(~0 << 3))))

    x = 29638
    32768 | 16384 | 8192 | 4096 | 2048 | 1024 | 512 | 256       128 | 64 | 32 | 16 | 8 | 4 | 2 | 1
      0       1       1      1     0       0     1     1         1     1    0   0    0   1   1   0
    x = 01110011 11000110

    ~0 = 11111111

    (01110011 11000110 & ((11111111 11111111 << 11) | (~(11111111 11111111 << 3))))

    (01110011 11000110 & (11111000 00000000 | (~11111111 11111000)))
     
    (01110011 11000110 & (11111000 00000000 | 00000000 00000111))

    (01110011 11000110 & 11111000 00000111)

    ( 01110011 11000110 
    & 11111000 00000111)
      01110000 00000110

    01110000 00000110 = ? = 28678

    32768 | 16384 | 8192 | 4096 | 2048 | 1024 | 512 | 256       128 | 64 | 32 | 16 | 8 | 4 | 2 | 1
      0       1      1       1      0      0      0    0         0    0    0    0    0   1   1   0
*/