#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABSIZE 8
#define MAXLINE 100

char buffer[MAXLINE];

char* getnewline()
{
    int c, i = 0;
    char *s = buffer;

    while (((c = getchar()) != '\n') && (c != EOF))
        buffer[i++] = c;
    
    if (c == EOF)
        return NULL;

    buffer[i] = '\0';

    return s;
}

int countspaces(char *s)
{
    int i, count = 0;

    while (*s == ' ')
        s++, count++;

    return count;
}

char* allocspaces(int i)
{
    static char s[100];
    int j = 0;

    while (i >= TABSIZE)
    {
        s[j++] = '\t';
        i -= TABSIZE;
    }

    while (i-- >= 0)
        s[j++] = ' ';

    return s;
}

int addspaces(int i)
{
    int j, count = 0;
    for (j = 0; j <= i; j++)
    {
        printf(" ");
        count++;
    }

    return count;
}

// Write a program detab that replaces tabs in the input with the proper number
//of blanks to space to the next tab stop. Assume a fixed set of tab stops, say every n columns
void detab(int startcol, int tablen)
{
    int c, i, count = 1;
    while ((c = getchar()) != EOF)
    {
        if (c == '\n')
            count = 0;

        if (c != '\t')
            printf("%c", c);
        else if (count > startcol)
        {
            int spaces = tablen - ((count) % tablen);
            count += addspaces(spaces);
            continue;
        }

        count++;
    }
}

// Write a program entab that replaces strings of blanks by the minimum number
// of tabs and blanks to achieve the same spacing. Use the same tab stops as for
// detab. When either a tab or a single blank would suffice to reach a tab stop,
// which should be given preference?
void entab2()
{
    // get input
    // find how many spaces there are
    // count how many tabs can go in those spaces
    // make the left over spaces go after the tabs
    // print result

    char *s;

    while ((s = getnewline()) != NULL)
    {
        char *t = s;
        int prevspaces = 0;
        while (*s != '\0')
        {
            int spaces = countspaces(s);

            if ((spaces > prevspaces) && spaces >= TABSIZE)
            {
                int nexttab = 8 - ((s-t) % TABSIZE);

                int newspaces = spaces;
                if (spaces >= nexttab)
                {
                    newspaces -= nexttab;
                }

                printf("%s", allocspaces(spaces));
                s += spaces;
            }
            else if (spaces == 0)
            {
                printf("%c", *s++);
            }

            prevspaces = spaces;
        }
        printf("\n");
    }
}

void entab(int startcol, int tablen)
{
    // get character
    // if character is space then increment spaces and don't print anything
    // loop until the next character is not a space
    // find how many tabs can fit in the spaces, then make the rest spaces
    // print result if spaces = 0

    int c;
    int spaces = 0, count = 0;

    while ((c = getchar()) != EOF)
    {
        count++;

        if (c == '\n')
            count = 0;

        if (count > startcol)
        {
            if (c == ' ')
                spaces++;
            else if (c != ' ' && spaces > 0)
            {
                if (spaces > tablen)
                    spaces = spaces + ((count - spaces) - 1) % tablen;

                int tabs = (spaces - (spaces % tablen)) / tablen;
                spaces = spaces % tablen;

                while (tabs-- > 0)
                    putchar('\t');
                
                while (spaces-- > 0)
                    putchar(' ');

                spaces = 0;
            }
        }

        if (c != ' ')
            putchar(c);
    }
}

// extend entab and detab to accept the shorthand: entab -m +n
// to mean tab stops every n columns, starting at column m.
int main(int argc, char *argv[])
{
    /*
    if (argc > 1 && (atoi(argv[1]) > 0))
        entab(atoi(argv[1]));
    else
        entab(TABSIZE);
    */

    int startcol = 0;
    int tablen = TABSIZE;

    int i = 1;
    while (i < argc)
    {
        if (strcmp(argv[i], "-m") == 0)
            startcol = atoi(argv[i+1]);
        else if (strcmp(argv[i], "-n") == 0)
            tablen = atoi(argv[i+1]);
        i++;
    }

    //entab(startcol, tablen);
    detab(startcol, tablen);
}