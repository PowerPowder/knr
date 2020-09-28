#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define OP '0'
#define NUM '1'

int sp = 0;
int val[100]; 

void push(int f)
{
    if (sp < 100)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %d\n", f);
}

int pop(void)
{
    if (sp > 0)
        return val[--sp];
    else
        printf("error: stack empty\n");
    return 0;
}

int getop(char *s)
{
    int i = 0;

    while (*s == ' ' || *s == '\0')
        s++;

    if (isdigit(*s))
        return NUM;
    else if (*s == '*' || *s == '/' || *s == '+' || *s == '-')
        return *s;
    else
        return 0;
}

// expr 2 3 4 + *   ->   2 x (3+4)
int main(int argc, char *argv[])
{
    int i, j;
    for (i = 1; i < argc; i++)
    {
        int type, op2;
        switch (type = getop(argv[i]))
        {
            case NUM:
                push(atoi(argv[i]));
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

                if (op2 != 0)
                    push(pop() / op2);
                else
                    printf("Division by 0\n");
                break;
            default:
                printf("'%c' is not valid.", *argv[i]);
                break;
        }
    }

    printf("%d", pop());
}