#include "Stack_Arr.h"

Stack stack_new(uint32_t size){
    size = (size > 0 && size < MAX_DEPTH)?size : MAX_DEPTH;
    Stack stk = {size,-1,{0}};
    return stk;
}

uint32_t isfull(const Stack *stk){
    assert(stk != NULL);
    return ((stk->size)==(stk->top+1));
}

uint32_t isemtpy(const Stack *stk){
    assert(stk != NULL);
    return (stk -> top == -1);
}

Stack* push(Stack *stk, float data, StackResult *result){
    assert(stk != NULL);
    if(stk -> top +1 < stk -> size){
        stk -> data[++stk -> top] = data;
        result -> data = data;
        result -> status = STACK_OK;
    }
    else{
        result -> data = data;
        result -> status = STACK_FULL;
    }
    return stk;
}

Stack* pop(Stack *stk, StackResult *result){
    assert(stk != NULL);
    if(stk -> top == -1){
        result -> status = STACK_EMPTY;
    }
    else{
        result -> data = stk -> data [stk -> top--];
        result -> status = STACK_OK;
    }
    return stk;
}

Stack* peek( Stack *stk, StackResult *result){
    assert(stk != NULL);
    if( stk -> top == -1){
        result -> status = STACK_EMPTY;
    }
    else{
        result -> data = stk -> data [stk -> top];
        result -> status = STACK_OK;
    }
    return stk;
}