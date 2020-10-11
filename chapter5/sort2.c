#include <stdio.h>
#include <string.h>

#define MAXLINES 5000
char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void qsort2(void *lineptr[], int left, int right, int (*comp)(void *, void *), int reverse);

int numcmp(char *, char *);

int main(int argc, char *argv[])
{
    int nlines;
    int numeric = 0;
    int reverse = 0;

    if (argc > 1 && strcmp(argv[1], "-n") == 0)
        numeric = 1;
    if ((argc > 1 && strcmp(argv[1], "-r") == 0) || argc > 2 && strcmp(argv[2], "-r") == 0)
        reverse = 1;
    if ((nlines = readlines(lineptr, MAXLINES)) >= 0)
    {
        qsort2((void **) lineptr, 0, nlines-1,
            numeric ? (int (*)(void*, void*)) numcmp : (int (*)(void*, void*)) strcmp,
            reverse);
        printf("\n");
        writelines(lineptr, nlines);
        return 0;
    }
    else
    {
        printf("input too big to sort\n");
        return 1;
    }
}

void qsort2(void *v[], int left, int right, int (*comp)(void *, void *), int reverse)
{
    int i, last;
    void swap(void *v[], int, int);

    if (left >= right)
        return;
    swap(v, left, (left + right) / 2);
    last = left;

    for (i = left + 1; i <= right; i++) 
    {
        if (reverse)
        {
            if ((*comp)(v[i], v[left]) > 0)
                swap(v, ++last, i);
        }
        else
        {
            if ((*comp)(v[i], v[left]) < 0)
                swap(v, ++last, i);
        }
    }

    swap(v, left, last);
    qsort2(v, left, last - 1, comp, reverse);
    qsort2(v, last + 1, right, comp, reverse);
}

#include <stdlib.h>

int numcmp(char *s1, char *s2)
{
    double v1, v2;

    v1 = atof(s1);
    v2 = atof(s2);
    if (v1 < v2)
        return -1;
    else if (v1 > v2)
        return 1;
    else
        return 0;
}

void swap(void *v[], int i, int j)
{
    void *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}


#define MAXLEN 1000   // max length of any input line
int getline2(char *, int);
char *alloc(int);

/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines)
{
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while ((len = getline2(line, MAXLEN)) > 0)
        if (nlines >= maxlines || (p = alloc(len)) == NULL)
            return -1;
        else
        {
            line[len-1] = '\0';   // delete newline
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    return nlines;
}

/* getline2: read a line into s, return length */
int getline2(char *s, int lim)
{
    int c, i;

    for (i = 0; i<lim-1 && (c=getchar()) != EOF && c != '\n'; i++)
        s[i] = c;
    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

#define ALLOCSIZE 50000           // size of available space

static char allocbuf[ALLOCSIZE];  // storage for alloc 
static char *allocp = allocbuf;   // next free position

char *alloc(int n)
{
    if (allocbuf + ALLOCSIZE - allocp >= n)   // if it fits
    {
        allocp += n;
        return allocp - n;  
    }
    else
        return 0;
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines)
{
    int i;

    for (i = 0; i < nlines; i++)
        printf("%s\n", lineptr[i]);
}
