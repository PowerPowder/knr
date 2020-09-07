#include <stdio.h>

#define SPACES 4 

int main()
{
    int c, cNum;

    cNum = 0;
    while ((c = getchar()) != EOF)
    {
        if (c == '\t')
        {
            while (!(cNum % SPACES == 0))
            {
                putchar(' ');
                ++cNum;
            }
        }
        else
        {
            ++cNum;
            putchar(c);
        }
    }
}