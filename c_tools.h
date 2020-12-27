#pragma once

struct array_2d{
    // simple 2d array

    int len; // number of strings in arrays
    char **arrays;
};

int get_input(char *, int);
int free_array_2d(struct array_2d *);
char *int_from_str(char *, int *);
int malloc_array_2d(struct array_2d *, int);
int print_array_2d(char *, struct array_2d *);