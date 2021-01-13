#include <stdio.h>
#include <stdlib.h>

#include "bin_tree.h"

int main(void)
{
	struct Tree *tree = create(10);

	insert(tree, 11);
	insert(tree, 8);
	insert(tree, 9);

	insert(tree, 12);
	insert(tree, 7);

	insert(tree, 13);
	insert(tree, 6);

	// del(tree, search(tree, 20));

	// printf("val: %d\n", search(tree, 20)->key);

	// printf("val: %d\n", search(tree, 30)->key);

	// level_order(tree, print_node);

	// iter_post_order(tree, print_node);
	s_iter_post_order(tree, print_node);
	post_order(tree, destroy);
}