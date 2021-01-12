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

void del(struct Tree *tree, struct Tree *del);

void destroy(struct Tree *node);

void post_order(struct Tree *tree, void (*fun)(struct Tree *));
