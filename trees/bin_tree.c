#include <stdio.h>
#include <stdlib.h>

#include "bin_tree.h"
#include "queue/queue_array.h"
#include "stack/stack_array.h"

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

void del(struct Tree *tree, int val)
{
	struct Tree *new = search(tree, val);

	if (new == NULL) {
		return;
	}
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

void print_node(struct Tree *node)
{
	printf("Val: %d\n", node->key);
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

void iter_post_order(struct Tree *tree, void (*fun)(struct Tree *))
{
	if (tree == NULL) {
		return;
	}
	struct Stack *p_stack = s_create(10);
	struct Stack *s_stack = s_create(10);

	s_push(s_stack, tree);

	while (s_size(s_stack) > 0) {
		tree = s_top(s_stack);
		s_pop(s_stack);

		if (tree->left != NULL) {
			s_push(s_stack, tree->left);
		}
		if (tree->right != NULL) {
			s_push(s_stack, tree->right);
		}

		s_push(p_stack, tree);
	}

	while (s_size(p_stack) > 0) {
		tree = s_top(p_stack);
		s_pop(p_stack);
		fun(tree);
	}

	s_destroy(p_stack);
	s_destroy(s_stack);
	return;
}

void s_iter_post_order(struct Tree *tree, void (*fun)(struct Tree *))
{
	if (tree == NULL) {
		return;
	}

	struct Stack *stack = s_create(10);
	while (1) {
		while (tree) {
			if (tree->right != NULL) {
				s_push(stack, tree->right);
			}
			s_push(stack, tree);
			tree = tree->left;
		}

		tree = s_top(stack);
		s_pop(stack);

		if (tree->right != NULL && tree->right == s_top(stack)) {
			s_pop(stack);
			s_push(stack, tree);
			tree = tree->right;
		} else {
			fun(tree);
			tree = NULL;
		}

		if (s_size(stack) == 0) {
			break;
		}
	}

	s_destroy(stack);
	return;
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

void level_order(struct Tree *tree, void (*fun)(struct Tree *))
{
	if (tree == NULL) {
		return;
	}

	Queue *queue = q_create(10);

	q_enqueue(queue, tree);

	while (queue->size > 0) {
		tree = q_front(queue);
		q_dequeue(queue);
		if (tree != NULL) {
			fun(tree);
			q_enqueue(queue, tree->left);
			q_enqueue(queue, tree->right);
		}
	}

	q_destroy(queue);
}