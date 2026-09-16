#include "Merge.h"

void test(){
    int arr [] = {20,52,1,0,26};
    mergesort(arr,0,4);
    for(int i = 0; i < 5; i++){
        printf("%d ",arr[i]);
    }
}

int main(){
    test();
    return 0;
}