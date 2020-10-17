#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

// Выполненяем сложение столбиком
void sumArrays(int arrayFirst[], int arraySecond[])
{
	for (int i = 7; i >= 0; i--)
	{
		if (arrayFirst[i] + arraySecond[i] >= 2 && i != 0)
		{
			arrayFirst[i - 1] ++;
		}
		arrayFirst[i] = (arrayFirst[i] + arraySecond[i]) % 2;
	}
}

// Распаковка
void unpacking(int const number, int* arrayNumber)
{
	if (number < 0)
	{
		arrayNumber[0] = 1;
		int temp = abs(number);
		for (int i = 7; i >= 1; i--)
		{
			arrayNumber[i] = abs(temp % 2 - 1);
			temp /= 2;
		}
		int* arrayOne = (int*)calloc(8, sizeof(int));
		arrayOne[7] = 1;
		sumArrays(arrayNumber, arrayOne);
		free(arrayOne);
	}
	else
	{
		arrayNumber[0] = 0;
		int temp = abs(number);
		for (int i = 7; i >= 1; i--)
		{
			arrayNumber[i] = temp % 2;
			temp /= 2;
		}
	}
}

// Запаковка
int packing(int array[])
{
	int answer = 0;
	int temp = 1;
	for (int i = 7; i > 0; i--)
	{
		answer += temp * array[i];
		temp *= 2;
	}
	if (array[0] == 1)
	{
		return answer * -1;
	}
	else
	{
		return answer;
	}
}

// Вывод массива
void showingArray(int array[], int sizeOfArray)
{
	for (int i = 0; i < sizeOfArray; i++)
	{
		printf("%d", array[i]);
	}
	printf("\n");
}

int main()
{
	setlocale(LC_ALL, ".1251");
	printf("Введите два целых числа, по модулю меньше чем 127\n");
	// Ввод чисел
	int firstNumber = 0;
	int secondNumber = 0;
	scanf("%d", &firstNumber);
	scanf("%d", &secondNumber);
	// Создание массива для первого числа
	int* arrayFirstNumber = (int*)malloc(sizeof(int) * 8);
	unpacking(firstNumber, arrayFirstNumber, 8);
	showingArray(arrayFirstNumber, 8);
	// Создание массива для второго числа
	int* arraySecondNumber = (int*)malloc(sizeof(int) * 8);
	unpacking(secondNumber, arraySecondNumber, 8);
	showingArray(arraySecondNumber, 8);
	// Сложение столбиком
	sumArrays(arrayFirstNumber, arraySecondNumber);
	showingArray(arrayFirstNumber, 8);
	free(arraySecondNumber);
	printf("%d", packing(arrayFirstNumber));
	free(arrayFirstNumber);
	return 0;
}