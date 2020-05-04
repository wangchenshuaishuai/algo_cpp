#include <iostream>
#include "heap.h"
int main(int argc, char *argv[]){
    std::cout << "========begin========" << std::endl;
    int array[] = {80, 70, 75, 43, 15, 100, 57, 62, 17, 23, 90};

    Heap<int> heap;
    for(int i=0; i<11; i++){
        heap.insert(array[i]);
    }
    std::cout <<"heap size:" << heap.size() << "  capacity" << heap.Capacity() << std::endl;
   
    std::cout <<"algo world" << std::endl;
    return 1;
}


