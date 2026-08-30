#include <stdio.h>

void enqueue(int queue[], int *rear,int n){
    int data;

    if(*rear >= n){
        printf("\nQueue is Full");
    }
    else{
        printf("\nEnter the data to be Enqueued : ");
        scanf("%d" ,&data);
        queue[*rear] = data;
        (*rear)++;
    }
    printf("\nRear : %d", *rear);
}

void dequeue(int queue[], int *front, int *rear, int n){
    if(*front == *rear || *rear == 0){
        printf("\nQueue is Empty\n");
    }
    else {
        int rem = queue[*front];
        (*front)++;
        printf("Dequeued Element : %d" ,rem);
        printf("\nRear : %d", *rear);
        printf("\nFront : %d", *front);
    }
}

void print(int queue[],int *front,int *rear){
    if(*rear == -1){
        printf("\nQueue is Empty\n");
    }
    else{
        printf("\nQUEUE : ");
        for(int i = *front;i<*rear;i++){
            printf(" %d" ,queue[i]);
        }
        printf("\n");
    }
}

int main(){

    int n,front = 0,rear = 0;
    printf("\nEnter the Size of the Queue : \n");
    scanf("%d" ,&n);
    int queue[n];
    while (1){

        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Print");
        printf("\n4. Exit\n");

        int choice;
        scanf("%d" ,&choice);
        if(choice == 1){
            enqueue(queue,&rear,n);
        }
        if(choice == 2){
            dequeue(queue,&front,&rear,n);
        }
        if(choice == 3){
            print(queue,&front,&rear);
        }
        if(choice == 4){
            break;
        }
    }
}