#include "CQueue.h"

void testQueue()
{
    Queue q = queue_new(3);
    Queue *queue = &q;
    QueueResult result;

    printf("\nEmpty: %u\n", isempty(queue));
    printf("Full: %u\n", isfull(queue));

    enqueue(queue, 10.5f, &result);
    enqueue(queue, 20.5f, &result);

    printf("\nQueue:\n");
    display(queue,&result);

    printf("\nEmpty: %u\n", isempty(queue));
    printf("Full: %u\n", isfull(queue));

    float data = peek(queue,&result);
    // if (data != NULL)
        printf("Peek: %.2f\n", data);

    dequeue(queue, &result);

    printf("\nAfter dequeue:\n");
    display(queue,&result);

    printf("\nEmpty: %u\n", isempty(queue));
    printf("Full: %u\n", isfull(queue));
}

int main()
{
    testQueue();
    return 0;
}
