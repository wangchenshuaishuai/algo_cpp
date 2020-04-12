#include <algorithm>
#include "SortTestingHelper.h"
template<typename T>

/**
 * 第一个版本
 * 开辟两个临时空间，分别存放：比基准值小的元素，比基准值大的元素
 */ 
void quickSort(T arr[], int n){
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

/**
 * 第二个版本
 * 在原数组基础上移动数据
 */
template<typename T>
void quickSort1(T arr[], int n){
    // cout << "n: " << n << std::endl;
    if(n <= 1){
        return;
    }
    // if(n <= 15){
    //     insertionSort(arr, 0, n-1);
    //     return;
    // }
    int x = n/2;
    swap(arr[0], arr[x]);
    int e = arr[0];
    int j = 0;
    for(int i=1; i<n; i++){
        if(arr[i] < e){
            std::swap(arr[j+1],arr[i]);
            j++;
        }
    }
    swap(arr[0], arr[j]);

    quickSort1(arr, j);
    quickSort1(&arr[j+1], n-(j+1));
}

template<typename T>
void __quickSort(T arr[], int n){
    if(n <= 1){
        return;
    }

    int e = arr[0];
    int j = 0;
    for(int i=1; i<n; i++){
        if(arr[i] < e){
            std::swap(arr[j+1] = arr[i]);
            j++;
        }
    }
    swap(arr[0], arr[j]);

    __quickSort(arr, j);
    __quickSort(&arr[j+1], n-(j+1));
}