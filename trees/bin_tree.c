#include <stdio.h>
#include <stdlib.h>

#include "bin_tree.h"

struct Tree *create(int val)
{
	struct Tree *new = malloc(sizeof(struct Tree));

	new->parent = NULL;
	new->left = NULL;
	new->right = NULL;
	new->key = val;

	return new;
}

struct Tree *insert_loop(struct Tree *tree, struct Tree *i)
{
	if (i->key == tree->key) {
		return i;
	}

	if (i->key < tree->key) {
		if (tree->left == NULL) {
			tree->left = i;
			i->parent = tree;
		}

		return insert_loop(tree->left, i);
	} else {
		if (tree->right == NULL) {
			tree->right = i;
			i->parent = tree;
		}
		return insert_loop(tree->right, i);
	}
}

void insert(struct Tree *tree, int val)
{
	struct Tree *new = create(val);

	insert_loop(tree, new);

	if (new->parent == NULL) {
		free(new);
	}
}

struct Tree *search(struct Tree *tree, int val)
{
	if (tree == NULL) {
		puts("Not found..");
		return tree;
	}
	if (val == tree->key) {
		return tree;
	}

	if (val < tree->key) {
		return search(tree->left, val);
	} else {
		return search(tree->right, val);
	}
}

void del(struct Tree *tree, struct Tree *del)
{
	if (del == NULL) {
		return;
	}
	struct Tree *new = del;
	struct Tree *min = NULL;

	if (new == NULL) {
		return;
	}
	if (new->right == NULL) {
		new->parent->left = new;

		if (new->left != NULL) {
			new->left->parent = new->parent;
		}

		destroy(new);
		return;
	}
	if (new->right != NULL) {
		min = new->right;
	} else {
		min = new;
	}

	while (min->left != NULL) {
		min = min->left;
	}

	new->key = min->key;

	if (new->right == min) {
		new->right = min->right;
	} else {
		min->parent->left = min->right;
	}

	free(min);
	return;
}

void destroy(struct Tree *node)
{
	free(node);
}

void post_order(struct Tree *tree, void (*fun)(struct Tree *))
{
	if (tree == NULL) {
		return;
	}
	post_order(tree->left, fun);
	post_order(tree->right, fun);

	fun(tree);
}

void pre_order(struct Tree *tree, void (*fun)(struct Tree *))
{
	if (tree == NULL) {
		return;
	}
	fun(tree);
	post_order(tree->left, fun);
	post_order(tree->right, fun);
}

void in_order(struct Tree *tree, void (*fun)(struct Tree *))
{
	if (tree == NULL) {
		return;
	}
	post_order(tree->left, fun);
	fun(tree);
	post_order(tree->right, fun);
}