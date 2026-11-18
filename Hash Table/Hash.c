#include "Hash.h"
#include <assert.h>
#include <stddef.h>
#include <stdint.h>


HashTable htb_new(uint32_t size){
    HashTable htb;
    htb.tablesize = size;
    htb.thelists = (List**)malloc(sizeof(List*)*htb.tablesize);
    for(int i = 0 ; i <  htb.tablesize;i++){
        htb.thelists[i] = NULL;
    }
    return htb;
}

static uint32_t _hash_(char *key,uint32_t tablesize){

    uint32_t hashval=0;

    while(*key != '\0'){
        hashval+= *key++;
    }
    return hashval%tablesize;
}

uint32_t htb_find(HashTable *htb, char *key){
    uint32_t bucket = _hash_(key, htb -> tablesize);
    List *temp = htb -> thelists[bucket];

    while(temp != NULL){
        if(!strcmp(temp->element,key)){
            break;
        }
        else{
            temp = temp -> next;
        }
    }
    return temp != NULL;
}


HashTable* htb_insert(HashTable *htb, char *data){

    uint32_t bucket;
    List *oldaddr;

    if(!htb_find(htb, data)){
        bucket = _hash_(data, htb->tablesize);
        oldaddr = htb -> thelists[bucket];
        htb -> thelists[bucket] = (List*)malloc(sizeof(List));
        strcpy(htb->thelists[bucket]->element,data);
        htb->thelists[bucket]->next=oldaddr;
    }
    return htb;
}


HashTable* htb_delete(HashTable *htb, char *data){
    List *curr,*temp;
    uint32_t bucket;

    bucket = _hash_(data,htb->tablesize);

    if(htb->thelists[bucket]!=NULL){
        if(!strcmp(htb->thelists[bucket]->element,data)){
            temp = htb->thelists[bucket];
            htb->thelists[bucket] = htb->thelists[bucket]->next;
            free(temp);
        }
        else{
            curr = htb -> thelists[bucket];
            while(curr -> next != NULL){
                if(!strcmp(curr->element,data)){
                    temp = curr -> next;
                    curr -> next = curr -> next -> next;
                    free(temp);
                }
                else{
                    curr = curr -> next;
                }
            }
        }
    }
    return htb;
}

HashTable* htb_destroy(HashTable *htb){
    List *curr , *temp;

    for(int i = 0 ; i < htb -> tablesize ;i++){
        temp = htb -> thelists[i];
        while(temp != NULL){
            curr = temp;
            temp = temp -> next;
            free(curr);
        }
        free(htb->thelists[i]);
    }
}