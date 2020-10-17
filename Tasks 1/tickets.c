#include <stdio.h>

int main() {
    int array[28];
    for (int counter = 0; counter < 28; counter++)
    {
        array[counter] = 0;
    }
    for (int firstn = 0; firstn < 10; firstn++) //перебор чисел
    {
        for (int secondn = 0; secondn < 10; secondn++)
        {
            for (int thirdn = 0; thirdn < 10; thirdn++)
            {
                array[firstn + secondn + thirdn]++;
            }
        }
    }
    int amount = 0;
    for (int counter = 0; counter < 28; counter++) // поэтапный подсчет билетов
    {
        amount = amount + array[counter] * array[counter];
    }
    printf("%d",amount); // вывод кол-ва счастливых билетов
    return 0;
}


