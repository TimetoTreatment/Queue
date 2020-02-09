#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Earrayqueue.h"

void print_functions(void)
{
	char* list[10] = { "push X", "pop","size","isempty","isfull","peek","list","exit", "\0" };
	char** pc;

	for (pc = list; **pc; pc++)
	{
		printf("%s\n", *pc);
	}

	printf("\n");
}

void debug(void)
{
	int n;
	int item;
	char cmd[6];
	AQueue qu[1];


	print_functions();

	printf("Queue Size : ");
	scanf("%d", &n);
	getchar();

	AQiniti(qu, n);

	for (;;)
	{
		printf("$ ");
		scanf("%s", cmd);

		if (strcmp(cmd, "push") == 0)
		{
			scanf("%d", &item);
			getchar();

			AQpush(qu, item);
		}

		if (strcmp(cmd, "pop") == 0)
		{
			printf("%d\n", AQpop(qu));
		}

		if (strcmp(cmd, "size") == 0)
		{
			printf("%d\n", AQsize(qu));
		}

		if (strcmp(cmd, "isempty") == 0)
		{
			printf("%d\n", AQisEmpty(qu));
		}

		if (strcmp(cmd, "isfull") == 0)
		{
			printf("%d\n", AQisFull(qu));
		}

		if (strcmp(cmd, "peek") == 0)
		{
			printf("%d\n", AQpeek(qu));
		}

		if (strcmp(cmd, "list") == 0)
		{
			AQlist(qu);
		}

		if (strcmp(cmd, "exit") == 0)
		{
			break;
		}
	}

	free(qu->item);
}