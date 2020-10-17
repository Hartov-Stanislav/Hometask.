#include <stdio.h>
#include <math.h>

int main() {
    int max1 = 0;
    int counter = 0;
    printf("Please, enter the number >=2\n");
    scanf("%d", &max1);//ввод числа, до которого нужно вывести простые числа;
    for (int number = 2; number <= max1; number++)
    {
        for (int divisor = 2; divisor <= sqrt(number); divisor++)
        {
            if (number % divisor == 0)
            {
                counter++;// подсчет делителей number
            }
        }
        if (counter == 0)
        {
            printf("%d ", number);
        }
        counter = 0;
    }

    return 0;
}
