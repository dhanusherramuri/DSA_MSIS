#include "Graphs.h"

void test(){
    Graph g = graph_new(5);
    graph_adjacency(&g);
    graph_dfs_(&g,0);
}

int main(){
    test();
    return 1;
}