#include <iostream>
// #include "printarr.h"
// #include "printall.h"
#include "SortTestingHelper.h"

#include "quicksort.h"
#include "SelectionSort.h"
#include "insertionSort.h"
#include "bubbleSort.h"
#include "mergeSort.h"

using std::cout;

void printCompileTime(){
    cout << __DATE__ << " " << __TIME__ << "\r\n";
}

int main(int argc, char* argv[]){
    cout << "====== main ======\r\n";
    for ( int i=0; i<argc; i++){
        cout << argv[i] << endl;
    }
    cout << "\r\n" ;

    int n = 10000;
    if(argc >= 2){
        std::string count(argv[1]);
        n = std::stoi(count);
    }

    printCompileTime();
    
    
    int *arr[7];
    int i=0;
    arr[i++] = SortTestHelper::generateRandomArray(n, 1, n);
    // arr[i++] = SortTestHelper::generateNearlyOrderedArray(n, 0);
    arr[i++] = SortTestHelper::copyArray<int>(arr[0], n);
    arr[i++] = SortTestHelper::copyArray<int>(arr[0], n);
    arr[i++] = SortTestHelper::copyArray<int>(arr[0], n);
    arr[i++] = SortTestHelper::copyArray<int>(arr[0], n);
    arr[i++] = SortTestHelper::copyArray<int>(arr[0], n);
    arr[i++] = SortTestHelper::copyArray<int>(arr[0], n);


    int j=0;
    // SortTestHelper::printArray(arr[0], n);
    // insertionSort(arr[0], 0, n-1);
    // SortTestHelper::printArray(arr[0], n);   

    SortTestHelper::testSort("merge sort", mergeSort0, arr[j++], n);
    SortTestHelper::testSort("merge sort", mergeSort1, arr[j++], n);
    SortTestHelper::testSort("insertion sort", insertionSort, arr[j++], n);
    // SortTestHelper::testSort("selection sort", selectionSort, arr[j++], n);
    // SortTestHelper::testSort("selection sort1", selectionSortImprove1, arr[j++], n);
    // SortTestHelper::testSort("bubble sort", bubbleSort, arr[j++], n);
    // SortTestHelper::testSort("bubble sort1", bubbleSortImprove1, arr[j++], n);
    // SortTestHelper::testSort("bubble sort2", bubbleSortImprove2, arr[j++], n);


    
    for(int k=0; k<i; k++){
        delete[] arr[k];
    }

    // delete arr;
    return 1;
}