#include <stdio.h>
#include <stdlib.h>

int partition(int a[],int low,int high){
    int pivot = a[low];
    int l = low;
    int h = high;

    while(l<h){
        while(a[l]<=pivot && l < high){
            l++;
        }
        while(a[h] >= pivot && h > low){
            h--;
        }
        if(l < h){
            int t = a[l];
            a[l] = a[h];
            a[h] = t;
        }
    }
    int t = a[low];
    a[low] = a[h];
    a[h] = t;

    return h;
}


void QuickSort(int a[],int low,int high){
    if(low < high){
        int j = partition(a,low,high);
        QuickSort(a,low,j-1);
        QuickSort(a,j+1,high);
    }
}

int main(){
   int arr [] = {20,52,1,0,26};
    QuickSort(arr,0,4);
    for(int i = 0; i < 5; i++){
        printf("%d ",arr[i]);
    }
}