// inspiration from https://www.geeksforgeeks.org/graph-and-its-representations/
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "graph.h"
#include "queue/queue.h"

int main(void)
{
	FILE *fp = fopen("small.txt", "r");
	u64 s = 0;
	char *line = NULL;
	char *endptr = NULL;
	char *word = NULL;
	u64 src = 0;
	u64 dst = 0;

	u64 size = 0;

	size = get_greatest(fp);

	Graph *graph = init_graph(size + 1);

	while (getline(&line, &s, fp) > 0) {
		if (line[0] == ' ') {
			continue;
		}

		word = strtok(line, " \t\n");
		src = strtol(word, &endptr, 10);

		word = strtok(NULL, " \t\n");
		dst = strtol(word, &endptr, 10);

		add_edge(graph, src, dst);
	}

	// print_graph(graph);
	// breadth_first(graph, graph->array[4038], 4038);
	printf("Number of triangles: %lu\n", triangle_count(graph) / 6);
	destroy_graph(graph);

	if (line) {
		free(line);
	}

	fclose(fp);
}

u64 get_greatest(FILE *fp)
{
	char *word = NULL;
	char *line = NULL;
	char *endptr = NULL;
	u64 greatest = 0;
	u64 temp = 0;
	size_t s = 0;

	while (getline(&line, &s, fp) > 0) {
		if (line[0] == ' ') {
			continue;
		}

		word = strtok(line, " \t\n");
		temp = strtol(word, &endptr, 10);

		if (temp > greatest) {
			greatest = temp;
		}

		word = strtok(NULL, " \t\n");
		temp = strtol(word, &endptr, 10);

		if (temp > greatest) {
			greatest = temp;
		}
	}

	if (line) {
		free(line);
	}

	rewind(fp);

	return greatest;
}

Graph *init_graph(u64 size)
{
	Graph *new = malloc(sizeof(Graph));

	new->v = size;
	new->array = calloc(size, sizeof(Node));

	for (u64 i = 0; i < size; i++) {
		new->array[i] = NULL;
	}

	return new;
}

Node *create_node(u64 dest)
{
	Node *new = malloc(sizeof(Node));
	new->dest = dest;
	new->next = NULL;

	return new;
}

void add_edge(Graph *graph, u64 src, u64 dst)
{
	Node *new = create_node(dst);
	new->next = graph->array[src];
	graph->array[src] = new;

	new = create_node(src);
	new->next = graph->array[dst];
	graph->array[dst] = new;
}

void destroy_graph(Graph *graph)
{
	for (u64 i = 0; i < graph->v; i++) {
		if (graph->array[i]) {
			destroy_list(graph->array[i]);
		}
	}

	free(graph->array);
	free(graph);
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
	u64 v = 0;

	for (; v < graph->v; v++) {
		node = graph->array[v];
		if (node) {
			printf("%lu", v);
			while (node) {
				printf(" -> %lu", node->dest);
				node = node->next;
			}
			puts("");
		}
	}
}

u64 triangle_count(Graph *graph)
{
	// only walk neighbors???
	uint8_t *arr = NULL;
	u64 count = 0;

	Node *temp = NULL;

	for (u64 i = 0; i < graph->v; i++) {
		arr = calloc(graph->v, sizeof(uint8_t));
		for (u64 j = i + 1; j < graph->v; j++) {
			temp = graph->array[i];
			while (temp) {
				arr[temp->dest] = 1;
				temp = temp->next;
			}

			temp = graph->array[j];
			while (temp) {
				if (arr[temp->dest]) {
					count++;
				}
				temp = temp->next;
			}
		}
		free(arr);
	}

	return count;
}

int breadth_first(Graph *graph, Node *node, u64 start)
{
	// change this to get node based on start value instead of providing it
	// in the function call
	time_t seconds1;
	time_t seconds2;

	seconds1 = time(NULL);
	puts("\n\n\n\n\n\n");
	u64 *visited = calloc(graph->v, sizeof(u64));
	Queue *q = create((graph->v * 2));

	u64 count = 0;
	enqueue(q, node);

	visited[start] = 1;
	printf("%lu -> %lu", start, node->dest);
	while (!empty(q)) {
		Node *temp = front(q);
		dequeue(q);

		while (temp) {
			count++;
			if (!visited[temp->dest]) {
				enqueue(q, graph->array[temp->dest]);
				visited[temp->dest] = 1;
				// printf(" -> %lu", temp->dest);
			}
			temp = temp->next;
		}
	}
	seconds2 = time(NULL);

	puts("");

	printf("Edges?: %lu\n", count);
	printf("Time: %lu\n", seconds2 - seconds1);
	free(visited);
	destroy(q);

	return 1;
}