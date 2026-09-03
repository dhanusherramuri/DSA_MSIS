// WAP TO FIND THE UNION AND INTERSECTION OF TWO SLL, THE RESULTANT LIST, THE ELEMENTS MUST BE UNIQUE
// COMPARE 2 SLL and FIND THE DIFF BETWEEN 2 SLL

#include "UI.h"
#include <stdio.h>

Node* list_node_new(uint32_t data){
    Node *node = (Node*)malloc(sizeof(Node));
    node -> data = data;
    node -> next = NULL;
    return node;
}

List* list_new(){
    List *list = (List*)malloc(sizeof(List));
    list -> head = NULL;
    list -> tail = NULL;
    list -> length = 0;
    return list;
}

List* list_add(List *list, uint32_t data){
    
    Node *node = list_node_new(data);
    if(list -> head == NULL){
        list -> head = node;
        list -> tail = node;
        ++list -> length;
    }

    else{
        list -> tail -> next = node;
        list -> tail = node;
        // node -> next = list -> head;
        // list -> head = node;
        ++list -> length;
    }
    return list;
}

List* list_union(List *list1, List *list2,List *list3){

    Node *temp1 = list1 -> head;
    Node *temp2 = list2 -> head;
    while(temp1 != NULL ){
        list_add(list3,temp1 -> data);
        temp1 = temp1 -> next;
    }
    Node *temp3 = list3 -> head;
    while(temp2 != NULL){
        int flag = 0;
        while(temp3 != NULL){
            if(temp2 -> data == temp3 -> data){
                // temp2 = temp2 -> next;
                flag = 1;
                break;
            }
            else{
                // list_add(list3, temp2 -> data);
                // temp2 = temp2 -> next;
                temp3 = temp3 -> next;
            }
        }
        if(!flag){
            list_add(list3, temp2 -> data);
        }
        temp2 = temp2 -> next;
    }
    return list3;

}

List* list_intersect(List *list1,List *list2,List *list4){
    Node *t1 = list1 -> head;
    
    while(t1 != NULL){
        int flag = 0;
        Node *t2 = list2 -> head;

        while( t2 != NULL ){

            if(t1 -> data == t2 -> data){
                flag = 1;
                t2 = t2 -> next;
                break;
            }
            t2 = t2 -> next;
        }
        if(flag){
            Node *t4 = list4 -> head;
            int f = 0;
            while(t4!=NULL){
                if( t4 -> data == t1 -> data ){
                    t4 = t4 -> next;
                    f = 1;
                    break;
                }
                t4 = t4 -> next;
            }
            if(!f){
                list_add(list4, t1 -> data);
                f = 0;
            }
            flag = 0;
        }
        t1 = t1 -> next;
    }
    return list4;
}

List* list_diff(List *list1, List *list2, List *list5){
    Node *t1 = list1 -> head;
    
    while( t1 != NULL){
        Node *t2 = list2 -> head;
        int flag = 0;
        while ( t2 != NULL){
            if(t2 -> data == t1 -> data){
                flag = 1;
                t2 = t2 -> next;
            }
            t2 = t2 -> next;
        }
        if(!flag){
            list_add(list5, t1 -> data);
            flag = 0;
        }

        t1 = t1 -> next;
    }
    return list5;
}

void display_UI(const List *list){
    if( list -> head == NULL){
        printf("\n EMPTY LIST \n");
        return ;
    }
    else{
        Node * temp = list -> head;
        while(temp->next != NULL){
            printf("%d -> ", temp -> data);
            temp = temp -> next;
        }
        printf("%d -> NULL", temp -> data);
    }
}