//https://www.geeksforgeeks.org/linked-list-set-2-inserting-a-node/
#include <stdio.h>
#include <stdlib.h>

#include "link_list.h"

int append(struct list **list, int val)
{
	struct list *new = NULL;

	if ((new = malloc(sizeof(struct list))) == NULL)
	{
		return 0;
	}

	struct list *pos = *list;

	new->val = val;
	new->next = NULL;

	if (*list == NULL)
	{
		*list = new;
		return 1;
	}

	while (pos->next != NULL)
	{
		pos = pos->next;
	}

	pos->next = new;

	return 1;
}

int prepend(struct list **list, int val)
{
	struct list *new = NULL;

	if ((new = malloc(sizeof(struct list))) == NULL)
	{
		return 0;
	}

	new->val = val;
	new->next = *list;

	*list = new;

	return 1;
}

int insert(struct list *pos, int val)
{
	if (pos == NULL)
	{
		return -1;
	}

	struct list *new = NULL;

	if ((new = malloc(sizeof(struct list))) == NULL)
	{
		return 0;
	}

	new->val = val;
	new->next = pos->next;

	pos->next = new;
}

int print(struct list *list)
{
	while (list != NULL)
	{
		printf("%d\n", list->val);

		list = list->next;
	}

	return 1;
}

int free_list(struct list *list)
{
	struct list *temp = NULL;

	while (list != NULL)
	{
		temp = list->next;
		free(list);
		list = temp;
	}

	return 1;
}
