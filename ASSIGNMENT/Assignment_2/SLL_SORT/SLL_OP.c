#include "SLL.h"

void test(){
    List *l1=new_list();
    l1=list_add(l1,5);
    l1=list_add(l1,2);
    l1=list_add(l1,8);
    l1=list_add(l1,1);
    l1=list_add(l1,4);
    List *l2=new_list();
    l2=list_add(l2,9);
    l2=list_add(l2,3);
    l2=list_add(l2,7);
    l2=list_add(l2,6);
    printf("List 1 before sorting:\n");
    print_list(l1);
    printf("\nList 2 before sorting:\n");
    print_list(l2);
    l1=sort_list(l1);
    l2=sort_list(l2);
    printf("\nList 1 after sorting:\n");
    print_list(l1);
    printf("\nList 2 after sorting:\n");
    print_list(l2);
    List *merged=merge_list(l1,l2);
    printf("\nMerged list:\n");
    print_list(merged);
    free(merged);
}

int main(){
    test();
    return 0;
}