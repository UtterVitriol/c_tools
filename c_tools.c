#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "c_tools.h"


int main(void)
{
    // testing
    int num = 0;
    char test[] = "123this456just789works101017";
    char *pEnd = NULL;
    pEnd = test;

    while(*pEnd){
        pEnd = int_from_str(pEnd, &num);
        printf("%d\n", num);
    }

        struct array_2d my_array;

    my_array.len = 3;

    malloc_array_2d(&my_array, 5);

    for (int i = 0; i < my_array.len; i++){
        strcpy(my_array.arrays[i], "Test");
    }

    print_array_2d(&my_array);
    free_array_2d(&my_array);
}

int get_input(char *buffer, int len)
{
	// get user input and drain stdin

	char dumpster[10] = {'\0'};

	if(fgets(buffer, len, stdin) == NULL){
		return 1;
	}

	if(!strchr(buffer, '\n')){
		while(!strchr(dumpster, '\n')){
			if(fgets(dumpster, 10, stdin) == NULL){
				return 1;
			}
		}
	}

	return 0;
}

int malloc_array_2d(struct array_2d *array, int max_string_len)
{
    array->arrays = malloc(array->len * sizeof(char*));

    for (int i = 0; i < array->len; i++){
        if((array->arrays[i] = malloc(max_string_len * sizeof(char))) == NULL){
            return 1;
        }
    }

    return 0;
}

int print_array_2d(struct array_2d *array)
{
    // prints array_2d
    for(int i = 0; i < array->len; i++){
		printf("%s\n", array->arrays[i]);
	}

    return 0;       
}

int free_array_2d(struct array_2d *array)
{
	// frees array_2d

	for(int i = 0; i < array->len; i++){
		free(array->arrays[i]);
	}

	free(array->arrays);

	return 0;
}

char  *int_from_str(char *string_ptr, int *number)
{
    // gets int from string
    // returns a pointer to the position in the string after the last number aquired

    char *position = NULL;
    position = string_ptr;
    while(*position){
        if(isdigit(*position)){
            *number = strtol(position, &position, 10);
            return position;
        }else{
            position++;
        }
    }
}