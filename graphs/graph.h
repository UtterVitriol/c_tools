#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define u64 uint64_t

typedef struct Node {
	u64 dest;
	int weight;
	struct Node *next;
} Node;

typedef struct Graph {
	u64 v;
	struct Node **array;
} Graph;

Graph *init_graph(u64 size);
Node *create_node(u64 dest);
void add_edge(Graph *graph, u64 src, u64 dst);
void destroy_list(Node *node);
void print_graph(Graph *graph);
int breadth_first(Graph *graph, Node *node, u64 start);
int depth_first(Graph *graph, u64 start);
void destroy_graph(Graph *graph);
u64 get_greatest(FILE *fp);
u64 triangle_count(Graph *graph);
void dijkstra(Graph *graph, u64 start);