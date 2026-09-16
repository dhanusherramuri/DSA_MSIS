#include "CQueue.h"

Queue queue_new(uint32_t size){
    size = (size > 0 && size < MAX_SIZE)? size : MAX_SIZE;
    Queue queue = {size,0,0,0,{0}};
    return queue;    
}

uint32_t isempty(const Queue *queue){
    assert(queue != NULL);
    return (queue -> count == 0);
}

uint32_t isfull(const Queue *queue){
    assert(queue != NULL);
    return (queue -> count == (queue -> size)-1);
}

Queue* enqueue(Queue *queue, float data, QueueResult *result){
    assert(queue != NULL);
    if(queue -> count < queue -> size){
        queue -> data[queue -> tail] = data;
        queue -> tail = (queue -> tail+1) % (queue -> size);
        ++queue -> count;
        result -> status = QUEUE_OK;
    }
    else{
        result -> status = QUEUE_FULL;
    }
    return queue;
}

Queue* dequeue(Queue *queue, QueueResult *result){
    assert(queue != NULL);
    if(queue -> count > 0){
        result -> data = queue ->data[queue -> head];
        queue -> head = (queue -> head +1) % (queue -> size);
        -- queue -> count;
        result ->status = QUEUE_OK;
    }
    else{
        result -> status = QUEUE_EMPTY;
    }
    return queue;
}

float peek(const Queue *queue, QueueResult *result){
    assert(queue !=NULL);
    if(queue -> count > 0){
        result -> status = QUEUE_OK;
        return queue -> data[queue -> head];
    }
    else{
        result -> status = QUEUE_EMPTY;
    }
    return 0;
}

void display(const Queue *queue, QueueResult *result){
    assert(queue != NULL);
    if(queue -> count > 0){
        for(int i = 0; i< queue -> count;i++){
            printf("%.2f ",queue->data[i]);
        }
        result -> status = QUEUE_OK;
    }
    else{
        result -> status = QUEUE_EMPTY;
    }
}