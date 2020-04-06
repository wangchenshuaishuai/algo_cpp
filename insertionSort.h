#ifndef _INSERTIONSORT_H
#define _INSERTIONSORT_H

template<typename T>
void insertionSort(T arr[], int n){
    for(int i=1; i<n; i++){
        // for(int j=i; j>0; j--){  //1st
        //     if(arr[j] < arr[j-1]){
        //         swap(arr[j], arr[j-1]);
        //     }else{
        //         break;
        //     }
        // }

        // for(int j=i; (j>0)&&(arr[j]<arr[j-1]); j--){ //2nd
        //     swap(arr[j], arr[j-1]);
        // }

        T e = arr[i];
        int j;  //保存元素e应该插入的位置
        for(j=i; j>0 && arr[j-1]>e; j--){
            arr[j] = arr[j-1];
        }
        arr[j] = e;
    }
}

#endif