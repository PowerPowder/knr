#include <stdio.h>

#define BUFFERSIZE 1000

int main()
{
    int c, i, skip;
    int slc, mlc;
    int slashes, asterisks;

    char buffer[BUFFERSIZE];

    slashes = asterisks = 0;
    slc = mlc = 0;
    i = 0;
    skip = 0;
    while ((c = getchar()) != EOF)
    {
        if (c == '/')
            ++slashes;

        // this is for 2 double foward slashes - //
        if (slashes == 2)
            slc++;

        if (slc)
        {
            skip = 1;
            i--;
            slashes = 0;
        }

        // this is for /* ... */
        if (slashes == 1 && c == '*')
            mlc++;

        if (!skip || c == '\n')
            buffer[i++] = c;

        if (mlc)
            skip = 1;

        // This prints and resets the char array
        if (c == '\n' && slc)
        {
            buffer[i] = '\0';

            printf("%s", buffer);

            buffer[0] = '\0';
            i = 0;

            if (slc)
                skip = 0;

            slc = 0;
        }
        else if (mlc && buffer[i] == '*' && c == '/')
        {
            buffer[i] = '\0';
            printf("%s", buffer);

            buffer[0] = '\0';
            i = 0;

            skip = 0;
            mlc = 0;
        }
    }
}

/*
    if there are 2 slashes, then wait until newline character, and only use that
    if there is one slash, followed by an asterisk, then wait until another asterisk
        followed by a forward slash
*/