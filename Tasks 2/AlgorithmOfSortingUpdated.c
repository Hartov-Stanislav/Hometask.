#include <stdio.h>
#include <stdlib.h>

// Функция циклического сдвига влево на один элемент
void cyclePermutationLeft(int array[], int point1, int point2) {
	int temp = array[point1];
	for (int i = point1; i < point2; i++) {
		array[i] = array[i + 1];
		}
	array[point2] = temp;
}

 // Алгоритм сортировки
void algorithmOfSorting(int array[], int sizeOfArray) {
	int firstElement = array[0];
	int i = 1;
	int j = sizeOfArray - 1;
	while (i <= j) {
		while(array[i] < firstElement && i < j) {
			i++;
		}
		while(array[j] >= firstElement && i < j) {
			j--;
		}
		int temp = array[i];
		array[i] = array[j];
		array[j] = temp;
		i++;
		j--;
	}
	cyclePermutationLeft(array, 0, sizeOfArray - 1);
}

// Тест для массива из одного элемента
int testWithOneElement() {
	int array[1] = { 13 };
	int sample[1] = { 13 };
	algorithmOfSorting(array, 1);
	if (array[0] == sample[0]) {
		return 1;
	}
	else {
		return 0;
	}
}

// Тест для массива, состоящего из одинаковых элементов
int  testEqualElements() {
	int array[12] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 };
	int sample[12] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 };
	algorithmOfSorting(array, 12);
	int mistakes = 0;
	for (int i = 0; i < 12; i++) {
		if (array[i] != sample[i]) {
			mistakes++;
		}
	}
	if (mistakes == 0) {
		return 1;
	}
	else {
		return 0;
	}
}

// Тест для "обычной"  ситуации
int testStandardSituation() {
	int array[20] = { 45, 1, 2, -2, 45, 46, 2, 9, 90, 2, -100, 2, 65, 21, 7, 1, -45, -70, 18, 130 };
	int sample[20] = { 1, 2, -2, 18, -70, 2, 9, -45, 2, -100, 2, 1, 21, 7, 65, 90, 46, 45, 130, 45 };
	int mistakes = 0;
	algorithmOfSorting(array, 20);
	for (int i = 0; i < 20; i++) {
		if (array[i] != sample[i]) {
			mistakes++;
		}
	}
	if (mistakes == 0) {
		return 1;
	}
	else {
		return 0;
	}
}

void resultsOfTests(int test1, int test2, int test3) {
	if (test1 != 0) {
		printf("test completed ");
	}
	else {
		printf("test failed ");
	}
	printf("(Array consists of 1 element)\n");
	if (test2 != 0) {
		printf("test completed ");
	}
	else {
		printf("test failed ");
	}
	printf("(Array consists of the same elements)\n");
	if (test3 != 0) {
		printf("test completed ");
	}
	else {
		printf("test failed ");
	}
	printf("(Usual case)\n");
}

int main() {
	printf("Tests for algorithm of sorting\n");
	resultsOfTests(testEqualElements(), testStandardSituation(), testWithOneElement());
	printf("Please, enter size of array\n");
	// Создание массива
	int sizeOfArray = 0;
	scanf("%d", &sizeOfArray);
	int* array;
	array = (int*)malloc((sizeOfArray + 1) * sizeof(int));
	for (int i = 0; i < sizeOfArray; i++) {
		array[i] = rand();
	}
	for (int i = 0; i < sizeOfArray; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
	algorithmOfSorting(array, sizeOfArray);
	for (int i = 0; i < sizeOfArray; i++) {
		printf("%d ", array[i]);
	}
	free(array);
	return 0;
}