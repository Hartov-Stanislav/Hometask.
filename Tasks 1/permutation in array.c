#include <stdio.h>

#define MAX 1000

void permutation(int *array[], int firstPositon, int lastPosition) {
    int counter = 0;
    for (int i = firstPositon; i <= (firstPositon + lastPosition) / 2; i++) {
        int temp = array[i];
        array[i] = array[lastPosition - counter];
        array[lastPosition - counter] = temp;
        counter++;
    }
}

int main() {
    printf("Please, enter the length of the first part of array < %d.\n", MAX / 2);
    int lengthOfArrayPart1 = 0;
    scanf("%d", &lengthOfArrayPart1); // Ввод длины первой части массива
    printf("Please, enter the length of the second part of array < %d.\n", MAX / 2);
    int lengthOfArrayPart2 = 0;
    scanf("%d", &lengthOfArrayPart2); // Ввод длины второй части массива
    int array[MAX]; // Создание массива МАХ размера
    printf("Please, enter members of this array.\n");
    for (int i = 0; i < (lengthOfArrayPart1 + lengthOfArrayPart2); i++) {
        scanf("%d", &array[i]); // Заполнение  массива
    }
    permutation(array, 0, lengthOfArrayPart1 - 1); // Перевортоты
    permutation(array, 0, lengthOfArrayPart1 + lengthOfArrayPart2 - 1);
    permutation(array, 0, lengthOfArrayPart2 - 1);
    for (int i = 0; i < lengthOfArrayPart1 + lengthOfArrayPart2; i++) { // Вывод
        printf("%d ", array[i]);
    }
    return 0;
}

