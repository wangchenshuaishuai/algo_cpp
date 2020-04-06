#ifndef _SELECTION_SORT_H
#define _SELECTION_SORT_H
#include <algorithm>
#include <iostream>
#include "SortTestingHelper.h"
/**
 * 选择排序 方案0
 */ 
template <typename T>
void selectionSort(T arr[], int n){
    for(int i=0; i<n; i++){
        int minIndex = i;
        for(int j=i+1; j<n; j++){   //遍历一次，查找最小值
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        std::swap(arr[i], arr[minIndex]);   //将最小值元素，与开头元素交换
    }
}

/**
 * 选择排序 方案1
 * 优化点: 遍历一次时，同时查找最小和最大值
 */ 
template<typename T>
void selectionSortImprove1(T arr[], int n){
    for( int i=0; i<n/2; i++){
        int minIndex = i;
        int maxIndex = n-i-1;
        // std::cout << "minIndex: " << minIndex << "  maxIndex:" <<maxIndex << "       ";
        for(int j=i; j<n-i; j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
            if(arr[j] > arr[maxIndex]){
                maxIndex = j;
            }
        }
        // std::cout << "min: arr[" << minIndex << "]: " << arr[minIndex];
        // std::cout << "    max: arr[" << maxIndex << "]: " << arr[maxIndex] << "\r\n";

        if(i+1 == n-i-1){
            std::swap(arr[i], arr[minIndex]);
            // cout << "once" << "\r\n"<< endl;
            // SortTestHelper::printArray(arr, n);
            return;

        }else{
            if(maxIndex == i){
                maxIndex = minIndex;
            }
            std::swap(arr[i], arr[minIndex]);
            std::swap(arr[n-i-1], arr[maxIndex]);                    
        }

        // SortTestHelper::printArray(arr, n);
    }
}
#endif