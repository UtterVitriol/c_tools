#pragma once

struct Tree {
	struct Tree *parent;
	int key;
	struct Tree *left;
	struct Tree *right;
	int height;
};

struct Tree *create(int val);

struct Tree *insert(struct Tree *tree, int val);

struct Tree *search(struct Tree *tree, int val);

struct Tree *del(struct Tree *tree, int val);

void print_node(struct Tree *node);

void destroy(struct Tree *node);

void pre_order(struct Tree *tree, void (*fun)(struct Tree *));

void in_order(struct Tree *tree, void (*fun)(struct Tree *));

void post_order(struct Tree *tree, void (*fun)(struct Tree *));

void iter_post_order(struct Tree *tree, void (*fun)(struct Tree *));

void s_iter_post_order(struct Tree *tree, void (*fun)(struct Tree *));

void level_order(struct Tree *tree, void (*fun)(struct Tree *));

struct Tree *rotate_right(struct Tree *node);

struct Tree *rotate_left(struct Tree *node);

struct Tree *rotate_right_left(struct Tree *node);

struct Tree *rotate_left_right(struct Tree *node);

void avl_insert(struct Tree *node, int val);

void avl_del(struct Tree *node, int val);