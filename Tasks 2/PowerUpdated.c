#include <stdio.h>

#define DELTA  0.0000001

// Реализация " в лоб"
float powerSlow(int number, int powerInt) {
    // Возведение нуля в степень
    if (number == 0) {
        // "Особый" случай 0^0
        if (powerInt == 0) {
            return 1;
        }
        else {
            return 0;
        }
    }
    if (powerInt == 0) {
        return 1;
    }
    // Возведение в неотрицательную степень
    if (powerInt >= 0) {
        return number * powerSlow(number, powerInt - 1);
    }
    // Возведение в отрицательную степень
    if (powerInt < 0) {
        return powerSlow(number, powerInt + 1) / number;
    }
}

// Проверка на возведение числа в нулевую степень
int checkPowerSlowNullPower() {
    return abs(powerSlow(0, 0) - 1.000000) < DELTA && abs(powerSlow(5, 0) - 1.000000) < DELTA;
}

// Проверка на возведение числа в отрицательную степень
int checkPowerSlowNegativeNumber() {
    return abs(powerSlow(8, -3) - 0.001953) < DELTA && abs(powerSlow(5, -5) - 0.000320) < DELTA;
}

// Прверка на возведение нуля в отличную от нуля степень
int checkPowerSlowNull() {
    return abs(powerSlow(0, 6) - 0.000000) < DELTA && abs(powerSlow(0, -8) - 0.000000) < DELTA;
}

// Проверка на возведение числа в положительную степень
int checkPowerSlowPositive() {
    return abs(powerSlow(2, 2) - 4.000000) < DELTA && abs(powerSlow(6, 7) - 279936.000000) < DELTA;
}

// Реализация со сложностью О(log(n))
float powerQuick(int number, int powerInt) {
    // Возведение нуля в степень
    if (number == 0) {
        // "Особый" случай 0^0
        if (powerInt == 0) {
            return 1;
        }
        else {
            return 0;
        }
    }
    if (powerInt == 0) {
        return 1;
    }
    // Возведение в неотрицательную степень
    if (powerInt >= 0) {
        if (powerInt % 2 == 0) {
            return powerQuick(number * number, powerInt / 2);
        }
        else {
            return number * powerQuick(number, powerInt - 1);
        }
    }
    // Возведение в отрицательную степень
    if (powerInt < 0) {
        if (powerInt % 2 == 0) {
            return powerQuick(number * number, powerInt / 2);
        }
        else {
            return powerQuick(number, powerInt + 1) / number;
        }
    }
}

// Проверка на возведение числа в нулевую степень
int checkPowerQuickNullPower() {
    return abs(powerQuick(0, 0) - 1.000000) < DELTA && abs(powerQuick(23, 0) - 1.000000) < DELTA;
}

// Проверка на возведение числа в отрицательную степень
int checkPowerQuickNegativeNumber() {
    return abs(powerQuick(9, -2) - 0.012346) < DELTA && abs(powerQuick(6, -6) - 0.000021) < DELTA;
}

// Прверка на возведение нуля в отличную от нуля степень
int checkPowerQuickNull() {
    return abs(powerQuick(0, 9) - 0.000000) < DELTA && abs(powerQuick(0, -10) - 0.000000) < DELTA;
}

// Проверка на возведение числа в положительную степень
int checkPowerQuickPositive() {
    return abs(powerQuick(3, 3) - 27.000000) < DELTA && abs(powerQuick(7, 6) - 117649.000000) < DELTA;
}

// Прохождение тестов
void resultsOfTests(int test1, int test2, int test3, int test4) {
    if (test1 != 0) {
        printf("test completed ");
    }
    else {
        printf("test failed ");
    }
    printf("(Null power)\n");
    if (test2 != 0) {
        printf("test completed ");
    }
    else {
        printf("test failed ");
    }
    printf("(Negative power)\n");
    if (test3 != 0) {
        printf("test completed ");
    }
    else {
        printf("test failed ");
    }
    printf("(Null in any power (without null power))\n");
    if (test4 != 0) {
        printf("test completed ");
    }
    else {
        printf("test failed ");
    }
    printf("(Positive power)\n");
}

int main() {
    // Прохождение тестов
    resultsOfTests(checkPowerQuickNullPower(), checkPowerQuickNegativeNumber(), checkPowerQuickNull(), checkPowerQuickPositive());
    resultsOfTests(checkPowerSlowNullPower(), checkPowerSlowNegativeNumber(), checkPowerSlowNull(), checkPowerSlowPositive());
    printf("Please, enter the number,which you would like to raised to the power\n");
    // Ввод числа для возведения в некоторую степень
    int number = 0;
    scanf("%d", &number);
    printf("Please, enter the power, of your new number\n");
    // Ввод показателя степени
    int powerInt = 0;
    scanf("%d", &powerInt);
    // Случай 0^0
    if (number == 0 && powerInt == 0) {
        printf("Sorry, but it is indeterminacy");
        return 1;
    }
    printf("The solution of your problem is %f (solved by function powerQuick)\n", powerQuick(number, powerInt));
    printf("The solution of your problem is %f (solved by function powerSlow)\n", powerSlow(number, powerInt));
    return 0;
}