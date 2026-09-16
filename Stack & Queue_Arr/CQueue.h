#ifndef _INCLUDE_CQUEUE_
#define _INCLUDE_QUEUE_
#define MAX_SIZE 32
#define QUEUE_OK 1
#define QUEUE_EMPTY 4
#define QUEUE_FULL 2

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>

struct _queue_ {
    uint32_t size;
    uint32_t count;
    uint32_t head;
    uint32_t tail;
    float data[MAX_SIZE];
};

struct _queueresult_{
    float data;
    int32_t status;
};

typedef struct _queue_ Queue;
typedef struct _queueresult_ QueueResult;

Queue queue_new(uint32_t size);
uint32_t isempty(const Queue *queue);
uint32_t isfull(const Queue *queue);
Queue* enqueue(Queue *queue, float data, QueueResult *result);
Queue* dequeue(Queue *queue, QueueResult *result);
float peek(const Queue *queue,QueueResult *result);
void display(const Queue *queue, QueueResult *result);
#endif