#ifndef _INCLUDED_SLL_
#define _INCLUDED_SLL_


#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct _list_ List;
typedef struct _node_ Node;
struct _node_{
    int32_t data;
    Node *next;
};


struct _list_{
    Node *head;
    uint32_t size;
};

List* new_list();
Node* new_node(int32_t data);
List* list_add(List *list,int32_t data);
List* sort_list(List *list);
List* merge_list(List *l1,List *l2);
void print_list(List *list);
#endif