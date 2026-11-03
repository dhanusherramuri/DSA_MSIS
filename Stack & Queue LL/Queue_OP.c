#include "Queue.h"

void test()
{
    List* Queue = list_new();

    Enqueue(Queue, 60);
    Enqueue(Queue, 50);
    Enqueue(Queue, 40);
    Enqueue(Queue, 30);
    Enqueue(Queue, 20);
    Enqueue(Queue, 10);

    display_queue(Queue);

    Reverse(Queue);

    display_queue(Queue);

    printf("LENGTH OF QUEUE: %u\n", Queue_len(Queue));

    Dequeue(Queue);
    display_queue(Queue);
}

int main()
{
    test();
    return 0;
}