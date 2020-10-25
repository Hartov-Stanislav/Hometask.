#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define MAX 200

typedef struct ListElement {
	int value;
	struct ListElement* next;
} ListElement;

// Добавление элемента в список 
ListElement* addNewElementInList(ListElement* head, int element)
{
	ListElement* newElement = malloc(sizeof(ListElement));
	if (newElement == NULL)
	{
		return NULL;
	}
	newElement->value = element;
	newElement->next = head;
	head = newElement;
	return head;
}

// Удаление последнего элемента из списка
int deleteElement(ListElement** head)
{
	if (*head == NULL)
	{
		return NULL;
	}
	int element = (*head)->value;
	struct ListElement* oldElement = *head;
	*head = (*head)->next;
	free(oldElement);
	return element;
}

void delete(ListElement** head)
{
	if (*head == NULL)
	{
		return NULL;
	}
	int element = (*head)->value;
	struct ListElement* oldElement = *head;
	*head = (*head)->next;
	free(oldElement);
}

// Проверка списка на полноту
bool isEmpty(ListElement* head)
{
	return head == NULL;
}

// Полная очистка стека от списка
void deleteStack(ListElement** head)
{
	while (*head != NULL)
	{
		delete(head);
	}
}

// Функция сложения
ListElement* plus(ListElement** head)
{
	if (*head == NULL)
	{
		return NULL;
	}
	if ((*head)->next == NULL)
	{
		return NULL;
	}
	(*head)->next->value = (*head)->next->value + (*head)->value;
	ListElement*newHead = (*head)->next;
	free(*head);
	return newHead;
}

ListElement* minus(ListElement** head)
{
	if (*head == NULL)
	{
		return NULL;
	}
	if ((*head)->next == NULL)
	{
		return NULL;
	}
	(*head)->next->value =(*head)->next->value -(*head)->value;
	ListElement* newHead = (*head)->next;
	free(*head);
	return newHead;
}

ListElement* multiplication(ListElement** head)
{
	if (*head == NULL)
	{
		return NULL;
	}
	if ((*head)->next == NULL)
	{
		return NULL;
	}
	(*head)->next->value = (*head)->next->value * (*head)->value;
	ListElement* newHead = (*head)->next;
	free(*head);
	return newHead;
}

ListElement* division(ListElement** head)
{
	if (*head == NULL)
	{
		return NULL;
	}
	if ((*head)->next == NULL)
	{
		return NULL;
	}
	(*head)->next->value = (*head)->next->value / (*head)->value;
	ListElement* newHead = (*head)->next;
	free(*head);
	return newHead;
}

int main()
{
	printf("Please, enter sequence of numbers and arithmetic signs({+} {-} {*} {/})\n");
	printf("If you want to see result, please enter (=)\n");
	// Место где хранится запись
	char sequence[MAX];
	struct ListElement* head = NULL;
	// Получение записи
	fgets(sequence, MAX, stdin);	
	for (int i = 0; i < MAX; i++)
	{
		int balanceOfSigns = 0;
		int temp;
		switch (sequence[i])
		{
		case' ':
			break;
		case'*':
			balanceOfSigns++;
			if (balanceOfSigns < 0)
			{
				printf("wrong data");
				return 0;
			}
			head = multiplication(&head);
			break;
		case'/':
			balanceOfSigns++;
			if (balanceOfSigns < 0)
			{
				printf("wrong data");
				return 0;
			}
			temp = deleteElement(&head);
			if (temp == 0)
			{
				printf("wrong data (division by zero)\n");
				return 0;
			}
			addNewElementInList(head, temp);
			head = division(&head);
			break;
		case'+':
			balanceOfSigns++;
			if (balanceOfSigns >= 0)
			{
				printf("wrong data");
				return 0;
			}
			head = plus(&head);
			break;
		case'-':
			head = minus(&head);
			break;
		case'=':
			temp = deleteElement(&head);
			if (isEmpty(head))
			{
				printf("%d", temp);
				return 0;
			}
			else
			{
				printf("wrong data\n");
				deleteStack(&head);
				return 0;
			}
			break;
		default:
			head = addNewElementInList(head, sequence[i]- 48);
			break;
		}
	}
	return 0;
}