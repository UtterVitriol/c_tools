#pragma once

struct d_list
{
	struct d_list *prev;
	int val;
	struct d_list *next;
};

int list_new(struct d_list **, int);

int list_append(struct d_list **, int);

int list_prepend(struct d_list **, int);

int list_insert(struct d_list **d_list, int pos, int val);

int list_xappend(struct d_list *);

int list_xprepend(struct d_list **);

int list_remove(struct d_list **d_list, int pos);

int list_print(struct d_list *);

int list_free(struct d_list *);

int list_size(struct d_list *d_list);