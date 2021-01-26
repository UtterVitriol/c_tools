// inspiration from https://www.geeksforgeeks.org/graph-and-its-representations/
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "graph.h"

int main(void)
{
	FILE *fp = fopen("small.txt", "r");
	u64 s = 0;
	char *line = NULL;
	// char *endptr = NULL;
	char *word = NULL;
	char c = '\0';
	u64 src = 0;
	u64 dst = 0;

	fseek(fp, -1, SEEK_END);

	c = fgetc(fp);

	if (c == '\n') {
		fseek(fp, -2, SEEK_END);
		c = fgetc(fp);
	}

	while (c != '\n') {
		fseek(fp, -2, SEEK_CUR);
		c = fgetc(fp);
	}

	if (getline(&line, &s, fp) < 1) {
		puts("oops");
	}

	word = strtok(line, " \n");
	src = word[0];

	Graph *graph = init_graph(src + 1);

	rewind(fp);

	while (getline(&line, &s, fp) > 0) {
		if (line[0] == ' ') {
			continue;
		}

		word = strtok(line, " \n");
		src = word[0]; // strtol(word, &endptr, 10);
		// printf("%c ", src);

		word = strtok(NULL, " \n");
		dst = word[0]; // strtol(word, &endptr, 10);
			       // printf("%c\n", src);

		addEdge(graph, src, dst);
	}

	print_graph(graph);

	if (line) {
		free(line);
	}

	fclose(fp);
}

Graph *init_graph(u64 size)
{
	Graph *new = malloc(sizeof(Graph));

	new->v = size;
	new->array = calloc(size, sizeof(A_List));

	return new;
}

Node *create_node(int dest)
{
	Node *new = malloc(sizeof(Node));
	new->dest = dest;
	new->next = NULL;

	return new;
}

void addEdge(Graph *graph, int src, int dst)
{
	if (graph->array[src].head == NULL) {
		graph->array[src].head = create_node(dst);
		return;
	}

	Node *new = create_node(dst);

	new->next = graph->array[src].head;
	graph->array[src].head = new;
}

void destroy_list(Node *node)
{
	if (node->next) {
		destroy_list(node->next);
	}

	free(node);
}

void print_graph(Graph *graph)
{
	Node *node = NULL;
	int v = 97;

	for (; v < graph->v; v++) {
		node = graph->array[v].head;
		if (node) {
			printf("%c", v);
			while (node) {
				printf(" -> %c", node->dest);
				node = node->next;
			}
			puts("");
		}
	}
}