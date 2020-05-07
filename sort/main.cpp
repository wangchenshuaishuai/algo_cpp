#include <iostream>
#include <vector>
#include "SortTestingHelper.h"

#include "SelectionSort.h"
#include "insertionSort.h"
#include "bubbleSort.h"
#include "mergeSort.h"
#include "quickSort.h"
#include "heapSort.h"
#include "../search/binarySearch.h"

using std::cout;

#define COUNT_OF(arr) ((sizeof(arr)/sizeof(arr[0])))

void printCompileTime(){
    cout << __DATE__ << " " << __TIME__ << "\r\n";
}

template<typename T>
void testHeap3(T arr[], int n){
    SortTestHelper::printArray(arr, n);
    createHeap(arr, n);
    SortTestHelper::printArray(arr, n);
    heapSort3(arr, n);
    SortTestHelper::printArray(arr, n);
}

void testBinarySearch(){
    int buffer[] = {1,2,5,6,8,9,11,13,16,16,19,20,26,27,38,38,38, 40};
    BinarySearch<int> objSearch;
    cout << "binary search 0:" << objSearch.binarySearch(buffer, COUNT_OF(buffer), 5) << endl;
    cout << "floor:" << objSearch.getFloor() << "  cell:" << objSearch.getCeil() << endl;

    cout << "binary search 0:" << objSearch.binarySearchRec(buffer, COUNT_OF(buffer), 38) << endl;
    cout << "floor:" << objSearch.getFloor() << "  cell:" << objSearch.getCeil() << endl;

}

int main(int argc, char* argv[]){
    cout << "====== main ======\r\n";
    for ( int i=0; i<argc; i++){
        cout << argv[i] << endl;
    }
    cout << "\r\n" ;

    int n = 10;
    if(argc >= 2){
        std::string count(argv[1]);
        n = atoi(count.c_str());
    }

    printCompileTime();

    testBinarySearch();

    int *arr[10];
    int i=0;
    arr[i++] = SortTestHelper::generateRandomArray(n, 1, 1000);
    cout << "sort begin:   n: " << n << "\r\n";
    // arr[i++] = SortTestHelper::generateNearlyOrderedArray(n, 0);
    arr[i++] = SortTestHelper::copyArray<int>(arr[0], n);
    arr[i++] = SortTestHelper::copyArray<int>(arr[0], n);
    arr[i++] = SortTestHelper::copyArray<int>(arr[0], n);
    arr[i++] = SortTestHelper::copyArray<int>(arr[0], n);
    arr[i++] = SortTestHelper::copyArray<int>(arr[0], n);
    arr[i++] = SortTestHelper::copyArray<int>(arr[0], n);
    arr[i++] = SortTestHelper::copyArray<int>(arr[0], n);
    arr[i++] = SortTestHelper::copyArray<int>(arr[0], n);
    arr[i++] = SortTestHelper::copyArray<int>(arr[0], n);

    int j=0;

    // cout << "begin    ";
    // SortTestHelper::printArray(arr[0], n);
    // SortTestHelper::testSort("quick sort", quickSort, arr[j++], n);
    // testHeap3(arr[j++], n);
    SortTestHelper::testSort("heap sort1", heapSort1, arr[j++], n);
    SortTestHelper::testSort("heap sort2", heapSort2, arr[j++], n);
    SortTestHelper::testSort("heap sort3", heapSort3, arr[j++], n);
    SortTestHelper::testSort("quick sort1", quickSort1, arr[j++], n);
    SortTestHelper::testSort("quick sort2", quickSort2, arr[j++], n);
    SortTestHelper::testSort("quick sort3", quickSort3, arr[j++], n);
    SortTestHelper::testSort("merge sort", mergeSort0, arr[j++], n);
    SortTestHelper::testSort("merge sort", mergeSort1, arr[j++], n);
    SortTestHelper::testSort("merge sort", mergeSortBU, arr[j++], n);
    // SortTestHelper::testSort("insertion sort", insertionSort, arr[j++], n);
    // SortTestHelper::testSort("selection sort", selectionSort, arr[j++], n);
    // SortTestHelper::testSort("selection sort1", selectionSortImprove1, arr[j++], n);
    // SortTestHelper::testSort("bubble sort", bubbleSort, arr[j++], n);
    // SortTestHelper::testSort("bubble sort1", bubbleSortImprove1, arr[j++], n);
    // SortTestHelper::testSort("bubble sort2", bubbleSortImprove2, arr[j++], n);

    vector<int> vtest(n);
    for(int i=0; i<n; i++){
        vtest[i] = arr[5][i];
    }
    
    clock_t startTime = clock();
    std::sort(vtest.begin(), vtest.end());
    clock_t endTime = clock();
    cout << "vector sort: " << double(endTime-startTime)/CLOCKS_PER_SEC << " s" << endl;

   
    for(int k=0; k<i; k++){
        delete[] arr[k];
    }

    // delete arr;
    return 1;
}