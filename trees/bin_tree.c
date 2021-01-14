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
	new->height = 1;

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

struct Tree *insert(struct Tree *tree, int val)
{
	struct Tree *new = create(val);

	new = insert_loop(tree, new);

	if (new->parent == NULL) {
		free(new);
		return NULL;
	} else {
		return new;
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

struct Tree *del(struct Tree *tree, int val)
{
	struct Tree *new = search(tree, val);

	if (new == NULL) {
		return NULL;
	}

	struct Tree *parent = new->parent;

	// if (new->right == NULL && new->left == NULL) {
	// 	if (new->parent->left == new) {
	// 		new->parent->left = NULL;
	// 	} else {
	// 		new->parent->right = NULL;
	// 	}
	// 	destroy(new);
	// 	return;
	// }

	struct Tree *min = NULL;

	if (new->right == NULL) {

		if (new->parent->left == new) {
			new->parent->left = new->left;
		} else {
			new->parent->right = new->left;
		}

		if (new->left != NULL) {
			new->left->parent = new->parent;
		}

		destroy(new);
		return parent;
	}

	// check for null was already done above ^^^^^^^
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

	parent = min->parent;
	free(min);
	return parent;
}

void print_node(struct Tree *node)
{
	printf("Val: %d\n", node->height);
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
	pre_order(tree->left, fun);
	pre_order(tree->right, fun);
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
	in_order(tree->left, fun);
	fun(tree);
	in_order(tree->right, fun);
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

struct Tree *rotate_right(struct Tree *node)
{
	if (!node || !node->parent || (node == node->parent->right)) {
		return node;
	}

	struct Tree *p = NULL;
	struct Tree *pp = NULL;
	struct Tree *c = NULL;

	p = node->parent;
	pp = p->parent;
	c = node->right;
	node->parent = pp;
	node->right = p;
	p->parent = node;
	p->left = c;
	c->parent = p;

	if (node->key > pp->key) {
		pp->right = node;
	} else {
		pp->left = node;
	}

	return node;
}

struct Tree *rotate_left(struct Tree *node)
{
	struct Tree *p = NULL;
	struct Tree *pp = NULL;
	struct Tree *c = NULL;

	p = node->parent;

	pp = p->parent;

	c = node->left;
	node->parent = pp;
	node->left = p;
	p->parent = node;
	p->right = c;

	if (c) {
		c->parent = p;
	}

	if (pp) {
		if (node->key > pp->key) {
			pp->right = node;
		} else {
			pp->left = node;
		}
	}

	return node;
}

struct Tree *rotate_right_left(struct Tree *node)
{
	return rotate_left(rotate_right(node));
}

struct Tree *rotate_left_right(struct Tree *node)
{
	return rotate_right(rotate_left(node));
}

void avl_insert(struct Tree *node, int val)
{
	node = insert(node, val);

	int bf = 0;

	int temp = 0;

	node->height = 1;

	while (node->parent && bf <= 1) {
		node = node->parent;

		if (!node->right && node->left) {
			bf = node->left->height;
		} else if (!node->left && node->right) {
			bf = node->right->height;
		} else {
			bf = abs(node->right->height - node->left->height);
		}

		if (!node->right && node->left) {
			temp = node->left->height + 1;
		} else if (!node->left && node->right) {
			temp = node->right->height + 1;
		} else if (node->right->height > node->left->height) {
			temp = node->right->height + 1;
		} else {
			temp = node->left->height + 1;
		}
		node->height = temp;
	}

	if (!node->parent || bf <= 1) {
		return;
	}

	if (val < node->key) {
		if (val < node->left->key) {
			node = rotate_right(node->left);
			node->right->height = node->height - 1;
		} else {
			node = rotate_left_right(node->left->right);
			node->left->height = node->height;
			node->right->height = node->height;
			node->height = node->height + 1;
		}
	} else {
		if (val > node->right->key) {
			node = rotate_left(node->right);
			node->left->height = node->height - 1;
		} else {
			node = rotate_right_left(node->right->left);
			node->left->height = node->height;
			node->right->height = node->height;
			node->height = node->height + 1;
		}
	}
}

void avl_del(struct Tree *node, int val)
{
	struct Tree *i = del(node, val);

	if (!i) {
		return;
	}

	int bf = 0;

	int temp = 0;

	node->height = 1;

	while (node->parent && bf <= 1) {
		node = node->parent;
		bf = abs(node->right->height - node->left->height);

		if (node->right->height > node->left->height) {
			temp = node->right->height + 1;
		} else {
			temp = node->left->height + 1;
		}
		node->height = temp;
	}

	if (!node->parent || bf <= 1) {
		return;
	}

	if (i->key < node->key) {
		if (i->key < node->left->key) {
			node = rotate_right(node->left);
			node->right->height = node->height - 1;
		} else {
			node = rotate_left_right(node->left->right);
			node->left->height = node->height;
			node->right->height = node->height;
			node->height = node->height + 1;
		}
	} else {
		if (i->key > node->right->key) {
			node = rotate_left(node->right);
			node->left->height = node->height - 1;
		} else {
			node = rotate_right_left(node->right->left);
			node->left->height = node->height;
			node->right->height = node->height;
			node->height = node->height + 1;
		}
	}
}