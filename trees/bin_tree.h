#pragma once

struct Tree {
	struct Tree *parent;
	int key;
	struct Tree *left;
	struct Tree *right;
};

struct Tree *create(int val);

void insert(struct Tree *tree, int val);

struct Tree *search(struct Tree *tree, int val);

void del(struct Tree *tree, int val);

void print_node(struct Tree *node);

void destroy(struct Tree *node);

void post_order(struct Tree *tree, void (*fun)(struct Tree *));

void iter_post_order(struct Tree *tree, void (*fun)(struct Tree *));

void s_iter_post_order(struct Tree *tree, void (*fun)(struct Tree *));

void level_order(struct Tree *tree, void (*fun)(struct Tree *));
