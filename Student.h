#ifndef _INCLUDED_SLIST
#define _INCLUDED_SLIST

#include<stdio.h>
#include<stdint.h>

typedef struct _node_ Node;
typedef struct _list_ List;

struct _node_{
    long long rno;
    char name[50];
    float marks1;
    float marks2;
    Node *next;
};

struct _list_{
    Node *head;
    Node *tail;
    uint32_t length;
};


List* list_new();
List* student_add(List *list);
List* student_modify(List *list);
List* student_remove(List *list);
void display_student(const List *list);
uint32_t student_length(const List *list);

#endif