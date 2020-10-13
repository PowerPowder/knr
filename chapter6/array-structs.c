#include <stdio.h>

int main()
{
    struct key {
        char *word;
        int count;
    } keytab[] = {
        "auto", 0,
        "break", 0,
        "case", 0,
        "char", 0,
        "const", 0,
        "continue", 0,
        "default", 0,
        "unsigned", 0,
        "void", 0,
        "volatile", 0,
        "while", 0
    };

    struct key boi;
    boi.word = "hehehe";
    boi.count = 5;

    printf("%s %d", boi.word, boi.count);
}