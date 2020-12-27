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
    // pEnd is a pointer to the position in the string after the last integer found

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