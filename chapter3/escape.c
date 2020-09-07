#include <stdio.h>
#include <string.h>

/*
    Write a function escape(s,t) that converts characters like newline and tab
    into visible escape sequences like \n and \t as it copies the string t to s.
    Use a switch.
*/
void escape(char s[], char t[])
{
    int i;
    for (i = 0; i < strlen(t); ++i)
    {
        switch (t[i])
        {
            case '\t':
                s[i] = '\\';
                s[++i] = 't';
                break;
            case '\n':
                s[i] = '\\';
                s[++i] = 'n';
                break;
            default:
                s[i] = t[i];
                break;
        }
    }
}

/*
    Write a function for the other direction as well, converting
    escape sequences into the real characters.
*/
int real(char s[], char t[])
{

}

int main()
{
    char s[1000];
    escape(s, "\nthere!\t");
    printf("%s", s);
}