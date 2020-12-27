#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "c_tools.h"


int main(void)
{
    // testingss

    char string[10] = {0};

    get_input(string, 10);

    printf("%s", string);
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

int int_from_str(char *string, int *number, char *pEnd)
{
    // gets int from string
    // pEnd is a pointer to the position in the string after the last integer found

    pEnd = string;    
    while(*pEnd){
        if(isdigit(*pEnd)){
            *number = strtol(pEnd, &pEnd, 10);
            return 0;
        }else{
            pEnd++;
        }
    }
    return 1;
}