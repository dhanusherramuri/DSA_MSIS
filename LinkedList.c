#include <stdio.h>

struct node{
    int head;
    struct node *link;
}

void add (struct node **head){
    struct node *temp;
    int data;
    printf("Enter the data to be stored\n");
    scanf("%d" data);

    struct Node *temp = malloc(sizeof(struct Node));


    temp->data = data;
    temp->link = NULL;


    if(*head == NULL){
        *head = temp;
    }
    else{
        struct node *current = *head;
        while(*head->next!=NULL){
            current = current->link;
        }

        current->link = temp;
    }
}

void display(struct Node **head) {
    struct Node *current = head;

    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->link;
    }

    printf("NULL\n");
}

int main(){
    int c;
    struct node *head = NULL;
    // struct node *link = NULL;
    
    
    while(1){
        printf("\n1. Add \n2. Display");
        scanf("%d" ,&c);
        if(c == 1){
            add(head);
        }
        else if(c == 2){
            display(head);
        }
        else if(c == 3){
            break;
        }

    }
    

}