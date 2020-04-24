#include <algorithm>
#include <iostream>
#include "SortTestingHelper.h"
template<typename T>

/**
 * 第一个版本
 * 开辟两个临时空间，分别存放：比基准值小的元素，比基准值大的元素
 */ 
void quickSort0(T arr[], int n){
    if(n<=1){
        return;
    }

    int c=arr[0]; //基准比较值，取第一个元素
    T *min = new T[n];  //临时空间: min[]
    T *max = new T[n];  //临时空间: max[]
    int ia = 0;
    int ib = 0;
    for(int i=1; i<n; i++){
        if(arr[i] < c){ //遍历数组
            min[ia++] = arr[i]; //存放比基准值小的部分
        }else{
            max[ib++] = arr[i]; //存放比基准值大的部分
        }
    }
    
    //合并 小/基准值/大
    for(int i=0; i<ia; i++){
        arr[i] = min[i];
    }
    arr[ia] = c;
    for(int j=0; j<ib; j++){
        arr[ia+j+1] = max[j];
    }

    //递归排序小部分和大部分
    quickSort(arr, ia);
    quickSort(arr+ia+1, ib);

    delete[] min;
    delete[] max;
}

template<typename T>
void __quickSort1(T arr[], int n){
    if(n <= 1){
        return;
    }

    int e = arr[0];
    int j = 0;
    for(int i=1; i<n; i++){
        if(arr[i] < e){
            std::swap(arr[j+1],arr[i]);
            j++;
        }
    }
    std::swap(arr[0], arr[j]);

    __quickSort1(arr, j);
    __quickSort1(&arr[j+1], n-(j+1));
}

/**
 * 第二个版本
 * 在原数组基础上移动数据
 */
template<typename T>
void quickSort1(T arr[], int n){
    __quickSort1(arr, n);
}


template<typename T>
void __quickSort2(T arr[], int left, int right){
    if(left >= right){
        return;
    }
    T v = arr[left];
    int j = left;
    for(int i=left+1; i<=right; i++){
        if(arr[i] < v){
            std::swap(arr[i], arr[j+1]);
            j++;
        }
    }
    swap(arr[left], arr[j]);
    __quickSort2(arr, left, j-1);
    __quickSort2(arr, j+1, right);
}

/**
 * 第三个版本
 * 使用left/right两个边界值
 */
template<typename T>
void quickSort2(T arr[], int n){
    __quickSort2(arr, 0, n-1);
}


template<typename T>
void __quickSort3(T arr[], int left, int right){
    if(left >= right){
        return;
    }
    
    T lt = left;
    T gt = right+1;
    T e = arr[left];
    
    for(int i=lt; i<gt; ){
        if(arr[i] < e){
            std::swap(arr[i], arr[lt+1]);
            lt++;
            i++;
        }else if(arr[i] > e){
            std::swap(arr[i], arr[gt-1]);
            gt--;
        }else{
            i++;
        }
    }

    std::swap(arr[left], arr[lt]);

    __quickSort3(arr, left, lt);
    __quickSort3(arr, gt, right);
}
/**
 * 第四个版本
 * 优化重复数，反复划分的问题
 * 使用三分法
 */ 
template<typename T>
void quickSort3(T arr[], int n){
    __quickSort3(arr, 0, n-1);
}
