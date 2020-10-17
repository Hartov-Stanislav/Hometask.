#include <stdio.h>

int fibonacciByRecursion(int number) {// Вычисление рекурсией
    if (number < 0) {
        return -1;
    }
    if (number == 1) {
        return 1;
    }
    if (number == 0) {
        return 0;
    }
    return fibonacciByRecursion(number - 1) + fibonacciByRecursion(number - 2);
}

int checkRecursionNegativeNumber() {// Проверка с отрицательным числом
    return fibonacciByRecursion(-8) == -1;
}

int checkRecursionNull() {// Проверка на ноль
    return fibonacciByRecursion(0) == 0;
}

int checkRecursionSmallNumber() {// Проверка с относительно малым числом на выходе
    return fibonacciByRecursion(5) == 5;
}

int checkRecursionGreatNumber() {// Проверка с большим числом на выходе
    return fibonacciByRecursion(43) == 433494437;
}

int fibonacciByIterator(int number) {

    if (number == 0) {
        return 0;
    }
    if (number == 1) {
        return 1;
    }
    if (number < 0) {
        return -1;
    }
    int firstTemp = 0;
    int secondTemp = 1;
    int answer = 0;
    for (int i = 2; i <= number; i++) {
        answer = firstTemp + secondTemp;
        firstTemp = secondTemp;
        secondTemp = answer;
    }
    return answer;
}

int checkIteratorNegativeNumber() {// Проверка с отрицательным числом
    return fibonacciByIterator(-5) == -1;
}

int checkIteratorNull() {// Проверка на ноль
    return fibonacciByIterator(0) == 0;
}

int checkIteratorSmallNumber() {// Проверка с относительно малым числом на выходе
    return fibonacciByIterator(6) == 8;
}

int checkIteratorGreatNumber() {// Проверка с большим числом на выходе
    return fibonacciByIterator(42) == 267914296;
}

void resultsOfTests(int test1, int test2, int test3, int test4) {
    if (test1 != 0) {
        printf("test completed ");
    }
    else {
        printf("test failed ");
    }
    printf("(Negative number)\n");
    if (test2 != 0) {
        printf("test completed ");
    }
    else {
        printf("test failed ");
    }
    printf("(Null)\n");
    if (test3 != 0) {
        printf("test completed ");
    }
    else {
        printf("test failed ");
    }
    printf("(Small number)\n");
    if (test4 != 0) {
        printf("test completed ");
    }
    else {
        printf("test failed ");
    }
    printf("(Great number)\n");
}

int main() {
    printf("Tests for solving by recursion\n");
    resultsOfTests(checkRecursionNegativeNumber(), checkRecursionNull(), checkRecursionSmallNumber(), checkRecursionGreatNumber());
    printf("Tests for solving iterator\n");
    resultsOfTests(checkIteratorNegativeNumber(), checkIteratorNull(), checkIteratorSmallNumber(), checkIteratorGreatNumber());
    printf("Please, enter thу fibonacci number < 47\n");
    int number = 0;
    scanf("%d", &number);
    if (number < 0) {
        printf("Sorry, wrong data");
        return 1;
    }
    printf("Your number fibonacci is %d (this data has been recived by solving with recursion)\n", fibonacciByRecursion(number));
    printf("Your number fibonacci is %d (this data has been recived by solving with iterator)\n", fibonacciByIterator(number));
    return 0;
}