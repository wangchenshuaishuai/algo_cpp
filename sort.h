#ifndef _SORT_H
#define _SORT_H
#include <iostream>
#include <argorithm>

template <typename T>
class QuickSort{
public:
    QuickSort(){};
    ~QuickSort(){};

    int partition(T arr[], int low, int high){
        if(low < high){
            for(int i=low; i<high; i++){
                if(arr[i])
            }
        }
    }
    void sort(T arr[], int low, int high){
        if(low < high){
            int i = partition(arr, low, high);
            sort(arr, low, i);
            sort(arr, i, high);
        }
    }
}


#endif