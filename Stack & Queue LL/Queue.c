#include "Queue.h"

List* list_new(){
    List *list = (List*)malloc(sizeof(List));
    list -> head = NULL;
    list -> tail = NULL;
    list -> length = 0;
    return list;

}


Node* node_new(int32_t data){
    Node *node = (Node*)malloc(sizeof(Node));
    node -> data = data;
    node -> next = NULL;
    return node;
}

List* Enqueue(List *list, int32_t data){
    Node *temp = node_new(data);

    if(list -> head == NULL){
        list -> head = temp;
        list -> tail = temp; 
    }
    else{
        temp -> next = list -> head;
        list -> head = temp;
    }
    ++list -> length;
    return list;
}

List* Dequeue(List *list)
{
    if (list == NULL || list->head == NULL)
    {
        printf("\nQUEUE IS EMPTY\n");
        return list;
    }

    Node *del = list->tail;

    printf("\nELEMENT DELETED : %d\n", del->data);

    if (list->head == list->tail)
    {
        list->head = NULL;
        list->tail = NULL;
    }
    else
    {
        Node *temp = list->head;

        while (temp->next != list->tail)
        {
            temp = temp->next;
        }

        list->tail = temp;
        temp->next = NULL;
    }

    free(del);
    --list->length;

    return list;
}



uint32_t isEmpty(const List *list){
    if( list == NULL){
        printf("\nEMPTY QUEUE\n");
        return 1;
    }
    else 
    return 0;
}

void display_queue(const List *list){
    if(list == NULL){
        printf("\nQUEUE IS EMPTY\n");
    }
    else{
        Node *temp = list -> head;
        while(temp -> next != NULL){
            printf("%d -> ",temp -> data);
            temp = temp -> next;
        }
        printf("%d", temp -> data);
    }

}

uint32_t Queue_len(const List *list){
    return list -> length;
}