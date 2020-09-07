#include <stdio.h>

unsigned getbits(unsigned x, int p, int n);

// getbits
// returns the n-bit field of x that begins at position p

// same as getbits, but sets those bits to the ones in y
// for the bits in y, it is the rightmost n bits

// get a range of bits in x, and change them to what the range of bits are in y

// p+1 >= n
// (x >> (p+1-n) & ~(~0 << n))

// x = 5, p = 4, n = 3, y = 10
// 5 =  00000101 <- getting XXX001XX
// 10 = 00001010 <- getting XXX010XX

// x = 00000101 -> 00001001 -> 9
// answer is obtained by swapping 000XXX01 with 000XXX10

// -----------------------------------------------------
// 'OR' the non-important bits, 'AND' the important bits
// -----------------------------------------------------

/*
    Write a function setbits(x,p,n,y) that returns x with the n bits that begin
    at position p set to the rightmost n bits of y, leaving the other bits 
    unchanged.
*/
unsigned setbits(unsigned x, int p, int n, unsigned y)
{
    unsigned char field = ~0;
    field = field >> (8-n);
    field = field << (p+1-n);
    return (x & ~field) | (y & field);
}

/*
    9, 5, 4, 23
    ~0 = 11111111   <- 00001111  <- 00111100

    5, 4, 3, 10
    ~0 = 11111111   <- 00000111  <- 00011100

    5, 4, 2, 10
    ~0 = 11111111   <- 00000011  <- 00011000

    ~0 >> 8-n
*/

// shift getbits back
// OR the bits back

/*
    Get the bits we need for both x and y
    Replace x's bit-field with getbits using y
*/

/*
    Write a function invert(x,p,n) that returns x with the n bits that begin at
    position p inverted. (i.e., 1 changed into 0 and vice versa), leaving the
    others unchanged.
*/
unsigned invert(unsigned x, int p, int n)
{
    unsigned char field = ~0;
    field = field >> (8-n);
    field = field << (p+1-n);

    return (~x & field) | (5 & ~field);
}

/*
    Write a function rightrot(x,n) that returns the value of the integer x
    rotated to the right by n bit positions.
*/
unsigned rightrot(unsigned x, int n)
{
    int i;
    unsigned char mask, end;

    mask = x;
    end = 0;
    for (i = 0; i < n; i++)
    {
        end = mask & 1;
        end = end << 7;
        mask = mask >> 1;
        mask = mask | end;
    }
    return mask;
}

// getbits: get n bits from position p
unsigned getbits(unsigned x, int p, int n)
{
    return (x >> (p+1-n) & ~(~0 << n));
}

int main()
{
    //printf("%hhu\n", invert(5, 4, 3));
    printf("%hhu", rightrot(63u, 4));
    /*
        printf("%d\t%hhu\n", 13, setbits(9, 5, 4, 23));
        printf("%d\t%hhu\n", 9, setbits(5, 4, 3, 10));
        printf("%d\t%hhu\n", 21, setbits(5, 4, 2, 10));
    */
}

/*
    p+1 >= n

    x = 147, p = 3, n = 3
    147 = 10010011

    10010011 >> 1 = 01001001

    11111111 << 3 = ~11111000

    01001001 &
    00000111
    00000001
*/

/*
    x = 11, p = 3, n = 2
    11 = 00001011

    00001011 >> 2 = 00000010
    11111111 << 2 = 11111100
    ~11111100 = 00000011

    00000011
    00000010
    00000010
*/

/*
    x = 5, p = 5, n = 4
    5 = 00000101
//        XXX

    00000101 >> 5+1-4
    00000101 >> 6-4
    00000101 >> 2 = 00000001

    ~0 = 11111111
    11111111 << 4 = 11110000
    ~11110000 = 00001111

    00000001 &
    00001111
    00000001
*/

/*
    x = 5, p = 4, n = 3
    5 = 00000101
//         XXX

    00000101 >> 4+1-3
    00000101 >> 2 = 00000001

    ~0 = 11111111
    11111111 << 3 = 11111000
    ~11111000 = 00000111

    00000001 &
    00000111
    00000001
*/

/*
    x = 11, p = 4, n = 3
    11 = 00001011

    00001011 >> 4+1-3
    00001011 >> 2 = 00000010

    ~0 = 11111111
    11111111 << 3 = 11111000
    ~11111000 = 00000111

    00000010 &
    00000111
    00000010
*/

/*
    x = 112, p = 4, n = 3
    112 = 01110000

    01110000 >> 2 = 00011100

    00011100 &
    00000111
    00000100
*/