#include "printarr.h"
#include <iostream>
using std::cout;

void printarr(int arr[], int n){

    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << "\r\n";
}