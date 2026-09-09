#include "Stack.h"

void test(){
    Stack stk1 = stack_new(6);
    Stack *stk = &stk1;
    StackResult result;
    // assert(isemtpy(stk));
    assert(!isfull(stk));
    peek(stk, &result);
    assert(result.status == STACK_EMPTY);
    push(stk,10,&result);
    // assert(stk -> size == 5);
    push(stk,20,&result);
    push(stk,30,&result);
    push(stk,40,&result);
    // push(stk,50,&result);
    pop(stk, &result);
    // assert(stk.size == 3);
    printf("\nASSERTIONS PASSED\n");
}

int main(){
    test();
    return 0;
}