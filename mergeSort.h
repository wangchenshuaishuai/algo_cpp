#ifndef _MERGE_SORT_H
#define _MERGE_SORT_H
#include "SortTestingHelper.h"

/**
 * first version designed by myself
 */ 
template<typename T>
void mergeSort0(T arr[], int n){
    if(n>2){
        mergeSort0(arr, n/2);
        mergeSort0(arr+(n/2), n-(n/2));
    }

    // int k = 0; 
    int i = 0;
    int j = 0;
    int devide = n/2;
    j += devide;

    T *copy = SortTestHelper::copyArray<T>(arr, n);
    for(int k=0; k<n; k++){
        if(i >= devide){
            arr[k] = copy[j++];
        }else if (j>=n){
            arr[k] = copy[i++];
        }else if(copy[i] < copy[j]){
            arr[k] = copy[i++];
        }else{
            arr[k] = copy[j++];
        }
    }
    
    delete[] copy;
    return;
}

template<typename T>
void __merge(T arr[], int left, int mid, int right){
    // T *temp = SortTestHelper::copyArray<T>(arr, right-left+1);
    T *temp = new T[right-left+1];
    for (int i=0; i<right-left+1; i++){
        temp[i] = arr[left+i];
    }
    int a = 0;
    int b = mid-left+1;
    for(int i=left; i<=right; i++){
        if(a+left > mid){
            arr[i] = temp[b++];
        }else if(b+left > right){
            arr[i] = temp[a++];
        }else if(temp[a]<temp[b]){
            arr[i] = temp[a++];
        }else{
            arr[i] = temp[b++];
        }
    }
}

template<typename T>
void __mergeSort(T arr[], int left, int right){
    // if(left >= right){
    //     return;
    // }
    if( right - left < 16 ){
        insertionSort(arr, left, right);
        return;
    }

    int mid = (left+right)/2;
    __mergeSort(arr, left, mid);
    __mergeSort(arr, mid+1, right);
    if(arr[mid] > arr[mid+1]){  //如果数组已经有序，则无需归并排序
        __merge(arr, left, mid, right);        
    }
}
/**
 * second version from tutorial
 */
template<typename T>
void mergeSort1(T arr[], int n){
    __mergeSort(arr, 0, n-1);
}


template<typename T>
void mergeSortBU(T arr[], int n){
    for(int sz=1; sz<n; sz*=2){
        for(int i=0; i+sz<n; i+=2*sz){
            __merge(arr,i, i+sz-1, std::min(i+2*sz-1, n-1));            
        }
    }
}



#endif