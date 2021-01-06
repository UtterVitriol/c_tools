//https://www.geeksforgeeks.org/linked-list-set-2-inserting-a-node/
#include <stdio.h>
#include <stdlib.h>

#include "link_list.h"

int list_new(struct list **list, int val)
{
	struct list *new = NULL;

	new = malloc(sizeof(struct list));

	new->val = val;
	new->next = NULL;

	*list = new;

	return 1;
}

int list_append(struct list **list, int val)
{
	// add static pointer to end???
	struct list *new = NULL;

	new = malloc(sizeof(struct list));

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

int list_prepend(struct list **list, int val)
{
	struct list *new = NULL;

	new = malloc(sizeof(struct list));

	new->val = val;
	new->next = *list;

	*list = new;

	return 1;
}

int list_insert(struct list **list, int place, int val)
{
	struct list *new = NULL;
	new = malloc(sizeof(struct list));
	new->val = val;

	if (place == 0)
	{
		new->next = *list;
		*list = new;
		return 1;
	}

	struct list *pos = *list;

	for (int i = 1; i < place; i++)
	{
		if (pos->next == NULL)
		{
			return 0;
		}
		pos = pos->next;
	}

	new->next = pos->next;
	pos->next = new;

	return 1;
}

int list_xappend(struct list *list)
{
	struct list *last = NULL;

	while (list->next != NULL)
	{
		last = list;
		list = list->next;
	}

	last->next = NULL;

	free(list);

	return 1;
}

int list_xprepend(struct list **list)
{
	struct list *temp = *list;

	*list = temp->next;

	free(temp);

	return 1;
}

int list_remove(struct list **list, int pos)
{
	int count = 0;

	struct list *temp = *list;
	struct list *next = NULL;

	if (pos == 0)
	{
		list_xprepend(list);
		return 1;
	}

	while (count < pos - 1)
	{
		if (temp->next == NULL)
		{
			next = temp->next;
			temp->next = NULL;
			free(next);
			return 1;
		}
		temp = temp->next;

		count++;
	}

	next = temp->next;
	temp->next = temp->next->next;

	free(next);

	return 1;
}

int list_print(struct list *list)
{
	while (list != NULL)
	{
		printf("%d\n", list->val);

		list = list->next;
	}

	return 1;
}

int list_free(struct list *list)
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

int list_size(struct list *list)
{
	int size = 0;
	while (list->next != NULL)
	{
		list = list->next;
		size++;
	}

	return size;
}
