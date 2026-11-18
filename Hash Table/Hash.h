#ifndef _INCLUDED_HASH_
#define _INCLUDED_HASH_

#include<stdint.h>
#include<stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _list_node_ List;
typedef struct _hash_table_ HashTable;

struct _list_node_ {
    char element[30];
    List *next;
};

struct _hash_table_{
    uint32_t tablesize;
    List **thelists;
};

HashTable htb_new(uint32_t size);
HashTable* htb_insert(HashTable *htb, char *data);
HashTable* htb_delete(HashTable *htb, char *data);
HashTable* htb_destroy(HashTable *htb);
uint32_t htb_find(HashTable *htb, char *key);




#endif