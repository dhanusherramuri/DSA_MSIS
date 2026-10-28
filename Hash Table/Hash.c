#include "Hash.h"
#include <assert.h>
#include <stddef.h>
#include <stdint.h>

HashTable hashtable_new(uint32_t size){
    HashTable h;
    int i;
    h.tablesize = size;
    h.thelists = (List**)malloc(sizeof(List*) * size);
    for(i = 0 ;i < h.tablesize ; i++){
        h.thelists[i] = NULL;
    }
    return h;
}

static uint32_t _hash_(char *key,uint32_t tablesize){
    uint32_t hashval = 0;
    while(*key != '\0'){
        hashval+=*key++;
    }
    return hashval % tablesize;
}

uint32_t hashtable_find(HashTable *htb,char *key){
    List *list = htb -> thelists[_hash_(key,htb->tablesize)];
    while(list!=NULL){
        if(!strcmp(list->element,key)){
            break;
        }
        else{
            list = list -> next;
        }
    }
    return list!=NULL;
}

HashTable* hashtable_insert_element(HashTable *htb, char *data){
    uint32_t bucket;
    List *oldAddress;
    if(!hashtable_find(htb,data)){
        bucket = _hash_(data,htb->tablesize);
        oldAddress = htb -> thelists[bucket];
        htb -> thelists[bucket] = (List*)malloc(sizeof(List));
        strcpy(htb->thelists[bucket]->element, data);
        htb -> thelists[bucket]->next = oldAddress;
    }
    return htb;
}

HashTable* hashtable_delete_element(HashTable *htb, char *data){
    List *current, *temp;
    uint32_t bucket = 0;
    bucket = _hash_(data, htb -> tablesize);
    if(htb -> thelists[bucket]!=NULL){
        if(!strcmp(htb->thelists[bucket]->element,data)){
            temp = htb -> thelists[bucket];
            htb -> thelists[bucket]= htb -> thelists[bucket]->next;
            free(temp);
        }
        else{
            current = htb -> thelists[bucket];
            while(current->next != NULL){
                if(!strcmp(current->next->element,data)){
                    temp = current -> next;
                    current -> next = current -> next -> next;
                    free(temp);
                    break;
                }
                else{
                    current = current -> next;
                }
            }
        }
    }
    return htb;
}

void hashtable_destroy(HashTable *htb){
    int i;
    List *current, *temp;
    for(i = 0;i < htb->tablesize;i++){
        current = htb -> thelists[i];
        while(current != NULL){
            temp = current;
            current = current -> next;
            free(temp);
        }
    }
    free(htb -> thelists[i]);
}