#include "Stack.h"

void test_stack(){
    List* Stack = new_list();
    push(Stack,60);
    push(Stack,50);
    push(Stack,40);
    push(Stack,30);
    push(Stack,20);
    push(Stack,10);
    isEmpty(Stack);
    display_stack(Stack);
    printf("\nLENTH OF THE STACK BEFORE POP: %d\n",Stack_len(Stack));
    pop(Stack);
    display_stack(Stack);
    pop(Stack);
    display_stack(Stack);
    printf("\nLENTH OF THE STACK AFTER POP: %d\n",Stack_len(Stack));
}

int main(){
    test_stack();
    return 0;
}