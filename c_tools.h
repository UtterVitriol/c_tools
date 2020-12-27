#pragma once

struct array_2d{
    // simple 2d array data structure

    int len;
    char **arrays;
};

int get_input(char *, int);
int free_array_2d(struct array_2d *);
char *int_from_str(char *, int *);
int malloc_array_2d(struct array_2d *, int);
int print_array_2d(struct array_2d *);