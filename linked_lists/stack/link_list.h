#pragma once

struct list {
	int val;
	struct list *next;
};

int list_new(struct list **, int);

int list_append(struct list **, int);

int list_prepend(struct list **, int);

int list_insert(struct list **list, int pos, int val);

int list_xappend(struct list *);

int list_xprepend(struct list **);

int list_remove(struct list **list, int pos);

int list_print(struct list *);

int list_free(struct list *);

int list_size(struct list *list);