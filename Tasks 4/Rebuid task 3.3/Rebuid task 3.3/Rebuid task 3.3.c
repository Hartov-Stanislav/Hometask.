#include "sort.h"

#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

// Функция просто пробегает по массиву и исчет наиболее часто встречаемые элементы
int searchFrequentElement(int* array, int sizeOfArray)
{
	qSort(array, 0, sizeOfArray - 1);
	int temp = array[0];
	int counter = 1;
	int counterMax = 1;
	for (int i = 1; i < sizeOfArray; i++)
	{
		if (array[i] == array[i-1])
		{
			counter++;
		}
		else
		{
			if (counterMax < counter)
			{
				counterMax = counter;
				temp = array[i - 1];
			}
			counter = 1;
		}
		if (i == sizeOfArray - 1 && counterMax < counter)
		{
			counterMax = counter;
			temp = array[i - 1];
		}
	}
	int answer = temp;
	return answer;
}

// Тесты

// Тест с одним элементом в массиве
int testWithOneElement()
{
	int array[1] = { 1 };
	return searchFrequentElement(array, 1) == 1;
}

// Тест с несколькими вариантами ответа
int testWithMoreThanOneAnswers()
{
	int array[] = { 1, 3, 2, 5, 3, 1, 2, 3, 1, 2, 5, 7 };
	return (searchFrequentElement(array, 12) == 1 || searchFrequentElement(array, 12) == 2 || searchFrequentElement(array, 12) == 3);
}

// Тест в массиве из одинаковых элементов
int testWithEqualElements()
{
	int* array = (int*)calloc(MAX, sizeof(int));
	int answer = (searchFrequentElement(array, MAX));
	free(array);
	return answer == 0;
}

// Функция для прохождения теста
int checkTest(int test)
{
	if (test == 0)
	{
		printf("Test failed\n");
		return 0;
	}
	else
	{
		printf("Test completed\n");
		return 1;
	}
}

// Функция для прохождения тестов
int checkTests()
{
	int completedTests = 0;
	printf("Test with 1 element \n");
	completedTests += checkTest(testWithOneElement());
	printf("Test with equal elements \n");
	completedTests += checkTest(testWithEqualElements());
	printf("Usual test \n");
	completedTests += checkTest(testWithMoreThanOneAnswers());
	return completedTests;
}

int main()
{
	if (checkTests() < 3)
	{
		return 0;
	}
	printf("\n");
	FILE* input = fopen("input.txt", "r"); 
	if (input == NULL) 
	{ 
		return -1;
	}
	// Получение размера массива
	int sizeOfArray = 0;
	fscanf(input,"%d", &sizeOfArray);
	// Создание массива
	int array[MAX];
	// Получение членов последовательности
	for (int i = 0; i < sizeOfArray; i++)
	{
		fscanf(input,"%d", &array[i]);
	}
	fclose(input);
	printf("The most frequent element is %d", searchFrequentElement(array, sizeOfArray));
	return 0;
}