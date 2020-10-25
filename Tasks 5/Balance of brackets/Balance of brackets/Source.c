#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 200

struct Stack
{
	int value;
	struct Stack* next;
};

struct Stack* addElement(struct Stack* head, int element)
{
	struct Stack* newElement = malloc(sizeof(struct Stack));
	if (newElement == NULL)
	{
		return 0;
	}
	newElement->next = head;
	newElement->value = element;
	head = newElement;
	return head;
}

int deleteTop(struct Stack** head)
{
	if (*head == NULL)
	{
		return NULL;
	}
	int temp = (*head)->value;
	struct Stack* oldElement = *head;
	*head = oldElement->next;
	free(oldElement);
	return temp;
}

bool isEmpty(struct Stack* head)
{
	return head == NULL;
}

void deleteStack(struct Stack** head)
{
	while (*head != NULL)
	{
		deleteTop(head);
	}
}
int main()
{
	struct Stack* head = NULL;
	char sequence[MAX];
	fgets(sequence, MAX, stdin);
	for (int i = 0; i < MAX; i++)
	{
		int temp;
		switch (sequence[i])
		{
		case'(':
			head = addElement(head, 1);
			break;
		case')':
			temp = deleteTop(&head);
			if (temp == 1)
			{
			}
			else
			{
				printf("it isnt correct");
				return 0;
			}
			break;
		case'{':
			head = addElement(head, 2);
			break;
		case'}':
			temp = deleteTop(&head);
			if (temp == 2)
			{
			}
			else
			{
				printf("it isnt correct");
				return 0;
			}
			break;
		case'[':
			head = addElement(head, 3);
			break;
		case']':
			temp = deleteTop(&head);
			if (temp == 3)
			{
			}
			else
			{
				printf("it isnt correct");
				return 0;
			}
			break;
		case'\n':
			if (isEmpty(head))
			{
				printf("it is correct");
				return 0;
			}
			else
			{
				printf("it isnt correct");
				return 0;
			}
			return 0;
			break;
		default:
			break;
		}
	}
	return 0;
}