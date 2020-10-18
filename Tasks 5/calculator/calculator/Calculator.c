#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define MAX 200

typedef struct ListElement {
	int value;
	struct ListElement* next;
} ListElement;

// ���������� �������� � ������ 
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

// �������� ���������� �������� �� ������
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

// �������� ������ �� �������
bool isEmpty(ListElement* head)
{
	return head == NULL;
}

// ������ ������� ����� �� ������
void deleteStack(ListElement** head)
{
	while (*head != NULL)
	{
		delete(head);
	}
}

// ������� ��������
int plus(ListElement** head)
{
	if (*head == NULL)
	{
		return NULL;
	}
	(*head)->value = &(*head)->value + (*head)->value;
	deleteElement(head);
}

int main()
{
	printf("Please, enter sequence of numbers and arithmetic signs({+} {-} {*} {/})\n");
	printf("If you want to see result, please enter (=)\n");
	char sequence[MAX];
	struct StackElement* head = NULL;
	fgets(sequence, MAX, stdin);
	for (int i = 0; i < MAX; i++)
	{
		char temp;
		switch (sequence[i])
		{
		case' ':
			break;
		case'�':
			return 0;
		case'\n':
			break;
		case'*':
			break;
		case'/': 
			break;
		case'+': 
			plus(&head);
			break;
		case'-':
			break;
		case'=':
			printf("%d", deleteElement(&head));
			break;
		default: 
			temp = sequence[i] - '0';
			addNewElementInList(head, temp);
			break;
		}
	}
	return 0;
}