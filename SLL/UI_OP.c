#include "UI.h"
#include <assert.h>

void test_UI(){
    List *a_list = list_new();
    assert(a_list->length == 0);
    list_add(a_list, 10);
    list_add(a_list, 20);
    list_add(a_list, 30);
    assert(a_list->length == 3);
    printf("\nLength of the list: %d\n", a_list->length);
    display_UI(a_list);

    printf("\n LIST B IS BEING CREATED\n");

    List *b_list = list_new();
    assert(b_list->length == 0);
    list_add(b_list, 20);
    list_add(b_list, 30);
    list_add(b_list, 40);
    assert(b_list->length == 3);
    printf("\nLength of the list: %d\n", b_list->length);
    display_UI(b_list);
   
    //CHECK THE UNION OF TWO LISTS
    printf("\n\n*******UNION********");
    List *d_list = list_new();
    list_union(a_list, b_list, d_list);
    printf("\nLength of the list: %d\n", d_list->length);
    display_UI(d_list);
    
    //CHECK THE INTERSECTION OF TWO LISTS
    printf("\n\n*******INTERSECTION********");
    List *c_list = list_new();
    list_intersect(a_list, b_list, c_list);
    printf("\nLength of the list: %d\n", c_list->length);
    display_UI(c_list);

    //CHECK A - B
    printf("\n\n******* A - B ********");
    List *e_list = list_new();
    list_diff(a_list, b_list, e_list);
    printf("\nLength of the list: %d\n", e_list->length);
    display_UI(e_list);
   
    printf("\nASSERTIONS PASSED\n");

}

int main(){
    test_UI();
    return 0;
}