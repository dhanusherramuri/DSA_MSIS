#include "Graphs.h"
int32_t visited [MAX] = {0};


Graph graph_new(int32_t max){
    Graph graph ;
    graph.maxnodes = max;
    graph.neighbours = (Node**)malloc(sizeof(Node*)*graph.maxnodes);
    for(int i = 0 ; i < graph.maxnodes ; i++){
        graph.neighbours[i] = NULL;
    }
    return graph;
}

static Node* _get_nodes_(int data){
    Node *node = (Node*)malloc(sizeof(Node));
    node -> node_id = data;
    node -> next = NULL;
    return node;
}

static int32_t _get_neighbour_(int data){
    int32_t neighbour_id;
    printf("ENTER THE NEIGHBOURS OF NODE %d AND IF THERE IS NO NEIGHBOUR, ENTER 999\n", data);
    scanf("%d" ,&neighbour_id);
    return neighbour_id;
}

Graph* graph_adjacency(Graph *graph){
int32_t neighbour_id;
Node *vertex, *last_vertex;

for(int i = 0; i < graph->maxnodes; ++i){
    graph -> neighbours[i] = _get_nodes_(i);
    neighbour_id = _get_neighbour_(i);

    while(neighbour_id!=999){
        vertex = _get_nodes_(neighbour_id);
        if(graph -> neighbours[i] -> next == NULL){
            graph -> neighbours[i] -> next = vertex;
        }
        else{
            last_vertex -> next = vertex;
        }
        last_vertex = vertex;
        neighbour_id = _get_neighbour_(i);
    }
}
return graph;
}

static void _dfs_(Graph *graph, int32_t v){
    Node *vertex;
    visited[v] = TRUE;
    printf("%d\t" ,v);
    for(vertex = graph->neighbours[v]->next;vertex!=NULL;vertex=vertex->next){
        if(!visited[vertex->node_id]){
            _dfs_(graph,vertex->node_id);
        }
    }
}

Graph* graph_dfs_ (Graph *graph,int32_t v){
    for(int i = 0; i < graph->maxnodes ; i++){
        visited[i] = FALSE;
    }
    _dfs_(graph,v);
    return graph;
}

