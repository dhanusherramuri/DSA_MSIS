#ifndef _INCLUDED_HEAP_
#define _INCLUDED_HEAP_
#define MAX_HEAP_SIZE 16

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

typedef struct _heap_ Heap;

struct _heap_{
    uint32_t size;
    int32_t data[MAX_HEAP_SIZE];
};

Heap heap_new(int32_t data[],int len);
void heap_delete(Heap *heap);
Heap* heap_sort(Heap *heap);
Heap* heap_insert(Heap *heap,int32_t key);
int32_t heap_get_max(Heap *heap);
int32_t heap_extract_max(Heap *heap);
int32_t heap_size(Heap *heap);



#endif