#include "Bubble.h"

int* sort(int arr[], int n){
    for(int i = 0 ;  i < n; i++){
        for(int j = i+1 ; j < n; j++){
            if ( arr[j] < arr[i]){
                int t = arr[i];
                arr[i] = arr[j];
                arr[j] = t;
            }
        }
    }
    return arr;
}
