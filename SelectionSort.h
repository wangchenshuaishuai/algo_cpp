#ifndef _SELECTION_SORT_H
#define _SELECTION_SORT_H
#include <algorithm>

template <typename T>
void SelectionSort(T arr[], int n){
    for(int i=0; i<n; i++){
        int minIndex = i;
        for(int j=i+1; j<n; j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        std::swap(arr[i], arr[minIndex]);
    }
}
#endif