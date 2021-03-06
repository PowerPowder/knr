#include <stdio.h>
#include <string.h>

#define MAXLINES 5000

char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines, char buffer[]);
void writelines(char *lineptr[], int nlines);

void qsort(char *lineptr[], int left, int right);

int main()
{
    int nlines;
    char buffer[10000];

    if ((nlines = readlines(lineptr, MAXLINES, buffer)) >= 0)
    {
        qsort(lineptr, 0, nlines-1);
        writelines(lineptr, nlines);
        return 0;
    }
    else
    {
        printf("error: input too big to sort\n");
        return 1;
    }
    
}

#define MAXLEN 1000
int agetline(char *, int);
char *alloc(int);

int readlines(char *lineptr[], int maxlines, char buffer[])
{
    int len, nlines;
    char *p, line[MAXLEN];

    char *index = buffer;

    nlines = 0;
    while ((len = agetline(line, MAXLEN)) > 0)
    {
        if (nlines >= maxlines || (buffer + 10000 - index) <= len)
            return -1;
        else
        {
            p = index;
            line[len-1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;

            index += len;
        }
    }

    return nlines;
}

void writelines(char *lineptr[], int nlines)
{
    while(nlines-- > 0)
        printf("%s\n", *lineptr++);
}

void swap(char *v[], int i, int j)
{
    char *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

void qsort(char *v[], int left, int right)
{
    int i, last;

    if (left >= right)
        return;

    swap(v, left, (left + right)/2);

    last = left;

    for (i = left+1; i <= right; i++)
        if (strcmp(v[i], v[left]) < 0)
            swap(v, ++last, i);

    swap(v, left, last);

    qsort(v, left, last-1);
    qsort(v, last+1, right);
}


int agetline(char s[], int lim)
{
    int c, i;

    for (i=0; i<lim-1 && (c=getchar()) !=EOF && c!= '\n'; ++i)
        s[i] = c;
    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

#define ALLOCSIZE 10000 // size of available space

static char allocbuf[ALLOCSIZE];    // storage for alloc
static char *allocp = allocbuf;     // next free position

char *alloc(int n)
{
    if (allocbuf + ALLOCSIZE - allocp >= n) // it fits
    {
        allocp += n;
        return allocp - n; // old p
    }
    else
        return 0;
}