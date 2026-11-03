#include "SLL.h"

List* new_list(){
    List *list = (List*)malloc(sizeof(List));
    list -> head = NULL;
    // list -> tail = NULL;
    list -> size = 0;
    return list;
}

Node* new_node(int32_t data){
    Node *node = (Node*)malloc(sizeof(Node));
    node -> data = data;
    node -> next = NULL; 
    return node;
}

List* list_add(List *list,int32_t data){
    Node *node = new_node(data);
    if( list->head == NULL){
        list -> head = node;
        // return list;
    }
    else{
        node -> next = list -> head;
        list -> head = node;
    }
    ++list -> size;
    return list;
}


static Node* merge(Node *head){

    if(head == NULL || head->next == NULL)
        return head;
    Node *slow = head;
    Node *fast = head->next;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    Node *right = slow->next;
    slow->next = NULL;

    Node *left = head;

    left = merge(left);
    right = merge(right);

    Node temp;
    Node *tail = &temp;

    temp.next = NULL;

    while(left != NULL && right != NULL){

        if(left->data <= right->data){

            tail->next = left;
            left = left->next;
        }
        else{

            tail->next = right;
            right = right->next;
        }

        tail = tail->next;
    }

    if(left != NULL)
        tail->next = left;
    else
        tail->next = right;

    return temp.next;
}

List* sort_list(List *list){

    if(list == NULL || list->head == NULL)
        return list;

    list->head = merge(list->head);

    return list;
}

List* merge_list(List *l1,List *l2){
    if(l1==NULL)
        return l2;
    
    if(l2==NULL)
        return l1;

    List *list=new_list();
    
    if(list==NULL)
        return NULL;

    Node temp;
    Node *tail=&temp;
    Node *left=l1->head;
    Node *right=l2->head;

    temp.next=NULL;
    while(left!=NULL && right!=NULL){
        if(left->data<=right->data){
            tail->next=left;
            left=left->next;
        }

        else{
            tail->next=right;
            right=right->next;
        }

        tail=tail->next;
    }
    
    tail->next=(left!=NULL)?left:right;
    list->head=temp.next;
    list->size=l1->size+l2->size;
    free(l1);
    free(l2);
    return list;
}

void print_list(List *list){
    if(list==NULL){
        printf("List is NULL\n");
        return;
    }
    Node *temp=list->head;
    while(temp!=NULL){
        printf("%d -> ",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
    printf("Size: %u\n",list->size);
}