#include <stdio.h>
#include <stdlib.h>
#include "Earrayqueue.h"


void AQiniti(AQueue* qu, int max)
{
	qu->item = (DATA*)malloc(max * sizeof(DATA));
	if (qu == NULL)
	{
		printf("Error : Not enough Memory.\n");

		exit(-1);
	}

	qu->front = 0;
	qu->rear = 0;
	qu->size = 0;
	qu->max = max;
}

int AQisEmpty(AQueue* qu)
{
	if (qu->size == 0)
		return 1;

	return 0;
}

int AQisFull(AQueue* qu)
{
	if (qu->size == qu->max)
		return 1;

	return 0;
}

void AQpush(AQueue* qu, DATA data)
{
	if (AQisFull(qu) == 1)
	{
		printf("Error : Queue Overflow.\n");

		exit(-1);
	}

	qu->item[qu->rear] = data;
	qu->size++;
	qu->rear++;
	qu->rear %= qu->max;
}

DATA AQpop(AQueue* qu)
{
	if (AQisEmpty(qu) == 1)
	{
		printf("Error : Queue is Empty.\n");

		exit(-1);
	}

	DATA temp = qu->item[qu->front];
	qu->front = (qu->front+1) % qu->max;
	qu->size--;

	return temp;
}

DATA AQpeek(AQueue* qu)
{
	if (AQisEmpty(qu) == 1)
	{
		printf("Error : Queue is empty.\n");

		exit(-1);
	}

	return qu->item[qu->front];
}

int AQsize(AQueue* qu)
{
	return qu->size;
}

void AQlist(AQueue* qu)
{
	for (int i = qu->front; i < qu->front + qu->size; i++)
	{
		printf("%d\n", qu->item[i % qu->max]);
	}
}