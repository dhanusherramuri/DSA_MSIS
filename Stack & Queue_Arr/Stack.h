#ifndef _INCLUDE_STACK_
#define _INCLUDE_STACK_

#define MAX_DEPTH 32
#define RESULT_INVALID 0
#define STACK_OK 1
#define STACK_FULL 2
#define STACK_EMPTY 4

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>

typedef struct  _stack_ Stack;
typedef struct  _stackresult_ StackResult;

struct _stack_ {
    uint32_t size;
    int32_t top;
    float data[MAX_DEPTH];
};

struct _stackresult_{
    float data;
    uint32_t status;
};

Stack stack_new(uint32_t size);
uint32_t isempty(const Stack *stk);
uint32_t isfull(const Stack *stk);
Stack* push(Stack *stk,float data, StackResult *result);
Stack* pop(Stack *stk, StackResult *result);
Stack* peek(Stack *stk, StackResult *result);

#endif