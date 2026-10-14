#include "Heap.h"

void test(){
    printf("Starting Max-Heap tests...\n");

    int32_t initial_data[] = {-1, 10, 20, 15, 30, 40};
    int len = 5;
    Heap my_heap = heap_new(initial_data, len);
    Heap *heap_ptr = &my_heap;
    
    assert(heap_size(heap_ptr) == 5);
    assert(heap_get_max(heap_ptr) == 40);
    printf("Heap creation and initial heapify passed.\n");

    heap_ptr = heap_insert(heap_ptr, 50);
    assert(heap_size(heap_ptr) == 6);
    assert(heap_get_max(heap_ptr) == 50);
    printf("Insertion of larger element passed.\n");

    int32_t max_val = heap_extract_max(heap_ptr);
    assert(max_val == 50);
    assert(heap_size(heap_ptr) == 5);
    assert(heap_get_max(heap_ptr) == 40); 
    printf("Maximum extraction passed.\n");

    for(int i = 0; i < 10; i++) {
        heap_ptr = heap_insert(heap_ptr, i);
    }
    assert(heap_size(heap_ptr) == 15); 
    printf("Boundary conditions and capacity limits passed.\n");

    heap_ptr = heap_sort(heap_ptr);
    printf("Heap sort execution passed.\n");
    for(int i = 1 ; i < 10;i++)
    printf("%d \t" ,heap_ptr->data[i]);

    heap_delete(heap_ptr);
    printf("\nHeap deletion passed.\n");

    printf("All Max-Heap test suites passed successfully!\n\n");
}

int main(){
    test();
    return 0;
}
