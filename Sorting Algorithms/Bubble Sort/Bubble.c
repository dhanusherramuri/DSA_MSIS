#include "Bubble.h"

// int* sort(int arr[], int n){
//     for(int i = 0 ;  i < n; i++){
//         for(int j = 0 ; j < n; j++){
//             if ( arr[j] > arr[j+1]){
//                 int t = arr[j];
//                 arr[j] = arr[j+1];
//                 arr[j+1] = t;
//             }
//         }
//     }
//     return arr;
// }


int* sort(int arr[], int n){
    for(int i = 0 ;  i < n; i++){
        for(int j = i+1 ; j < n; j++){
            if ( arr[j] < arr[i]){
                int t = arr[j];
                arr[j] = arr[i];
                arr[i] = t;
            }
        }
    }
    return arr;
}
