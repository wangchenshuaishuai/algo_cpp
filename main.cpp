#include <iostream>
#include "printarr.h"
#include "printall.h"
#include "SortTestingHelper.h"

#include "quicksort.h"
#include "SelectionSort.h"

using std::cout;

void printCompileTime(){
    cout << __DATE__ << " " << __TIME__ << "\r\n";
}

int main(int argc, char* argv[]){
    printCompileTime();
    int *arr = SortTestHelp::generateRandomArray(8, 16, 998);
    printall(arr, 8);
    SelectionSort<int>(arr, 8);
    // quicksort(arr, 0, 7);
    printarr(arr, 8);

    std::string barr[] = {"a", "x","c","f"};
    printall(barr, 4);
    SelectionSort(barr, 4);
    printall(barr, 4);

    delete arr;
    return 1;
}