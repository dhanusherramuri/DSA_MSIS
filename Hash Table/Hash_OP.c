#include "Hash.h"
#include <assert.h>
#include <stdio.h>

void test(void) {
    HashTable h = htb_new(10);

    htb_insert(&h, "apple");
    htb_insert(&h, "banana");
    htb_insert(&h, "orange");

    assert(htb_find(&h, "apple") == 1);
    assert(htb_find(&h, "banana") == 1);
    assert(htb_find(&h, "grape") == 0);

    htb_delete(&h, "banana");

    assert(htb_find(&h, "banana") == 0);
    assert(htb_find(&h, "apple") == 1);

    htb_destroy(&h);

    printf("All tests passed!\n");
}

int main(void) {
    test();
    return 0;
}