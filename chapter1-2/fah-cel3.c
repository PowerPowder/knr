#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

float convCel(int x);

int main() 
{
    float fahr, celcius;
    int lower, upper, step;

    printf("--- Fahrenheit to Celcius ---\n");

    for (fahr = LOWER; fahr <= UPPER; fahr += STEP)
        printf("%3.0f %6.1f\n", fahr, convCel(fahr));
}

float convCel(int fahr) 
{
    float celcius = (5.0 / 9.0) * (fahr - 32.0);

    return celcius;
}