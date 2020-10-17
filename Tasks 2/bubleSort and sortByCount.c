#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// Сортировка "пузырьком"
void bubbleSort(int array[], int sizeOfArray) {
	for (int i = sizeOfArray - 1; i >= 0; i--) {
		for (int j = 1; j < sizeOfArray; j++) {
			if (array[j] < array[j - 1]) {
				int temp = array[j];
				array[j] = array[j - 1];
				array[j - 1] = temp;
			}
		}
	}
}

// Сортировка подсчетом
void sortByCounting(int array[], int sizeOfArray) {
	int min = array[0];
	int max = array[0];
	for (int i = 0; i < sizeOfArray; i++) {
		if (min > array[i]) {
			min = array[i];
		}
		if (max < array[i]) {
			max = array[i];
		}
	}
	// Cоздание массива для подсчета повторяющихся элементов
	int* storage;
	int sizeOfStorage = max - min + 1;
	storage = (int*)malloc(sizeOfStorage * sizeof(int));
	// Заполнили массив для подсчета нулями
	for (int i = 0; i < sizeOfStorage; i++) {
		storage[i] = 0;
	}
	// Прошли по массиву, посчитали количество каждого элемента
	for (int i = 0; i < sizeOfArray; i++) {
		int temp1 = array[i];
		storage[temp1 - min]++;
	}
	// Изменение исхoдного массива
	int temp = 0;
	for (int i = 0; i <= sizeOfStorage; i++) {
		for (int j = 0; j < storage[i]; j++) {
			array[temp] = i + min;
			temp++;
		}
	}
	free(storage);
}

// Тест сортировки пузырьком для положительных чисел
void test1BubbleSort() {
	int array[10] = { 5, 2, 6, 1, 5, 6, 9, 7, 9, 10 };
	int sample[10] = { 1, 2, 5, 5, 6, 6, 7, 9, 9, 10 };
	bubbleSort(array, 10);
	int mistakes = 0;
	for (int i = 0; i < 10; i++) {
		if (array[i] != sample[i]) {
			mistakes++;
		}
	}
	if (mistakes != 0) {
		printf("Test n1 failed\n");
	}
	else {
		printf("Test n1 completed\n");
	}
}

// Тест сортировки пузырьком для любых чисел
void test2BubbleSort() {
	int array[13] = { -2, 23, 56, -12, 23, 45, 2, 6, 8, 9, 10, 123, 13 };
	int sample[13] = { -12, -2, 2, 6, 8, 9, 10, 13, 23, 23, 45, 56, 123 };
	bubbleSort(array, 13);
	int mistakes = 0;
	for (int i = 0; i < 13; i++) {
		if (array[i] != sample[i]) {
			mistakes++;
		}
	}
	if (mistakes != 0) {
		printf("Test n2 failed\n");
	}
	else {
		printf("Test n2 completed\n");
	}
}

// Тест сортировки пузырьком для 1ого элемента
void test3BubbleSort() {
	int array[1] = { 13 };
	bubbleSort(array, 1);
	int sample[1] = { 13 };
	if (array[0] != sample[0]) {
		printf("Test n3 failed\n");
	}
	else {
		printf("Test n3 completed\n");
	}
}

// Тест сортировки пузырьком для одинаковых элементов
void test4BubbleSort() {
	int array[6] = { 12, 12, 12, 12, 12, 12 };
	bubbleSort(array, 6);
	int sample[6] = { 12, 12, 12, 12, 12, 12 };
	int mistakes = 0;
	for (int i = 0; i < 6; i++) {
		if (array[i] != sample[i]) {
			mistakes++;
		}
	}
	if (mistakes != 0) {
		printf("Test n4 failed\n");
	}
	else {
		printf("Test n4 completed\n");
	}
}

// Тест сортировки подсчетом для положительных чисел
void test1sortByCounting() {
	int array[10] = { 5, 2, 6, 1, 5, 6, 9, 7, 9, 10 };
	int sample[10] = { 1, 2, 5, 5, 6, 6, 7, 9, 9, 10 };
	sortByCounting(array, 10);
	int mistakes = 0;
	for (int i = 0; i < 10; i++) {
		if (array[i] != sample[i]) {
			mistakes++;
		}
	}
	if (mistakes != 0) {
		printf("Test n1 failed\n");
	}
	else {
		printf("Test n1 completed\n");
	}
}

// Тест сортировки подсчетом для любых чисел
void test2SortByCounting() {
	int array[13] = { -2, 23, 56, -12, 23, 45, 2, 6, 8, 9, 10, 123, 13 };
	int sample[13] = { -12, -2, 2, 6, 8, 9, 10, 13, 23, 23, 45, 56, 123 };
	sortByCounting(array, 13);
	int mistakes = 0;
	for (int i = 0; i < 13; i++) {
		if (array[i] != sample[i]) {
			mistakes++;
		}
	}
	if (mistakes != 0) {
		printf("Test n2 failed\n");
	}
	else {
		printf("Test n2 completed\n");
	}
}

// Тест сортировки подсчетом для 1ого элемента
void test3SortByCounting() {
	int array[1] = { 13 };
	sortByCounting(array, 1);
	int sample[1] = { 13 };
	if (array[0] != sample[0]) {
		printf("Test n3 failed\n");
	}
	else {
		printf("Test n3 completed\n");
	}
}

// Тест сортировки подсчетом для одинаковых элементов
void test4SortByCounting() {
	int array[6] = { 12, 12, 12, 12, 12, 12 };
	sortByCounting(array, 6);
	int sample[6] = { 12, 12, 12, 12, 12, 12 };
	int mistakes = 0;
	for (int i = 0; i < 6; i++) {
		if (array[i] != sample[i]) {
			mistakes++;
		}
	}
	if (mistakes != 0) {
		printf("Test n4 failed\n");
	}
	else {
		printf("Test n4 completed\n");
	}
}
int main() {
	// Прохождение тестов
	printf("Tests for bubble sorting\n");
	test1BubbleSort();
	test2BubbleSort();
	test3BubbleSort();
	test4BubbleSort();
	printf("Tests for sorting by counting\n");
	test1sortByCounting();
	test2SortByCounting();
	test3SortByCounting();
	test4SortByCounting();
	// Создание и заполнение массива на 100000 элементов
	int tеstingArray[100000];
	for (int i = 0; i < 100000; i++) {
		tеstingArray[i] = -i;
	}
	// Подсчет времени работы для сортировки пузырьком
	unsigned int startTime = clock();
	bubbleSort(tеstingArray, 100000);
	unsigned int endTime = clock();
	unsigned int searchTime = endTime - startTime;
	// Вывод результата
	printf("Bubble sort took %u ticks\n", searchTime);
	// Подсчет времени работы для сортировки подсчетом
	startTime = clock();
	sortByCounting(tеstingArray, 100000);
	endTime = clock();
	searchTime = endTime - startTime;
	// Вывод результата
	printf("sorting by Counting took %u ticks\n", searchTime);
	return 0;
}