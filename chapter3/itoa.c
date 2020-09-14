void itoa(int n, char s[])
{
    int i, sign;

    if ((sign = n) < 0)
        n = -n;
    
    i = 0;
    do {
        s[i++] = n % 10 + '0';
        printf("%s\n", s);
    } while ((n /= 10) > 0);

    if (sign < 0)
        s[i++] = '-';
    
    s[i] = '\0';
}

int main(void)
{
    char s[100];
    itoa(338, s);
    //printf("%s", s);
}