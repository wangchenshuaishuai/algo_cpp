#include <iostream>
// #include "printarr.h"
// #include "printall.h"
#include "SortTestingHelper.h"

#include "quicksort.h"
#include "SelectionSort.h"
#include "insertionSort.h"
#include "bubbleSort.h"

using std::cout;

void printCompileTime(){
    cout << __DATE__ << " " << __TIME__ << "\r\n";
}

int main(int argc, char* argv[]){
    printCompileTime();
    const int n = 150001;
    // int *arr1 = SortTestHelper::generateRandomArray(n, 1, n);
    int *arr[6];
    int i=0;
    // arr[i++] = SortTestHelper::generateRandomArray(n, 1, n);
    arr[i++] = SortTestHelper::generateNearlyOrderedArray(n, 10);
    arr[i++] = SortTestHelper::copyArray<int>(arr[0], n);
    arr[i++] = SortTestHelper::copyArray<int>(arr[0], n);
    arr[i++] = SortTestHelper::copyArray<int>(arr[0], n);
    arr[i++] = SortTestHelper::copyArray<int>(arr[0], n);
    arr[i++] = SortTestHelper::copyArray<int>(arr[0], n);

    int j=0;
    // SortTestHelper::printArray(arr[j], n);
    SortTestHelper::testSort("selection sort", selectionSort, arr[j++], n);
    SortTestHelper::testSort("selection sort1", selectionSortImprove1, arr[j++], n);
    SortTestHelper::testSort("insertion sort", insertionSort, arr[j++], n);
    SortTestHelper::testSort("bubble sort", bubbleSort, arr[j++], n);
    SortTestHelper::testSort("bubble sort1", bubbleSortImprove1, arr[j++], n);
    SortTestHelper::testSort("bubble sort2", bubbleSortImprove2, arr[j++], n);
    
    for(int k=0; k<i; k++){
        delete[] arr[k];
    }

    // delete arr;
    return 1;
}