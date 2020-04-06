#ifndef _SORT_TEST_HELP_H
#define _SORT_TEST_HELP_H
#include <iostream>
#include <ctime>
#include <cassert>

using namespace std;
namespace SortTestHelper{
    int* generateRandomArray(int n, int rangeL, int rangeR){

        assert(rangeL <= rangeR);
        int *arr = new int[n];
        srand(time(NULL));
        for(int i=0; i<n; i++){
            arr[i] = rand() % (rangeR - rangeL + 1);
        }
        return arr;
    }

    int* generateNearlyOrderedArray(int n, int swapTimes){
        int *arr = new int[n];
        for(int i=0; i<n; i++){
            arr[i] = i;
        }

        srand(time(NULL));
        for(int i=0; i<swapTimes; i++){
            int posx = rand() % n;
            int posy = rand() % n;
            swap(arr[posx], arr[posy]);
        }

        return arr;
    }

    template<typename T>
    void printArray(T arr[], int n){
        for(int i=0; i<n; i++){
            std::cout << arr[i] << " ";
        }
        cout << std::endl;
    }

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

    template<typename T>
    void testSort( string sortName, void(*sort)(T[], int n), T arr[], int n){
        clock_t startTime = clock();
        sort(arr,n);
        clock_t endTime = clock();
        
        assert(isSorted(arr,n));
        cout << sortName << " " << double(endTime-startTime)/CLOCKS_PER_SEC << " s" << endl;
    }

    template<typename T>
    T* copyArray(int arr[], int n){
        T *p = new T[n];
        clock_t startTime = clock();
        std::copy(arr, arr+n, p);
        clock_t endTime = clock();
        cout << "copyTime: " << double(endTime-startTime)/CLOCKS_PER_SEC << " s" << endl;
        return p;
    }

}
#endif 