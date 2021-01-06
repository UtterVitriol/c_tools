#include <stdio.h>
#include <stdlib.h>

#include "link_list.h"

int main(void)
{
	struct list *new = NULL;

	append(&new, 10);
	append(&new, 1555);
	prepend(&new, 69);

	print(new);
	puts("Heh?");
	print(new);

	free_list(new);
}