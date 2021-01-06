#pragma once

struct list
{
	int val;
	struct list *next;
};

int append(struct list **, int);

int prepend(struct list **, int);

int print(struct list *);

int free_list(struct list *);