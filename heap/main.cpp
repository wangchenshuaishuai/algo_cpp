#include <iostream>
#include "heap.h"
#include "IndexHeap.h"
using namespace std;
int main(int argc, char *argv[]){
    std::cout << "========begin========" << std::endl;
    int array[] = {80, 70, 75, 43, 15, 100, 57, 62, 17, 23, 90};

    Heap<int> heap = Heap<int>(array, sizeof(array)/sizeof(int));
    // for(int i=0; i<20; i++){
    //     heap.insert(rand()%100);
    // }
    cout <<"heap size:" << heap.size() << "  capacity" << heap.Capacity() << endl;
   
    cout <<heap.toString() << "\r\n";

    int heapSize = heap.size();
    for(int i=0; i<heapSize; i++){
        cout << heap.extractMax() << " ";
    }
    return 1;
}


