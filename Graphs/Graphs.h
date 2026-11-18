#ifndef _INCLUDE_GRAPH_
#define _INCLUDE_GRAPH_
#define TRUE 1
#define FALSE 0
#define MAX 20

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct _graph_node Node;
typedef struct _graph_list Graph;

struct _graph_node {
    int32_t node_id;
    Node *next;
};

struct _graph_list{
    Node **neighbours;
    int32_t maxnodes;
};

extern int32_t visited[MAX];

Graph graph_new(int32_t max);
Graph* graph_adjacency(Graph *graph);
Graph* graph_dfs_ (Graph *graph, int32_t v);



#endif