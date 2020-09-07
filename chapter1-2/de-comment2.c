#include <stdio.h>

#define BUFFERSIZE 10000

int main()
{
    // test
    int c, i, size, slc, mlc;
    char buffer[BUFFERSIZE];

    while ((c = getchar()) != EOF)
        buffer[i++] = c;

    buffer[i] = '\0';

    size = i;

    slc = mlc = 0;
    // boi
    for (i = 0; i < size; ++i)
    {
        if (buffer[i] == '/' && buffer[i+1] == '/')
            slc = 1;
        else if (buffer[i] == '/' && buffer[i+1] == '*')
            mlc = 1;

        if (buffer[i] == '\n')
            slc = 0;
        
        if (buffer[i-2] == '*' && buffer[i-1] == '/')
            mlc = 0;
        
        if (!(slc || mlc))
            printf("%c", buffer[i]);
    }
}

/*
    if there are 2 slashes, then wait until newline character, and only use that
    if there is one slash, followed by an asterisk, then wait until another asterisk
        followed by a forward slash
*/
