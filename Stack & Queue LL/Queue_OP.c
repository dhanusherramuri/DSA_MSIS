#include "Queue.h"

void test(){
List* Queue = list_new();
// isEmpty(Queue);
Enqueue(Queue,60);
Enqueue(Queue,50);
Enqueue(Queue,40);
Enqueue(Queue,30);
Enqueue(Queue,20);
Enqueue(Queue,10);
display_queue(Queue);
printf("\nLENGTH OF QUEUE AFTER ENQUEUE : %d" ,Queue_len(Queue));
Dequeue(Queue);
display_queue(Queue);
Dequeue(Queue);
display_queue(Queue);
printf("\nLENGTH OF QUEUE AFTER DEQUEUE : %d" ,Queue_len(Queue));
isEmpty(Queue);
}

int main(){
    test();
    return 0;
}