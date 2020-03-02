#include <stdio.h>
#include <stdlib.h>

typedef int DATA;
// ~def ___ DATA;

typedef struct _ListQueue
{
	DATA item;
	struct _ListQueue* prev;
	struct _ListQueue* next;

} LQueue;


void LQiniti(LQueue** head, LQueue** tail);
void LQpush(LQueue* tail, DATA data);
DATA LQpop(LQueue* head);


void LQiniti(LQueue** head, LQueue** tail)
{
	*head = (LQueue*)malloc(sizeof(LQueue));
	if (*head == NULL)
	{
		printf("Memory Error : \"LQiniti\\head\"");
		exit(-1);
	}
	*tail = (LQueue*)malloc(sizeof(LQueue));
	if (*head == NULL)
	{
		printf("Memory Error : \"LQiniti\\tail\"");
		exit(-1);
	}

	(*head)->next = *tail;
	(*head)->prev = *tail;
	(*tail)->prev = *head;
	(*tail)->next = *head;
}

void LQpush(LQueue* tail, DATA data)
{
	LQueue* newnode = (LQueue*)malloc(sizeof(LQueue));
	if (newnode == NULL)
	{
		printf("Memory Error : \"LQpush\\newnode\"");
		exit(-1);
	}

	newnode->item = data;
	newnode->prev = tail->prev;
	newnode->next = tail;
	tail->prev->next = newnode;
	tail->prev = newnode;
}


DATA LQpop(LQueue* head)
{
	DATA data = head->next->item;

	head->next = head->next->next;
	free(head->next->prev);

	head->next->prev = head;

	return data;
}

DATA LQpop_target(LQueue* target)
{
	DATA data = target->item;

	target->prev->next = target->next;
	target->next->prev = target->prev;

	free(target);

	return data;
}

int main(void)
{
	int i;
	int n, k;
	int size;
	LQueue* head;
	LQueue* tail;
	LQueue* plq;
	LQueue* next;


	scanf("%d %d", &n, &k);

	LQiniti(&head, &tail);
	size = n;

	head->item = 1;
	for (i = 2; i < n; i++)
	{
		LQpush(tail, i);
	}
	tail->item = n;

	printf("<");
	for (i = 1, plq = head; size > 1; i++)
	{
		next = plq->next;

		if (i % k == 0)
		{
			next = plq->next;
			printf("%d, ", LQpop_target(plq));
			size--;
		}

		plq = next;
	}

	printf("%d>", LQpop_target(plq));


	return 0;
}