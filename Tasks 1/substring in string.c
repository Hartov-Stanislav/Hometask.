#include <stdio.h>

#define MAX 100

int occurrence(char mainString[], char substring[], int lengthOfMainString, int lengthOfSubstring) {
    int counterForCheck = 0; // Создание счетчика, который считает вхождение подстроки в главную строку
    int counter = 0; // // Создание счетчика, который подсчитывает количество элементов подстроки, содержащихся в кусочке главной строки
    for (int i = 0; i < lengthOfMainString - lengthOfSubstring + 1; i++) {

        for (int j = 0; j < lengthOfSubstring; j++) {
            if (substring[j] != mainString[i + j]) {
                break;
            } else {
                counterForCheck++;
            }

        }
        if (counterForCheck == lengthOfSubstring) {
            counter++;
        }
        counterForCheck = 0;
    }
    return counter;
}

int main() {
    printf("Please, enter the length of main string < %d.\n", MAX);
    int lengthOfMainString = 0;
    scanf("%d", &lengthOfMainString); // Ввод длины главной строки
    char mainString[MAX];
    printf("Please, enter your main string.\n");
    scanf("%*c");
    fgets(mainString, lengthOfMainString + 1, stdin); // Ввод главной строки
    printf("Please, enter the length of substring < %d.\n", MAX);
    int lengthOfSubstring = 0;
    scanf("%d", &lengthOfSubstring); // Ввод длины подстроки
    if (lengthOfMainString < lengthOfSubstring) {
        printf("Sorry, the length of main string < the length of substring"); // Ругается, если данные некоректны
        return 1;
    }
    char substring[MAX];
    printf("Please, enter your substring.\n");
    scanf("%*c");
    fgets(substring, lengthOfSubstring + 1, stdin); // Ввод подстроки
    int answer = occurrence(mainString, substring, lengthOfMainString, lengthOfSubstring);
    printf("Occurrence of a substring in the main string is %d",answer); // Вывод количества вхождения подстроки в строку
    return 0;
}