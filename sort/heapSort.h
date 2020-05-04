#ifndef _HEAP_SORT_H
#define _HEAP_SORT_H

// #include "heap.h"
#include "../heap/heap.h"
#include "../heap/Excep.h"
#include "SortTestingHelper.h"
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

#endif