#include <stdlib.h>
#include <stddef.h>
#include <assert.h>
#include "SLL.h"

List* slist_new(){
    List *list;
    list = (List*)malloc(sizeof(List));
    list -> head = NULL;
    list -> tail = NULL;
    list->length = 0;
    return list;
}

List* slist_free(List *list){
    Node *cur, *p;
    if(slist_length(list)>0){
        assert(list->head&&list->tail);
        cur = list->head;
        list->head = NULL;
        list->tail = NULL;
        while(cur!=NULL){
            p = cur;
            cur = cur -> next;
            free(p);
            --list->length;
        }
    }
    return list;
}

static Node* list_node_new(int32_t data){
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

List* slist_add_head(List *list, uint32_t data){
    Node* node = list_node_new(data);
    node->next = list->head;
    list->head = node;
    if(list->tail == NULL){
        list->tail = node;
    }
    ++list->length;
    assert((list->length == 1 && list->head == list->tail)||(list->length > 0 && list->head!=list->tail));
    return list;
}

List* slist_add_bw(List *list, uint32_t data){
    Node* node = list_node_new(data);
    Node *temp = list -> head;

    printf("Enter the desired location : ");
    int n,i=1;
    scanf("%d" ,&n);
    if(n <= 1){
        printf("\nCannot be inserted at head\n");
        return list;
    }

        while(i < n - 1 && temp != NULL){
            temp = temp -> next;
            i++;
        }

        if (temp == NULL || temp->next == NULL) {
        printf("\nInvalid location\n");
        free(node);
        return list;
    }
        node -> next = temp->next;
        temp -> next = node;
        ++list->length;
    return list;
}

List* slist_add_tail(List *list, uint32_t data){
    Node *node = list_node_new(data);
    node->next = NULL;
    if(list -> head == NULL){
        list->head=node;
        list->tail=node;
    }
    else{
        list->tail->next=node;
        list -> tail = node;
    }
    ++list->length;
    return list;
}

List*  slist_add_on_data(List *list, uint32_t key,uint32_t data){
    Node *node = list_node_new(data);
    node -> next = NULL;
    if(list -> head == NULL){
        list->head = node;
        list->tail = node;
    }
    else{
        Node *temp = list -> head;
        while(temp!=NULL){
            if(temp->data == key && temp -> next !=NULL){
                node->next = temp -> next;
                temp->next = node;
                ++list->length;
                break;
            }
            if(temp->data == key && temp -> next == NULL){
                temp->next = node;
                list->tail = node;
                ++list->length;
                break;
            }
            temp = temp->next;
            if(temp->data!=key&&temp->next==NULL){
                printf("\nKey Not Found\n");
                free(node);
                break;
            }
        }

    }
    return list;
}

uint32_t slist_length(const List *list){
    return list->length;
}

uint32_t slist_lookup(const List *list, uint32_t key){
    Node *temp = list->head;
    while(temp!=NULL){
        if(key == temp->data){
            printf("\nFOUND\n");
            break;
        }

        temp = temp -> next;
    }
    return (temp!=NULL);
}

List* slist_delete_head(List *list){

    if(list->head == NULL){
        printf("\nEMPTY LL\n");
    }
    else{
        Node *node = list->head;
        list -> head = list->head->next;
        node->next = NULL;
        free(node);
        --list -> length;
    }
    return list;

}

List* slist_delete_bw(List *list){
    Node *temp = list -> head;
    int n, i=1;
    printf("\n Enter the position to be deleted : ");
    scanf("%d" ,&n);

     if(n <= 1){
        printf("\nHead Cannot Be deleted Using this Function\n");
        return list;
    }

    while(i < n - 1 && temp != NULL){
            temp = temp -> next;
            i++;
        }

        if (temp == NULL || temp->next == NULL) {
        printf("\nInvalid location\n");
        return list;
    }

    Node *del = temp->next;      
    temp->next = del->next;      
    free(del);                   

    --list->length;

    return list;

}

List* slist_delete_tail(List *list) {
    Node *temp;

    if (list->head == NULL) {
        printf("\nEMPTY LL\n");
        return list;
    }

    if (list->head == list->tail) {
        free(list->tail);
        list->head = NULL;
        list->tail = NULL;
        list->length = 0;
        return list;
    }

    temp = list->head;

    while (temp->next != list->tail) {
        temp = temp->next;
    }

    free(list->tail);
    list->tail = temp;
    list->tail->next = NULL;
    --list->length;

    return list;
}

List *slist_delete_on_data(List *list, uint32_t data){
    if(list->head == NULL){
        list->tail =NULL;
        printf("\nEMPTY LIST\n");
    }
    else{
        Node *temp = list->head;
        Node *p;
        if(temp->data == data){
            list->head = temp->next;
        }
        else{
            p = temp;
            temp = temp ->next;
            while(temp!=NULL){
                if(temp->data == data){
                    p->next = temp->next;
                }
                else{
                    p = temp;
                    temp = temp->next;
                }
            }
            if(temp == list->tail){
                list->tail = p;
            }
        }
        
        free(temp);
        --list->length;
    }
}

void display(const List *list){
    Node *temp = list ->head;
    printf("\n");
    for(int i = 0 ; i < list->length-1; i++){
        printf("%d -> " ,temp->data);
        temp = temp->next;
    }
    printf("%d",list->tail->data);
}

