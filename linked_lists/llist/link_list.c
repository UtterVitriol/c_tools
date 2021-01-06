//https://www.geeksforgeeks.org/linked-list-set-2-inserting-a-node/
#include <stdio.h>
#include <stdlib.h>

#include "link_list.h"

int list_new(struct d_list **list, int val)
{
	struct d_list *new = NULL;

	new = malloc(sizeof(struct d_list));

	new->prev = NULL;
	new->val = val;
	new->next = NULL;

	*list = new;

	return 1;
}

int list_append(struct d_list **list, int val)
{
	// add static pointer to end???
	struct d_list *new = NULL;

	new = malloc(sizeof(struct d_list));

	struct d_list *pos = *list;

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

	new->prev = pos;
	pos->next = new;
	return 1;
}

int list_prepend(struct d_list **list, int val)
{
	struct d_list *new = NULL;

	new = malloc(sizeof(struct d_list));

	new->prev = NULL;
	new->val = val;
	new->next = *list;

	*list = new;

	return 1;
}

int list_insert(struct d_list **list, int place, int val)
{
	struct d_list *new = NULL;
	new = malloc(sizeof(struct d_list));
	new->val = val;

	if (place == 0)
	{
		new->prev = NULL;
		new->next = *list;
		*list = new;
		return 1;
	}

	struct d_list *pos = *list;

	for (int i = 1; i < place; i++)
	{
		if (pos->next == NULL)
		{
			return 0;
		}
		pos = pos->next;
	}

	new->prev = pos;
	new->next = pos->next;
	pos->next = new;

	return 1;
}

int list_xappend(struct d_list *d_list)
{
	struct d_list *last = NULL;

	while (d_list->next != NULL)
	{
		last = d_list;
		d_list = d_list->next;
	}

	last->next = NULL;

	free(d_list);

	return 1;
}

int list_xprepend(struct d_list **d_list)
{
	struct d_list *temp = *d_list;

	*d_list = temp->next;

	free(temp);

	temp = *d_list;
	temp->prev = NULL;

	return 1;
}

int list_remove(struct d_list **d_list, int pos)
{
	int count = 0;

	struct d_list *temp = *d_list;
	struct d_list *next = NULL;

	if (pos == 0)
	{
		list_xprepend(d_list);
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
	next->prev = temp;

	free(next);

	return 1;
}

int list_print(struct d_list *d_list)
{
	while (d_list != NULL)
	{
		printf("%d\n", d_list->val);

		d_list = d_list->next;
	}

	return 1;
}

int list_free(struct d_list *d_list)
{
	struct d_list *temp = NULL;

	while (d_list != NULL)
	{
		temp = d_list->next;
		free(d_list);
		d_list = temp;
	}

	return 1;
}

int list_size(struct d_list *d_list)
{
	int size = 0;
	while (d_list->next != NULL)
	{
		d_list = d_list->next;
		size++;
	}

	return size;
}
