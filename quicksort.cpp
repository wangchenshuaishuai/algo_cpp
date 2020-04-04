#include "quicksort.h"
#include <iostream>
#include <algorithm>
using std::cout;

int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = low-1;

    for(int j=low; j<=high-1; j++){
        if(arr[j] <= pivot){ 
            i++;
            cout << "swap " << i << " and " << j << "\r\n";
            std::swap(arr[i], arr[j]);
        }
    }

    cout << "swap " << i+1 << " and " << high << "\r\n";
    std::swap(arr[i+1], arr[high]);
    return (i+1);
}

void quicksort(int arr[], int low, int high){
    if(low < high){
        int pi = partition(arr, low, high);

        quicksort(arr, low, pi-1);
        quicksort(arr, pi+1, high);
    }
}