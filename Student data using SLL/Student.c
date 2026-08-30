#include "Student.h"
#include <stdlib.h>
#include <stddef.h>
#include <assert.h>
#include <limits.h>

List* list_new(){
    List *list;
    list = (List*)malloc(sizeof(List));
    list->head = NULL;
    list->tail = NULL;
    list->length = 0;
    return list;
}

static Node* list_new_node(){
    Node *node = (Node*)malloc(sizeof(Node));
    printf("Enter the name of the student : ");
    scanf(" %48[^\n]",node->name);
    printf("Enter the roll number of the student : ");
    scanf("%lld" ,&node->rno);
    printf("Enter the marks of Subject 1 : ");
    scanf("%f" ,&node->marks1);
    printf("Enter the marks of subject 2 : ");
    scanf("%f" ,&node->marks2);
    // node->name = n;
    // node->rno = roll;
    // node->marks1 = m1;
    // node->marks2 = m2;
    node->next = NULL;

    return node;
}
List* student_add(List *list){
    Node *node = list_new_node();
    if(list->head == NULL){
        list -> head = node;
        node->next = NULL;
        // list -> tail = node;
    }
    else{
        node -> next = list->head;
        list -> head = node;
    }
    ++list->length;
    return list;
}
List* student_modify(List *list){
    if(list->head == NULL){
        printf("Empty List\n");
    }
    else{
        Node *temp = list->head;
        printf("Enter the Roll Number of the Student : ");
        long long key;
        scanf("%lld" ,&key);
        while(temp!=NULL){
            if(temp->rno == key){
                printf("1. Roll Number\n2. Name\n3. Marks1\n4. Marks2\n\n Choose the number you want to modify :");
                int n;
                scanf("%d" ,&n);
                switch(n){
                    case 1:{
                        printf("\nEnter the New Roll Number : ");
                        scanf("%lld" ,&temp->rno);
                        printf("\nROLL CHANGED SUCCESSFULLY\n");
                        break;
                    }
                    case 2:{
                        printf("\nEnter the Modified Name : ");
                        scanf(" %48[^\n]" ,temp->name);
                        printf("\nNAME CHANGED SUCCESSFULLY\n");
                        break;
                    }
                    case 3:{
                        printf("\nEnter the New Marks of Subject 1 : ");
                        scanf("%f" ,&temp->marks1);
                        printf("\nMARKS 1 CHANGED SUCCESSFULLY\n");
                        break;
                    }
                    case 4:{
                        printf("\nEnter the New Marks of Subject 2 : ");
                        scanf("%f" ,&temp->marks2);
                        printf("\nMARKS 2 CHANGED SUCCESSFULLY\n");
                        break;
                    }
                    default :{
                        printf("\nINVALID OPTION\n");
                        break;
                    }
                }
                break;
            }
            else{
                temp = temp->next;
            }
            if(temp->rno != key && temp->next == NULL ){
                printf("\nSTUDENT NOT FOUND\n");
                break;
            }
        }
    }
    return list;
}

List* student_remove(List *list){
    if(list->head == NULL){
        printf("\nTHERE IS NO DATA\n");
    }
    else{
        printf("Enter the Roll Number of the Student : ");
        long long key;
        scanf("%lld", &key);

        Node *temp = list->head;
        Node *cur = NULL;

        if(key == temp->rno){
            list->head = temp->next;
            free(temp);
            printf("\nSTUDENT DATA REMOVED SUCCESSFULLY\n")
            list->length--;
            return list;
        }
        while(temp != NULL){
            
            if(temp->rno == key){
                
                cur->next = temp->next;
                temp->next = NULL;
                free(temp);
                printf("\nSTUDENT DATA REMOVED SUCCESSFULLY\n")
                
                --list->length;
                break;
            }
            else{
                cur = temp;
                temp = temp->next;
            }

            if(temp == NULL){
                printf("\nStudent Not Found\n");
                break;
            }
        }
    }
    return list;
}
void display_student(const List *list){
    if(list->head == NULL){
        printf("Empty List");
    }
    else{
        Node *temp = list->head;
        while(temp!= NULL){
            printf("\nRoll Number : %lld ",temp->rno);
            printf("\nName : %s ",temp->name);
            printf("\nMarks1 : %.2f ",temp->marks1);
            printf("\nMarks2 : %.2f \n",temp->marks2);
            temp = temp->next;
        }
    }
}

uint32_t student_length(const List *list){
    return list->length;
}