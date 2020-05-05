#ifndef _HEAP_SORT_H
#define _HEAP_SORT_H

// #include "heap.h"
#include "../heap/heap.h"
#include "../heap/Excep.h"
#include "SortTestingHelper.h"
#include <iostream>
template<typename T>
void heapSort1(T arr[], int n){
    // std::cout << "n:" << n << "\r\n";

    Heap<T> heap = Heap<T>(n);
    for(int i=0; i<n; i++){
        heap.insert(arr[i]);
    }
    for(int i=n-1; i>=0; i--){
        try{
            arr[i] = heap.extractMax();
        }catch(Excep ex){
            std::cout << ex.info << "\r\n";
        }
    }
}

template<typename T>
void heapSort2(T arr[], int n){
    // std::cout << "n:" << n << "\r\n";

    Heap<T> heap = Heap<T>(arr, n);
    for(int i=n-1; i>=0; i--){
        try{
            arr[i] = heap.extractMax();
        }catch(Excep ex){
            std::cout << ex.info << "\r\n";
        }
    }
}

template<typename T>
void shiftDown(T arr[], int k, int n){
    T v = arr[k];
    while(k*2+1 < n){
        int j = k*2+1;
        if(j+1<n && arr[j+1]>arr[j]){
            j++;
        }
        if(v < arr[j]){
            // std::swap(arr[k], arr[j]);
            arr[k] = arr[j];
            k = j;
        }else{
            break;
        }
    }
    arr[k] = v;
}

template<typename T>
void createHeap(T arr[], int n){
    for(int i=(n-2)/2; i>=0; i--){
        shiftDown(arr, i, n);
    }
}

template<typename T>
void heapSort3(T arr[], int n){
    createHeap(arr, n);
    for(int i=n-1; i>=0; i--){
        std::swap(arr[0], arr[i]);
        shiftDown(arr, 0, i);
    }
}

#endif