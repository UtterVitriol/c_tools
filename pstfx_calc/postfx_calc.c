#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "stack_array_i.h"
#include "stack_array_c.h"

char *convert(char *arr);
int eval(char *arr);

int main(void)
{
	char arr[] = {"6+4(2*3-1)/5"};
	char *result = convert(arr);

	printf("%s\n", result);

	printf("Result: %d\n", eval(result));
	free(result);
}

char *convert(char *arr)
{
	char prio[] = {"()+-*/^"};
	int len = strlen(arr);

	int count = 0;
	char *result = calloc(len, sizeof(char));

	Stack_c *stack = c_create(len);

	for (int i = 0; i < len; i++) {
		if (isdigit(arr[i])) {
			result[count] = arr[i];
			count++;
			// printf("%c ", arr[i]);
			continue;
		}
		if (arr[i] == '(') {
			c_push(stack, '*');
			c_push(stack, arr[i]);
			continue;
		}
		if (arr[i] == ')') {
			while (c_size(stack) > 0) {
				if (c_top(stack) == '(') {
					c_pop(stack);
					break;
				}
				result[count] = c_top(stack);
				count++;
				// printf("%c \n", c_top(stack));
				c_pop(stack);
			}

			continue;
		}
		if (c_size(stack) == 0) {
			c_push(stack, arr[i]);
			continue;
		}

		if (strchr(prio, arr[i]) > strchr(prio, c_top(stack))) {
			c_push(stack, arr[i]);
		} else {
			while (strchr(prio, arr[i]) <
				   strchr(prio, c_top(stack)) &&
			       c_size(stack) > 0) {
				result[count] = c_top(stack);
				count++;
				// printf("%c ", top(stack));
				c_pop(stack);
			}
			c_push(stack, arr[i]);
		}
	}

	while (c_size(stack) > 0) {
		result[count] = c_top(stack);
		count++;
		// printf("%c ", top(stack));
		c_pop(stack);
	}

	// puts("");

	free(stack->stack);
	free(stack);

	return result;
}

int eval(char *arr)
{
	int len = strlen(arr);

	Stack_i *stack = i_create(len);

	int result = 0;

	int temp1 = 0;
	int temp2 = 0;

	for (int i = 0; i < len; i++) {
		if (isdigit(arr[i])) {
			i_push(stack, arr[i] - '0');
			continue;
		}

		temp1 = i_top(stack);
		i_pop(stack);
		temp2 = i_top(stack);
		i_pop(stack);

		switch (arr[i]) {
		case '*':
			i_push(stack, temp2 * temp1);
			continue;
		case '/':
			i_push(stack, temp2 / temp1);
			continue;
		case '+':
			i_push(stack, temp2 + temp1);
			continue;
		case '-':
			i_push(stack, temp2 - temp1);
			continue;
		}
	}
	result = i_top(stack);
	free(stack->stack);
	free(stack);
	return result;
}