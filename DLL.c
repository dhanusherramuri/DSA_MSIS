#include "DLL.h"
#include <limits.h>
List* dlist_new(){
    List *list;
    list = (List*)malloc(sizeof(List));
    list -> head = NULL;
    list -> tail = NULL;
    list -> length = 0;
    return list;
}

Node* node_new(uint32_t data){
    Node *node = (Node*)malloc(sizeof(Node));
    node -> data = data;
    node -> next = NULL;
    node -> prev = NULL;
    return node;
}

List* dll_add_head(List *list, uint32_t data){
    Node *node = node_new(data);
    if(list -> head == NULL){
        list -> head = node;
        list -> tail = node;
        node -> next = NULL;
        node -> prev = NULL;
        ++list -> length;
    }
    else{
        Node * temp = list -> head;
        temp -> prev = node;
        node -> next = temp;
        node -> prev = NULL;
        list -> head = node;
        ++list -> length;
    }

    return list;

}

List* dll_add_tail(List *list, uint32_t data){
    Node *node = node_new(data);
    if(list->head == NULL){
        list->tail = list -> head = node;
        node -> next = NULL;
        node -> prev = NULL;
        ++list -> length;
    }
    else{
        Node *temp = list -> tail;
        temp -> next = node;
        node -> prev = temp;
        node -> next = NULL;
        list -> tail = node;
        ++list->length;
    }

    return list;
}

List* dll_add_bw(List *list, uint32_t data){
    int n;
    printf("\nEnter the position to insert the element : ");
    scanf("%d" ,&n);
    if(n <= 1){
        printf("\nCannot Insert at head\n");
    }
    else if(n >= list->length){
        printf("\nCannot Insert at tail\n");
    }
    else{
        int i = 1;
        Node *temp = list -> head;
        Node *node = node_new(data);
        while(i < n - 1){
            temp = temp -> next;
            i++;
        }
        Node *curr = temp->next;
        node -> next = curr;
        node -> prev = temp;
        temp -> next = node;
        curr -> prev = node;
        ++list -> length;
    }

    return list;
}

List* dll_add_on_data(List *list,uint32_t key,uint32_t data){
    if(list -> head == NULL){
        list -> tail = NULL;
        printf("\nEMPTY LIST\n");
    }
    else{
        Node * temp = list -> head;
        while( temp != NULL ){
            if(temp -> data == key){
                Node *node = node_new(data);
                node -> next = temp -> next;
                node -> prev = temp;
                temp -> next = node;

                if(node->next != NULL)
                    node -> next -> prev = node;
                else
                    list -> tail = node;
                ++list -> length;
                return list;
            }
            temp = temp->next ;
        }
        printf("\nELEMENT NOT FOUND\n");
        }
        return list;
    }


List* dll_del_bw(List *list){
    int n;
    printf("\nEnter the position where the element is to be deleted : ");
    scanf("%d" ,&n);
    if(n <= 1){
        printf("\nCANNOT DELETE HEAD\n");
    }
    else if(n >= list->length){
        printf("\n CANNOT DELETE TAIL\n");
    }
    else{
        Node * temp = list -> head;
        int i = 1;
        while( i < n-1 && temp != NULL ){
            temp = temp -> next;
            i++;
        }

        if (temp == NULL || temp->next == NULL) {
        printf("\nInvalid location\n");
        return list;
        }

        Node *del = temp -> next;
        temp -> next = del -> next;
        del -> next -> prev = temp;

        if(del ==  list->tail){
        list->tail = temp;
    }
    free(del);                   
    --list->length;

}
return list;
}

List* dll_del_on_data(List *list, uint32_t data){
    Node *temp = list -> head;
    if( list -> head == NULL ){
        list -> tail = NULL;
        printf("\n EMPTY LIST \n");
    }
    else{
        while(temp != NULL){
            if( temp -> data == data){
                if(temp->prev != NULL)
                    temp->prev->next = temp->next;
                else
                    list->head = temp->next;

                if(temp->next != NULL)
                    temp->next->prev = temp->prev;
                else
                    list->tail = temp->prev;

                free(temp);
                list->length--;

                return list;
            }
            temp = temp -> next;
        }
        printf("\nDATA NOT FOUND\n");
    }
    return list;
}

List* dll_del_head(List *list){
    if( list -> head == NULL ){
        list -> tail = NULL;
        printf("\nEMPTY LIST\n");
    }
    else{
        Node *temp = list -> head;
        list -> head = temp -> next;
        list -> head -> prev = NULL;
        temp -> next = NULL;
        free (temp);
        list -> length --;
    }
    return list;
}

List* dll_del_tail(List *list){
    if( list -> tail == NULL ){
        printf("\nEMPTY LIST\n");
    }
    else{
        Node *temp = list -> tail;
        list -> tail = temp -> prev;
        list -> tail -> next = NULL;
        temp -> prev = NULL;
        free(temp);
        list -> length --;
    }
    return list;
}

void dll_lookup( List *list, uint32_t key){
    Node *temp = list -> head;

    while( temp != NULL ){
        if( temp -> data == key ){
            printf("\nKEY FOUND\n");
            return ;
        }
        temp = temp -> next;
    }
    printf("\nKEY NOT FOUND\n");
    return ;
}

void dll_min_max( List *list){
    int min = INT_MAX;
    int max = INT_MIN;

    if( list -> head == NULL ){
        list -> tail = NULL;
        return;
    }
    else{
        Node *temp = list -> head;
        while(temp != NULL){
            if( temp -> data >= max ){
                max = temp -> data;
            }
            else if( temp -> data <= min ){
                min = temp -> data;
            }
            temp = temp -> next;
        }
        printf("\nMINIMUM : %d\nMAXIMUM : %d\n",min,max);
    }
    return;
}

uint32_t dll_length(const List *list){
    return list->length;
}
void dll_display(const List *list){
    if(list -> head == NULL || list -> tail == NULL){
        printf("\nEMPTY LIST\n");
    }
    else{

        Node *temp = list -> head;
        
        printf("\n");
        
        while(temp->next != NULL){
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }

    printf("%d", temp->data);
    }
}