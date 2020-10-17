#include <stdio.h>
#include <stdlib.h>

#define SIZEOFARRAY  1000
#define SIZEOFSEARCHARRAY  1000

// Сортировка Qsort
void qSort(int* array, int firstElement, int lastElement)
{
	if (firstElement >= lastElement)
	{
		return;
	}
	int i = firstElement;
	int j = lastElement;
	// Выбор "Рандомного" элемента из середины массива
	int middleElementInArray = array[(i + j) / 2];
	// Поделилим массив на две части так, что каждый элемент массива из первой части меньше любого элемента из второй
	do
	{
		while (array[i] < middleElementInArray)
		{
			i++;
		}
		while (array[j] > middleElementInArray)
		{
			j--;
		}
		if (i <= j)
		{
			int tempForSwap = array[i];
			array[i] = array[j];
			array[j] = tempForSwap;
			i++;
			j--;
		}
	} while (i <= j);
	// Аналогия для двух получившихся частей исходного массива и так делее
	qSort(array, firstElement, j);
	qSort(array, i, lastElement);
}

// Поиск за log(n)
int searchElementInArray(int* array, int firstPosition, int lastPosition, int number)
{
	int answer = 0;
	while (firstPosition <= lastPosition)
	{
		int middlePosition = (firstPosition + lastPosition) / 2;
		if (number == array[middlePosition])
		{
			answer = 1;
			break;
		}
		if (number > array[middlePosition])
		{
			firstPosition = middlePosition + 1;
		}
		if (number < array[middlePosition])
		{
			lastPosition = middlePosition - 1;
		}
	}
	return answer;
}

// Перевод (1/0) в текст
void searchPart2(int answer, int element)
{
	if (answer != 0)
	{
		printf("%d is in array\n", element);
	}
	else
	{
		printf("%d isn't in array\n", element);
	}
}

// Тесты

// Тест для поиска в массиве, состоящии из 1 элемента
int testWithOneElement()
{
	int array[1] = { 13 };
	int searchArray[] = { 13, 2, 3, 4 };
	int answerArray[] = { 1, 0, 0, 0 };
	qSort(array, 0, 0);
	int mistakes = 0;
	for (int i = 0; i < 4; i++)
	{
		if (searchElementInArray(array, 0, 0, searchArray[i]) != answerArray[i])
		{
			mistakes++;
			break;
		}
	}
	return 1 - mistakes;
}

// Тест для массива, состоящего из одинаковых элементов
int testEqualElements()
{
	int* array = (int*)calloc(50, sizeof(int));
	int searchArray[10] = { 12, 10, 9, 8, 0, 3, 4, 2, 1, 9 };
	int answerArray[10] = { 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 };
	qSort(array, 0, 9);
	int mistakes = 0;
	for (int i = 0; i < 10; i++)
	{
		if (searchElementInArray(array, 0, 0, searchArray[i]) != answerArray[i])
		{
			mistakes++;
			break;
		}
	}
	free(array);
	return 1 - mistakes;
}

// Тест обычная ситуация
int testUsualCase()
{
	int array[14] = { -7, 34, -7, -34, 2, 6, 98, -34, 90, -12, -1, 34, 9, 2 };
	int searchArray[20] = { 34, 7, -34, 2, 6, 120, 56, 2, 87, 9, 52, 13, 34, 2, 8, 4, -100, -7, 45, 65 };
	int answerArray[20] = { 1, 0, 1, 1, 1, 0, 0, 1, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0 };
	qSort(array, 0, 13);
	int mistakes = 0;
	for (int i = 0; i < 20; i++)
	{
		if (searchElementInArray(array, 0, 13, searchArray[i]) != answerArray[i])
		{
			mistakes++;
			break;
		}
	}
	return 1 - mistakes;
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
	int comletedTests = 0;
	printf("Test with 1 element \n");
	comletedTests += checkTest(testWithOneElement());
	printf("Test with equal elements \n");
	comletedTests += checkTest(testEqualElements());
	printf("Usual test \n");
	comletedTests += checkTest(testUsualCase());
	return comletedTests;
}

int main() {
	// Не даст ввести данные при провале хотя бы одного теста
	if (checkTests() < 3)
	{
		return 0;
	}
	printf("\n");
	// Ввод n
	printf("Please, enter n < %d (place for search)\n", SIZEOFARRAY);
	int sizeOfArray = 0;
	scanf("%d", &sizeOfArray);
	// Создание основного массива
	int array[SIZEOFARRAY];
	// Ввод k
	printf("Please, enter k < %d (ammount of numbers, which we will search)\n", SIZEOFSEARCHARRAY);
	int sizeOfSearchArray = 0;
	scanf("%d", &sizeOfSearchArray);
	// Создание массива чисел для поиска данных чисел в основном массиве
	int searchArray[SIZEOFSEARCHARRAY];
	// Заполнение основного массива
	for (int i = 0; i < sizeOfArray; i++)
	{
		array[i] = rand();
	}
	// Заполнение поискового массива
	for (int i = 0; i < sizeOfSearchArray; i++)
	{
		searchArray[i] = rand();
	}
	for (int i = 0; i < sizeOfArray; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
	for (int i = 0; i < sizeOfSearchArray; i++)
	{
		printf("%d ", searchArray[i]);
	}
	printf("\n");
	// Отсортирум основной массив
	qSort(array, 0, sizeOfArray - 1);
	for (int i = 0; i < sizeOfArray; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
	for (int i = 0; i < sizeOfSearchArray; i++)
	{
		searchPart2(searchElementInArray(array, 0, sizeOfArray - 1, searchArray[i]), searchArray[i]);
	}
	return 0;
}