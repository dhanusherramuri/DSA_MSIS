#ifndef _INCLUDED_UI
#define _INCLUDED_UI


#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct _node_ Node;
typedef struct _list_ List;

struct _node_{
    uint32_t data;
    Node *next;
};

struct _list_{
    Node *head;
    Node *tail;
    uint32_t length;
};

Node* list_node_new(uint32_t data);
List* list_new();
List* list_add(List *list, uint32_t data);
List* list_intersect(List *list1, List *list2,List *list3);
void display_UI(const List *list);

#endif