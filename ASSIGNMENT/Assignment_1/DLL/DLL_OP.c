#include "DLL.h"
#include <assert.h>
void test_dll(){
    List *list = dlist_new();
    assert(dll_length(list) == 0);
    dll_add_head(list,40);
    dll_add_head(list,30);
    dll_add_head(list,20);
    dll_add_head(list,10);
    printf("\nLIST LENGTH AFTER 4 HEAD ADD'S : %d\n",dll_length(list));
    dll_display(list);
    dll_add_tail(list,50);
    dll_add_tail(list,60);
    dll_add_tail(list,70);
    dll_add_tail(list,80);
    printf("\nLIST LENGTH AFTER 4 TAIL ADD'S : %d\n",dll_length(list));
    dll_display(list);
    dll_add_bw(list,50);
    dll_add_bw(list,60);
    printf("\nLIST LENGTH AFTER 2 B/W ADD'S : %d\n",dll_length(list));
    dll_display(list);
    dll_del_bw(list);
    dll_del_bw(list);
    printf("\nLIST LENGTH AFTER 2 B/W DEL'S : %d\n",dll_length(list));
    dll_display(list);
    dll_add_on_data(list,50,25);
    dll_add_on_data(list,100,20);
    printf("\nLIST LENGTH AFTER 2 ADD ON DATA : %d\n",dll_length(list));
    dll_display(list);
    dll_del_on_data(list,50);
    dll_del_on_data(list,150);
    printf("\nLIST LENGTH AFTER 2 DEL ON DATA : %d\n",dll_length(list));
    dll_display(list);
    dll_del_head(list);
    printf("\nLIST LENGTH AFTER 1 DEL ON HEAD : %d\n",dll_length(list));
    dll_display(list);
    dll_del_tail(list);
    printf("\nLIST LENGTH AFTER 1 DEL ON TAIL : %d\n",dll_length(list));
    dll_display(list);
    dll_min_max(list);
    dll_lookup(list,150);
    printf ("\nLIST BEFORE REVERSE :");
    dll_display(list);
    dll_rev(list);
    printf ("\nLIST AFTER REVERSE : " );
    dll_display(list);
    dll_rem_dup(list);
    printf ("\nLIST AFTER DELETE DUPLICATES : " );
    dll_display(list);
    printf("\n\n ALL ASSERTIONS PASSED\n\n");
}

int main(){
    test_dll();
    return 0;
}