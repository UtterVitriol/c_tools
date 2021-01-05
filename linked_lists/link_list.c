#include <stdio.h>
#include <stdlib.h>

#include "link_list.h"

int create_new(struct node *new, int val)
{
	new = malloc(sizeof(struct node));

	new->val = val;
	new->next = NULL;

	return 1;
}

struct node add(struct node list, struct node *new)
{
	while (list.next != NULL)
	{
		list = *list.next;
	}
}

int swap(struct node *list, int val1, int val2)
{
	return 1;
}