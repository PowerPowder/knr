#include <stdio.h>
#include <ctype.h>

#define MAXLINE 100

int getLine(char s[], int lim)
{
    int c, i;

    i = 0;
    while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
        s[i++] = c;

    if (c == '\n')
        s[i++] = c;

    s[i] = '\0';

    return i;
}

double atof(char s[])
{
    double val, power, sci;
    double result;
    int i, sign;

    for (i = 0; isspace(s[i]); i++) /* skip the whitespace */
        ;

    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');

    if (s[i] == '.')
        i++;

    for (power = 1.0; isdigit(s[i]); i++)
    {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }

    result = sign * val / power;

    if (s[i++] == 'e' || s[i++] == 'E')
    {
        if (!isdigit(s[i]))
            return result;

        sign = (s[i] == '-') ? -1 : 1;
        if (s[i] == '+' || s[i] == '-')
            i++;
        
        int sci = (s[i] - '0') * sign;

        float multiplier;
        if (sci > 0)
            multiplier = 10.0;
        else if (sci < 0)
        {
            sci *= -1;
            multiplier = 0.1;
        }

        for (i = 0; i < sci; i++)
            result *= multiplier;
    }

    return result;
}

int main()
{
    double sum, atof(char []);
    char line[MAXLINE];
    int getLine(char line[], int max);

    sum = 0;
    while (getLine(line, MAXLINE) > 0)
        printf("\t%g\n", sum += atof(line));

    return 0;
}