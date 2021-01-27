// inspiration from https://www.geeksforgeeks.org/graph-and-its-representations/
// https://www.geeksforgeeks.org/dijkstras-algorithm-for-adjacency-list-representation-greedy-algo-8/
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <limits.h>
#include <stdint.h>

#include "graph.h"
#include "queue/queue.h"
#include "stack/stack.h"
#include "min_heap/min_heap.h"

int main(void)
{
	FILE *fp = fopen("small.txt", "r");
	u64 s = 0;
	char *line = NULL;
	char *endptr = NULL;
	char *word = NULL;
	u64 src = 0;
	u64 dst = 0;
	u64 weight = 0;

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

		word = strtok(NULL, " \t\n");
		weight = strtol(word, &endptr, 10);

		add_edge(graph, src, dst, weight);
	}

	// print_graph(graph);
	// breadth_first(graph, graph->array[6], 6);
	// depth_first(graph, 0);
	// printf("Number of triangles: %lu\n", triangle_count(graph) / 6);
	dijkstra(graph, 6);
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

Node *create_node(u64 dest, u64 weight, u64 v)
{
	Node *new = malloc(sizeof(Node));
	new->dest = dest;
	new->weight = weight;
	new->v = v;
	new->next = NULL;

	return new;
}

void add_edge(Graph *graph, u64 src, u64 dst, u64 weight)
{
	Node *new = create_node(dst, weight, src);
	new->next = graph->array[src];
	graph->array[src] = new;

	new = create_node(src, weight, dst);
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

int depth_first(Graph *graph, u64 start)
{
	puts("\n\n\n\n\n\n");
	u64 *visited = calloc(graph->v, sizeof(u64));

	Stack *stack = stack_create((graph->v * 2));

	u64 count = 0;
	stack_push(stack, graph->array[start]);

	visited[start] = 1;
	printf("%lu -> %lu", start, graph->array[start]->dest);
	while (!stack_empty(stack)) {
		Node *temp = stack_top(stack);
		stack_pop(stack);

		while (temp) {
			count++;
			if (!visited[temp->dest]) {
				stack_push(stack, graph->array[temp->dest]);
				visited[temp->dest] = 1;
				printf(" -> %lu", temp->dest);
			}
			temp = temp->next;
		}
	}

	puts("");
	printf("Edges?: %lu\n", count);
	free(visited);
	stack_destroy(stack);

	return 1;
}

void print_path(u64 *p, u64 size, u64 start)
{
	printf("%lu\n", start);
	u64 temp = 0;
	for (u64 i = 0; i < size; i++) {
		if (i == start) {
			continue;
		}
		temp = p[i];
		printf("%lu <- ", i);
		while (temp != start) {
			printf("%lu <- ", temp);
			temp = p[temp];
		}
		printf("%lu\n", start);
	}

	printf("\n\nB: %lu\n", p[1]);
}

int breadth_first(Graph *graph, Node *node, u64 start)
{
	// change this to get node based on start value instead of providing it
	// in the function call
	time_t seconds1;
	time_t seconds2;

	u64 *p = calloc(graph->v, sizeof(u64));

	seconds1 = time(NULL);
	puts("\n\n\n\n\n\n");
	u64 *visited = calloc(graph->v, sizeof(u64));
	Queue *q = queue_create((graph->v * 2));

	u64 count = 0;
	queue_enqueue(q, node);

	visited[start] = 1;
	printf("%lu -> %lu", start, node->dest);
	while (!queue_empty(q)) {
		Node *temp = queue_front(q);
		queue_dequeue(q);

		while (temp) {
			count++;
			if (!visited[temp->dest]) {
				p[temp->dest] = temp->v;
				// parent array goes here....
				// parent of temp->dest is temp
				queue_enqueue(q, graph->array[temp->dest]);
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

	print_path(p, graph->v, start);

	free(p);
	free(visited);
	queue_destroy(q);

	return 1;
}

void decrease_key(Heap *heap, u64 v, u64 dist)
{
	int i = heap->pos[v];

	heap->array[i]->dist = dist;

	while (i && heap->array[i]->dist < heap->array[(i - 1) / 2]->dist) {
		heap->pos[heap->array[i]->v] = (i - 1) / 2;

		heap->pos[heap->array[(i - 1) / 2]->v] = i;

		Item *temp = NULL;

		temp = heap->array[i];
		heap->array[i] = heap->array[(i - 1) / 2];
		heap->array[(i - 1) / 2] = temp;

		i = (i - 1) / 2;
	}
}

void print_paths(u64 *dist, u64 n)
{
	puts("V Dist from Src");
	for (u64 i = 0; i < n; i++) {
		printf("%lu \t\t %lu\n", i, dist[i]);
	}
}

void dijkstra(Graph *graph, u64 start)
{
	u64 V = graph->v;

	u64 *dist = malloc(V * sizeof(u64));

	u64 *p = calloc(graph->v, sizeof(u64));

	Heap *heap = create_heap(V);

	for (u64 v = 0; v < V; v++) {
		dist[v] = ULONG_MAX;
		heap->array[v] = create_item(v, dist[v]);
		heap->pos[v] = v;
	}

	heap->array[start] = create_item(start, dist[start]);
	heap->pos[start] = start;
	dist[start] = 0;
	decrease_key(heap, start, dist[start]);

	heap->count = V;

	while (heap->count > 0) {
		Item *h_node = heap_extract(heap);

		u64 u = h_node->v;

		Node *crawl = graph->array[u];

		while (crawl) {
			u64 v = crawl->dest;

			// need to add weights.....
			if (/*isminheap(v)???*/ dist[u] != ULONG_MAX &&
			    crawl->weight + dist[u] < dist[v]) {
				dist[v] = dist[u] + crawl->weight;
				// parent array goes here.
				p[crawl->dest] = crawl->v;
				decrease_key(heap, v, dist[v]);
			}

			crawl = crawl->next;
		}
	}

	print_paths(dist, V);

	// free(heap->array);
	// free(heap);
	print_path(p, graph->v, start);
	free(p);
	free(dist);
	free(heap);
}