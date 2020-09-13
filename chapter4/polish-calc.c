#include <stdio.h>
#include <stdlib.h> // for atof()
#include <math.h>

#define MAXOP 100   // max size od operand or operator
#define NUMBER '0'  // signal that a number was found

int getop(char []);
void push(double);
double pop(void);

void showtop(void);
void duplicate(void);
void swap(void);
void clear(void);

void setvar(int, double);
double getvar(int);

/*
    Ex 4-4: 'p' to print, 'd' to duplicate, 's' to swap top two elements, 'c' to clear
    Ex 4-5: '~' for sin, 'e' for exp, '^' for pow
    Ex 4-6: variables go from A to Z, to write to a variable do @A to @Z
*/

// reverse Polish calculator
int main()
{
    int type, expectvar, prevtype;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF)
    {
        switch (type)
        {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero divisor\n");
                break;
            case '%':
                op2 = pop();
                push((int)pop() % (int)op2);
                break;
            case '~':
                push(sin(pop()));
                break;
            case 'e':
                push(exp(pop()));
                break;
            case '^':
                op2 = pop();
                push(pow(pop(), op2));
                break;
            case 'p':
                showtop();
                break;
            case 'd':
                duplicate();
                break;
            case 's':
                swap();
                break;
            case 'c':
                clear();
                break;
            case '\n':
                if (!(prevtype >= 'A' && prevtype <= 'Z'))
                    printf("\t%.8g\n", pop());
                else
                    printf("\t%.8g\n", getvar(prevtype));
                break;
            case '@':
                expectvar = 1;
                break;
            case 'A': case 'B': case 'C': case 'D': case 'E': case 'F': case 'G':
            case 'H': case 'I': case 'J': case 'K': case 'L': case 'M': case 'N':
            case 'O': case 'P': case 'Q': case 'R': case 'S': case 'T': case 'U':
            case 'V': case 'W': case 'X': case 'Y': case 'Z':
                if (expectvar)
                {
                    setvar(type, pop());
                    expectvar = 0;
                }
                else
                    push(getvar(type));
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }

        prevtype = type;
    }

    return 0;
}

#define MAXVAL 100  // maximum depth of val stack

int sp = 0;         // next free stack position
double val[MAXVAL]; // value stack

// push:    push f onto value stack
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

// pop: pop and return top value from stack
double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else
    {
        printf("error: stack empty\n");
        return 0.0;
    }
}

void showtop(void)
{
    if (sp > 0)
        printf("The stack has %g at the top\n", val[sp - 1]);
    else
        printf("The stack is empty\n");
}

void duplicate(void)
{
    if (sp > 0)
        push(val[sp - 1]);
    else
        printf("The stack is empty");
}

void swap(void)
{
    if ((sp-2) >= 0)
    {
        double value1 = pop();
        double value2 = pop();

        push(value1);
        push(value2);
    }
    else
        printf("Not enough values\n");
}

void clear(void)
{
    while (sp > 0)
        pop();
}

double v[27];

void setvar(int var, double val)
{
    if (var == 0)
        v[26] = val;

    int pos= var - 'A';

    if (pos >= 0)
        v[pos] = val;
    else
        printf("error: value not stored in var\n");
}

double getvar(int var)
{
    int pos = var - 'A';

    if (pos >= 0)
        return v[pos];
    else
        return 0.0;
}

#include <ctype.h>

int getch(void);
void ungetch(int);

// getop: get next operator or numeric operand
int getop(char s[])
{
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;

    s[1] = '\0';

    if (!isdigit(c) && c != '.')
        return c;

    i = 0;
    if (isdigit(c))
        while (isdigit(s[++i] = c = getch()))
            ;

    if (c == '.')
        while (isdigit(s[++i] = c = getch()))
            ;

    s[i] = '\0';

    if (c != EOF)
        ungetch(c);

    return NUMBER;
}

#define BUFSIZE 100

char buf[BUFSIZE];  // buffer for ungetch
int bufp = 0;       // next free position in buf

int getch(void)     // get a (possible pushed back) character
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) // push character back on input
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}