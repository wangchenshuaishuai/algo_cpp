/**
 * Function：测试辅助函数
 * Author: wangchenshuaishuai
 * 
 */


 #ifndef _SORT_TEST_HELP_H
#define _SORT_TEST_HELP_H
#include <iostream>
#include <ctime>
#include <cassert>

using namespace std;
namespace SortTestHelper{
    /**
     * 生成随机数组
     */ 
    int* generateRandomArray(int n, int rangeL, int rangeR){

        assert(rangeL <= rangeR);
        int *arr = new int[n];
        srand(time(NULL));
        for(int i=0; i<n; i++){
            arr[i] = rand() % (rangeR - rangeL + 1);
        }
        return arr;
    }

    /**
     * 生成近似有序的数组
     */ 
    int* generateNearlyOrderedArray(int n, int swapTimes){
        int *arr = new int[n];
        for(int i=0; i<n; i++){
            arr[i] = n-i;
        }

        srand(time(NULL));
        for(int i=0; i<swapTimes; i++){
            int posx = rand() % n;
            int posy = rand() % n;
            swap(arr[posx], arr[posy]);
        }

        return arr;
    }

    /**
     * 打印数组
     */ 
    template<typename T>
    void printArray(T arr[], int n){
        for(int i=0; i<n; i++){
            std::cout << arr[i] << " ";
        }
        cout << std::endl;
    }

    /**
     * 测试数组是否有序(即排序是否成功)
     */ 
    template<typename T>
    bool isSorted(T arr[], int n){
        for(int i=0; i<n-1; i++){
            if(arr[i] > arr[i+1])
            {
                return false;
            }
        }

        return true;
    }

    /**
     * 测试排序算法
     */ 
    template<typename T>
    void testSort( string sortName, void(*sort)(T[], int n), T arr[], int n){
        clock_t startTime = clock();
        sort(arr,n);
        clock_t endTime = clock();
        
        // printArray(arr, n);
        assert(isSorted(arr,n));
        cout << sortName << " " << double(endTime-startTime)/CLOCKS_PER_SEC << " s" << endl;
    }

    /**
     * copy数组
     * 用于不同排序算法，输入相同参数
     * 避免因输入参数不同，造成算法对比不准确
     */ 
    template<typename T>
    T* copyArray(int arr[], int n){
        T *p = new T[n];
        // clock_t startTime = clock();
        std::copy(arr, arr+n, p);
        // clock_t endTime = clock();
        // cout << "copyTime: " << double(endTime-startTime)/CLOCKS_PER_SEC << " s" << endl;
        return p;
    }

}
#endif 