#include <stddef.h>
#include <stdlib.h>
#include <assert.h>
#include "SLL.h"

void test_generic(){
    List* list = slist_new();
    // list = list_node_new(30);
    assert(slist_length(list)==0);
    slist_add_head(list,20);
    slist_add_head(list,10);
    slist_add_tail(list,30);
    slist_add_tail(list,40);
    slist_add_tail(list,50);
    printf("\nAFTER ADDING ALL THE ELEMENTS : %d" ,slist_length(list));
    assert(slist_lookup(list,30));
    slist_delete_head(list);
    printf("\nLength AFTER DELETION OF HEAD ELEMENT : %d" ,slist_length(list));
    slist_delete_tail(list);
    printf("\nAFTER DELETION OF TAIL ELEMENT : %d\n" ,slist_length(list));
    // assert(slist_length(list)==2);
    slist_add_bw(list,100);
    printf("After adding element in bw : %d", slist_length(list));
    display(list);
    slist_delete_bw(list);
    printf("After Deleting element in bw : %d", slist_length(list));
    display(list);
    printf("\nASSERTIONS PASSED\n");
}

int main(){

    test_generic();
    return 0;
}