#ifndef _INCLUDE_QUEUE
#define _INCLUDE_QUEUE

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <assert.h>


typedef struct _node_ Node;
typedef struct _list_ List;

struct _node_ {
    int32_t data;
    Node *next;
};

struct _list_ {
    Node *head;
    Node *tail;
    uint32_t length;
};



List* list_new();
Node* node_new(int32_t data);
List* Enqueue(List *list, int32_t data);
List* Dequeue(List *list);
uint32_t isEmpty(const List *list);
void display_queue(const List *list);
uint32_t Queue_len(const List *list);

#endif