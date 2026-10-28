#include "Hash.h"
#include <assert.h>
#include <stdio.h>

void test(void) {
    HashTable h = hashtable_new(10);

    hashtable_insert_element(&h, "apple");
    hashtable_insert_element(&h, "banana");
    hashtable_insert_element(&h, "orange");

    assert(hashtable_find(&h, "apple") == 1);
    assert(hashtable_find(&h, "banana") == 1);
    assert(hashtable_find(&h, "grape") == 0);

    hashtable_delete_element(&h, "banana");

    assert(hashtable_find(&h, "banana") == 0);
    assert(hashtable_find(&h, "apple") == 1);

    hashtable_destroy(&h);

    printf("All tests passed!\n");
}

int main(void) {
    test();
    return 0;
}