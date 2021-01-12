#include <stdio.h>
#include <stdlib.h>

#include "bin_tree.h"

int main(void)
{
	struct Tree *tree = create(10);

	insert(tree, 20);

	insert(tree, 30);

	del(tree, search(tree, 20));

	// printf("val: %d\n", search(tree, 20)->key);

	// printf("val: %d\n", search(tree, 30)->key);

	post_order(tree, destroy);
}