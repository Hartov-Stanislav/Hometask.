#include <iostream>
#include <stdlib.h>

#define MAX 1000

// Функция просто пробегает по массиву и исчет наиболее часто встречаемые элементы
int searchFrequentElement(int* array, int sizeOfArray, int min)
{
	int temp = min;
	int counter = array[0];
	for (int i = 1; i < sizeOfArray; i++)
	{
		if (array[i] > counter)
		{
			temp = i + min;
			counter = array[i];
		}
	}
	int answer = temp;
	return answer;
}

// Часть сортировки подсчётом, которая записывает количество каждого элемента
int elementCount(int array[], int sizeOfArray)
{
	int min = array[0];
	int max = array[0];
	for (int i = 0; i < sizeOfArray; i++)
	{
		if (min > array[i])
		{
			min = array[i];
		}
		if (max < array[i])
		{
			max = array[i];
		}
	}
	// Cоздание массива для подсчета повторяющихся элементов
	int sizeOfStorage = max - min + 1;
	int* storage = (int*)calloc(sizeOfStorage, sizeof(int));
	// Прошли по массиву, посчитали количество каждого элемента
	for (int i = 0; i < sizeOfArray; i++) {
		int temp1 = array[i];
		storage[temp1 - min]++;
	}
	return searchFrequentElement(storage, sizeOfStorage, min);
	free(storage);
}

// Тесты

// Тест с одним элементом в массиве
int testWithOneElement()
{
	int array[1] = { 1 };
	return elementCount(array, 1) == 1;
}

// Тест с несколькими вариантами ответа
int testWithMoreThanOneAnswers()
{
	int array[] = { 1, 3, 2, 5, 3, 1, 2, 3, 1, 2, 5, 7 };
	return (elementCount(array, 12) == 1 || elementCount(array, 12) == 2 || elementCount(array, 12) == 3);
}

// Тест в массиве из одинаковых элементов
int testWithEqualElements()
{
	int* array = (int*)calloc(MAX, sizeof(int));
	return (elementCount(array, MAX)) == 0;
	free(array);
}

// Функция для прохождения теста
void checkTest(int test)
{
	if (test == 0)
	{
		printf("Test failed\n");
	}
	else
	{
		printf("Test completed\n");
	}
}

// Функция для прохождения тестов
void checkTests()
{
	printf("Test with 1 element \n");
	checkTest(testWithOneElement());
	printf("Test with equal elements \n");
	checkTest(testWithEqualElements());
	printf("Usual test \n");
	checkTest(testWithMoreThanOneAnswers());
}

int main()
{
	checkTests();
	if (testWithEqualElements() + testWithMoreThanOneAnswers() + testWithOneElement() < 3)
	{
		return 0;
	}
	printf("\n");
    // Получение размера массива
    printf("Please, enter size of array < %d \n", MAX);
    int sizeOfArray = 0;
    scanf("%d", &sizeOfArray);
    // Создание массива
	int array[MAX];
    printf("Please, enter the members of your array\n");
    for (int i = 0; i < sizeOfArray; i++)
    {
        scanf("%d", &array[i]);
    }
	printf("The most frequent element is %d", elementCount(array, sizeOfArray));
    return 0;
}