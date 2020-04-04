#ifndef _SORT_TEST_HELP_H
#define _SORT_TEST_HELP_H
#include <iostream>
#include <ctime>
#include <cassert>

using namespace std;
namespace SortTestHelp{
    int* generateRandomArray(int n, int rangeL, int rangeR){

        assert(rangeL <= rangeR);
        int *arr = new int[n];
        srand(time(NULL));
        for(int i=0; i<n; i++){
            arr[i] = rand() % (rangeR - rangeL + 1);
        }
        return arr;
    }
}
#endif