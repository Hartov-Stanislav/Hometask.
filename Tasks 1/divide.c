#include <stdio.h>

bool ch1(int a, int b)
{
    return (a >= 0 && b > 0);
}

bool ch2(int a, int b)
{
    return (a >= 0 && b < 0);
}

bool ch3(int a, int b)
{
    return (a <= 0 && b > 0);
}

bool ch4(int a, int b)
{
    return (a <= 0 && b < 0);
}

int alg1(int a, int b)
{
    int c = 0;
    while (a >= b * c)
    {
        if (a == b * c)
        {
            c++;
            break;
        }
        c++;
    }
    return c-1;
}

int alg2 (int a, int b)
{
    int c = 0;
    while (a >= b * c)
    {
        if (a == b * c)
        {
            break;
        }
        c--;
    }
    return c;
}

int alg3 (int a, int b)
{
    int c = 0;
    while (a <= b * c)
    {
        if (a == b * c)
        {
            break;
        }
        c--;
    }
    return c;
}

int alg4 (int a, int b)
{
    int c = 0;
    while (a <= b * c)
    {
        if (a == b * c)
        {
            break;
        }
        c++;
    }
    return c;
}


int main() {
    int a, b, c;//c-schetchik
    printf("Vvedide dellimoe\n");
    scanf_s("%d", &a);// Ввод делимого
    printf("Vvedite delitel\n");
    scanf_s("%d", &b);// Ввод делителя
    if (ch1(a, b))
    {
        c = alg1(a, b);
        printf("%d", c);
    }
    if (ch2(a, b))
    {
        c = alg2(a, b);
        printf("%d", c);
    }
    if (ch3(a, b))
    {
        c = alg3(a, b);
        printf("%d", c);
    }
    if (ch4(a, b))
    {
        c = alg4(a, b);
        printf("%d", c);
    }
    return 0;
}
