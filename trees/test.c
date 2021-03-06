#include <stdio.h>
#include <stdlib.h>

#include "bin_tree.h"

int main(void)
{
	struct Tree *tree = create(5);

	// insert(tree, 1);
	// insert(tree, 5);
	// insert(tree, 3);
	// insert(tree, 6);
	// insert(tree, 4);

	avl_insert(tree, 6);
	avl_insert(tree, 3);
	avl_insert(tree, 7);
	avl_insert(tree, 4);
	avl_insert(tree, 2);
	avl_insert(tree, 123);
	avl_insert(tree, 1);
	avl_insert(tree, 9);
	avl_insert(tree, 8);
	avl_insert(tree, 10);

	avl_insert(tree, 5125);
	avl_insert(tree, 2125);
	avl_insert(tree, 1125);
	avl_insert(tree, 325);

	avl_insert(tree, 5126);
	avl_insert(tree, 5127);
	avl_insert(tree, 5128);

	avl_del(tree, 1125);
	avl_del(tree, 5127);
	// insert(tree, 9);
	// insert(tree, 8);

	// del(tree, 8);
	// level_order(tree, print_node);
	// puts("");
	// rotate_right(tree->right->left);
	// level_order(tree, print_node);
	// puts("");

	// rotate_left(tree->right);

	// insert(tree, 11);
	// insert(tree, 8);
	// insert(tree, 9);

	// insert(tree, 12);
	// insert(tree, 7);

	// insert(tree, 13);
	// insert(tree, 6);

	// insert(tree, 20);
	// insert(tree, 30);

	// del(tree, 20);

	// printf("val: %d\n", search(tree, 20)->key);

	// printf("val: %d\n", search(tree, 30)->key);

	in_order(tree, print_node);

	// iter_post_order(tree, print_node);
	// s_iter_post_order(tree, print_node);
	post_order(tree, destroy);
}