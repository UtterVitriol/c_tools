#include <stdio.h>
#include <stdlib.h>

#include "link_list.h"

int main(void)
{
	struct d_list *new = NULL;

	list_new(&new, 1);

	list_append(&new, 3);

	list_insert(&new, 2, 69);

	list_print(new);

	puts("----");

	list_remove(&new, 2);

	list_print(new);

	list_free(new);

	/*
	struct d_list *new = NULL;

	struct d_list **last = &new;

	struct d_list *temp = NULL;

	int nums = 1000000;

	for (int i = 0; i < nums; i++)
	{
		list_append(last, i + 1);
		temp = *last;
		last = &temp->next;
	}

	//list_print(new);

	printf("Size: %d\n", list_size(new));

	list_free(new);
	*/
}