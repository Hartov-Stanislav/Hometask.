#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

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

void deleteElement(struct Stack** head)
{
	while (*head != NULL)
	{
		deleteTop(head);
	}
}

int main()
{
	char sequence[MAX];
	struct Stack* head = NULL;
	fgets(sequence, MAX, stdin);
	for (int i = 0; i < MAX; i++)
	{
		int temp;
		switch (sequence[i])
		{
		case ' ':
			break;
		case'*':
			head = addElement(head, '*');
			break;
		case'/':
			head = addElement(head, '/');
			break;
		case'+':
			if (isEmpty(head))
			{
				head = addElement(head, '+');
			}
			if (head->value == '*' || head->value == '/')
			{
				printf("%c ", deleteTop(&head));
			}
			head = addElement(head, '+');
			break;
		case'-':
			if (head->value == '*' || head->value == '/' && head !=NULL)
			{
				printf("%c ", deleteTop(&head));
			}
			head = addElement(head, '-');
			break;
		case'(':
			head = addElement(head, '(');
			break;
		case')':
			temp = deleteTop(&head);
			while (temp != '(')
			{
				printf("%c ", temp);
				temp = deleteTop(&head);
			}
			break;
		case'\n':
			temp = deleteTop(&head);
			while (temp != '(' || isEmpty(head))
			{
				printf("%c ", temp);
				if (isEmpty(head))
				{
					return 0;
				}
				else
				{
					printf("it isnt correct");
					deleteElement(&head);
					return 0;
				}
				deleteTop(&head);
			}
		default:
			printf("%c ", sequence[i]);
			break;
		}
	}
	return 0;
}