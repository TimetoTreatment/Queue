//#include <stdio.h>
//#include <stdlib.h>
//#include "Elistqueue.h"
//
//
//void LQiniti(LQueue** head, LQueue** tail)
//{
//	*head = (LQueue*)malloc(sizeof(LQueue));
//	if (*head == NULL)
//	{
//		printf("Memory Error : \"LQiniti\\head\"");
//		exit(-1);
//	}
//	*tail = (LQueue*)malloc(sizeof(LQueue));
//	if (*head == NULL)
//	{
//		printf("Memory Error : \"LQiniti\\tail\"");
//		exit(-1);
//	}
//
//	(*head)->next = *tail;
//	(*head)->prev = *tail;
//	(*tail)->prev = *head;
//	(*tail)->next = *head;
//}
//
//void LQpush(LQueue* tail, DATA data)
//{
//	LQueue* newnode = (LQueue*)malloc(sizeof(LQueue));
//	if (newnode == NULL)
//	{
//		printf("Memory Error : \"LQpush\\newnode\"");
//		exit(-1);
//	}
//
//	newnode->item = data;
//	newnode->prev = tail->prev;
//	newnode->next = tail;
//	tail->prev->next = newnode;
//	tail->prev = newnode;
//}
//
//
//DATA LQpop(LQueue* head)
//{
//	DATA data = head->next->item;
//
//	head->next = head->next->next;
//	free(head->next->prev);
//
//	head->next->prev = head;
//
//	return data;
//}
//
