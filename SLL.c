#include <stdlib.h>
#include <stddef.h>
#include <assert.h>
#include <limits.h>
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
        free(list);
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
            if(temp!=NULL&&temp->data!=key&&temp->next==NULL){
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
        list -> head = node->next;

        if(list->head == NULL){
            list->tail = NULL;
        }
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
    
    if(del ==  list->tail){
        list->tail = temp;
    }
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

// List *slist_delete_on_data(List *list, uint32_t data){
//     if(list->head == NULL){
//         list->tail =NULL;
//         printf("\nEMPTY LIST\n");
//     }
//     else{
//         Node *temp = list->head;
//         Node *p;
//         if(temp->data == data){
//             list->head = temp->next;
//         }
//         else{
//             p = temp;
//             temp = temp ->next;
//             while(temp!=NULL){
//                 if(temp->data == data){
//                     p->next = temp->next;
//                 }
//                 else{
//                     p = temp;
//                     temp = temp->next;
//                 }
//             }
//             if(temp == list->tail){
//                 list->tail = p;
//             }
//         }
        
//         free(temp);
//         --list->length;
//     }
// }


List *slist_delete_on_data(List *list, uint32_t data){

    if(list->head == NULL){
        printf("\nEMPTY LIST\n");
        return list;
    }

    Node *temp = list->head;
    Node *p = NULL;

    while(temp != NULL && temp->data != data){
        p = temp;
        temp = temp->next;
    }

    if(temp == NULL){
        printf("\nKey Not Found\n");
        return list;
    }

    if(p == NULL){
        list->head = temp->next;
    }
    else{
        p->next = temp->next;
    }

    if(temp == list->tail){
        list->tail = p;
    }

    free(temp);
    --list->length;

    if(list->head == NULL){
        list->tail = NULL;
    }

    return list;
}


void slist_min_max(List *list){
    int min = INT_MAX;
    int max = INT_MIN;
    
    if(list->head == NULL){
        list->tail = NULL;
    }
    else{
        Node *temp = list->head;
        while(temp!=NULL){
            if(temp->data > max){
                max = temp->data;
            }
            if(temp -> data < min){
                min = temp->data;
            }
            temp = temp->next;
        }
    }
    printf("\nMax : %d\nMin : %d",max,min);
}

List* slist_rev(List *list){
    if(list->head == NULL){
        list->tail = NULL;
    }
    else{
        Node *curr = list->head;
        Node *prev=NULL,*next=NULL;

        list->tail = list->head;

        while(curr!=NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr=next;
        }
        list->head = prev;
    }
    return list;
}

void slist_nth_node(List *list){
    if(list->head == NULL){
        list->tail = NULL;
    }
    else{
        int i=1,n;
        printf("\nEnter the node to be displayed\n");
        scanf("%d" ,&n);
        if(n<1 || n>list->length){
            printf("\nINVALID SIZE\n");
        }
        else{
            Node *temp = list->head;
            while(i<list->length-n+1){
                temp = temp->next;
                i++;
            }
            printf("\nNode Data :%d" ,temp->data);
        }

    }
}

List *slist_rem_dup(List *list){
    if(list->head == NULL){
        list->tail = NULL;
        return list;
    }

    else{
        Node *cur = list->head;

        while(cur != NULL){
            Node *ptr = cur->next;
            Node *temp = cur;

            while(ptr != NULL){
                if(cur->data == ptr->data){
                    temp->next = ptr->next;

                    if(ptr == list->tail){
                        list->tail = temp;
                    }

                    free(ptr);
                    --list->length;

                    ptr = temp->next;
                }
                else{
                    temp = ptr;
                    ptr = ptr->next;
                }
            }

            cur = cur->next;
        }
    }

    return list;
}
void display(const List *list){

    if(list->head == NULL){
        printf("\nEMPTY LIST\n");
        return;
    }

    Node *temp = list->head;

    printf("\n");

    while(temp->next != NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("%d", temp->data);
}

