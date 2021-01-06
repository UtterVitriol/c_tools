#pragma once

struct array_2d{
    // simple 2d array

    int len; // number of strings in arrays
    char **arrays;
};

// functions specific to array_2d struct
int malloc_array_2d(struct array_2d *, int);
int print_array_2d(char *, struct array_2d *);
int free_array_2d(struct array_2d *);

// other useful functions
int get_input(char *, int);
char *int_from_str(char *, int *);
