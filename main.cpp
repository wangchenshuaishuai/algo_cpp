#include <iostream>
#include <vector>
#include "SortTestingHelper.h"

#include "SelectionSort.h"
#include "insertionSort.h"
#include "bubbleSort.h"
#include "mergeSort.h"
#include "quicksort.h"

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
    // arr[i++] = SortTestHelper::generateRandomArray(n, 1, n);
    cout << "sort begin: " << "\r\n";
    arr[i++] = SortTestHelper::generateNearlyOrderedArray(n, 0);
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
    SortTestHelper::testSort("quick sort", quickSort1, arr[j++], n);
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