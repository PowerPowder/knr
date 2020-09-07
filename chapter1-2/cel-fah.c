#include <stdio.h>

int main() 
{
    float fahr, celcius;
    int lower, upper, step;

    lower = -10;
    upper = 30;
    step = 5;

    celcius = lower;

    printf("--- Celcius to Fahrenheit ---\n");

    while (celcius <= upper)
    {
        fahr = celcius * (9.0 / 5.0) + 32;
        printf("%3.0f %6.1f\n", celcius, fahr);
        celcius = celcius + step;
    }
}
