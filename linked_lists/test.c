#include <stdio.h>
#include <stdlib.h>

#include "link_list.h"

int main(void)
{
	puts("test");
	struct node *head = NULL;
	create_new(head, 69);

	printf("hear: %d", head->val);
}