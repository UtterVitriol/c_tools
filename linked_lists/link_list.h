#pragma once

struct node
{
	int val;
	struct node *next;
};

int create_new(struct node *, int);

struct node add(struct node, struct node *);

int swap(struct node *, int, int);