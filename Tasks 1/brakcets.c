#include <stdio.h>

#define MAX 100

int main() {
    char string[MAX];

    printf("Please, enter the length of your string. This number should be < %d\n", MAX);
    int lengthOfString = 0;
    scanf("%d", &lengthOfString); // Ввод длины строки
    if (lengthOfString >= MAX) {
        printf("Sorry, the length of your string is wrong.\n");
        return 1;
    }
    printf("Please, enter your string.\n");
    scanf("%*c");
    fgets(string, lengthOfString + 1, stdin);
    int balance = 0;
    for (int i = 0; i < lengthOfString; i++) {
        if (string[i] == '(') {
            balance++;
        }
        if (string[i] == ')') {
            balance--;
        }
        if (balance < 0) {
            printf("Sorry, there isn't balance of brackets\n");
            return 1;
        }
    }
    if (balance != 0) {
        printf("Sorry, there isn't balance of brackets\n");
    } else {
        printf("Yes, all right!\n");
    }
    return 0;
}

