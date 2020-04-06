#ifndef _BUBBLESORT_H
#define _BUBBLESORT_H
#include <algorithm>

/**
 * 冒泡排序 方案0
 */
template<typename T>
void bubbleSort(T arr[], int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n-i-1; j++){
            if(arr[j] > arr[j+1]){
                std::swap(arr[j], arr[j+1]);
            }
        }
    }
}

/**
 * 冒泡排序 方案1
 * 优化点：若需要排序的数组已经有序。则结束排序，避免重复遍历
 */
template<typename T>
void bubbleSortImprove1(T arr[], int n){
    for(int i=0; i<n; i++){
        bool flag = false;  //交换记录flag
        for(int j=0; j<n-i-1; j++){
            if(arr[j] > arr[j+1]){
                std::swap(arr[j], arr[j+1]);
                flag = true;    //记录有交换
            }
        }

        if(!flag){  //若无交换，则返回
            return;
        }
    }
}

/**
 * 冒泡排序 方案2
 * 优化点：记录已经排好序的末端，下次遍历时不在重复排序
 */ 
template<typename T>
void bubbleSortImprove2(T arr[], int n){
    int pos = n-1;
    for(int i=0; i<n; i++){
        bool flag = false;  //交换记录flag
        int posRecord = pos;
        for(int j=0; j<pos; j++){
            if(arr[j] > arr[j+1]){
                std::swap(arr[j], arr[j+1]);
                flag = true;    //记录有交换
                posRecord = j;
            }
        }

        pos = posRecord;

        if(!flag){  //若无交换，则返回
            return;
        }
    }
}

#endif