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
    slist_add_head(list,11);
    // slist_add_head(list,67);
    // slist_add_head(list,59);
    // slist_add_head(list,61);
    // slist_add_head(list,74);
    slist_add_head(list,97);
    slist_add_head(list,93);
    slist_add_tail(list,30);
    slist_add_tail(list,40);
    slist_add_tail(list,50);
    printf("\nAFTER ADDING ALL THE ELEMENTS : %d" ,slist_length(list));
    assert(slist_lookup(list,30));
    slist_delete_head(list);
    printf("\nLength AFTER DELETION OF HEAD ELEMENT : %d" ,slist_length(list));
    slist_delete_tail(list);
    printf("\nAFTER DELETION OF TAIL ELEMENT : %d\n" ,slist_length(list));
    slist_add_bw(list,10);
    // slist_add_bw(list,89);
    // slist_add_bw(list,80);
    printf("After adding element in bw : %d", slist_length(list));
    display(list);
    slist_delete_bw(list);
    printf("After Deleting element in bw : %d", slist_length(list));
    slist_add_on_data(list, 50,17);
    printf("\nAfter add_on function : %d", slist_length(list));
    slist_delete_on_data(list, 20);
    printf("\nAfter add_on function : %d", slist_length(list));
    slist_min_max(list);
    display(list);
    slist_rev(list);
    printf("\n REVERSE LIST \n");
    display(list);
    printf("\n LATEST LENGTH : %d", slist_length(list));
    slist_nth_node(list);
    slist_rem_dup(list);
    display(list);
    slist_cycle(list);
    // slist_free(list);
    printf("\nASSERTIONS PASSED\n");
}


int main(){

    test_generic();
    return 0;
}