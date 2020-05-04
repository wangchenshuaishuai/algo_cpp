#ifndef _HEAP_H
#define _HEAP_H
#include "test.h"
#include <string.h>
template<typename T>
class Heap{
private:
    T *pData;
    int count;
    int capacity;

public:
    Heap();
    Heap(int capacity);
    Heap(T arr[], int n);
    ~Heap();
    int size();
    bool empty();
    void insert(T item);
    int Capacity();
private:
    void shiftUp(int index);
};

template<typename T>
Heap<T>::Heap(int capacity){
    pData = new T[capacity+1];
    count = 0;
    this->capacity = capacity;
}

template<typename T>
Heap<T>::Heap(){
    capacity = 1;
    pData = new T[capacity+1];
    count = 0;
}

template<typename T>
Heap<T>::Heap(T arr[], int n){
    capacity = n;
    pData = new T[capacity+1];
    memcpy(pData+1, arr, n*sizeof(int));
    test::printAll(pData+1, n);
    count = n;
}

template<typename T>
Heap<T>::~Heap(){
    delete []pData;
}

template<typename T>
int Heap<T>::size(){
    return count;
}

template<typename T>
int Heap<T>::Capacity(){
    return this->capacity;
}

template<typename T>
bool Heap<T>::empty(){
    return count==0;
}

template<typename T>
void Heap<T>::insert(T item){

    if((count+1) > capacity){
        std::cout << "capacity:" << capacity << "  count:" << count << std::endl;
        if(capacity < 2 ){
            capacity++;
        }else{
            capacity = capacity + capacity/2;            
        }

        T *pTemp = new T[capacity+1];
        test::copy(pTemp, pData, count+1);
        delete[] pData;
        pData = new T[capacity+1];
        test::copy(pData, pTemp, capacity+1);
        delete[] pTemp;
    }
    pData[++count] = item;
    test::printAll(pData+1, count);
    shiftUp(count);
    test::printAll(pData+1, count);
}

template<typename T>
void Heap<T>::shiftUp(int index){
    for(int i = index; i>1; i/=2){
        if(pData[i] > pData[i/2]){
            std::swap(pData[i], pData[i/2]);
        }else{
            break;
        }
    }
}


#endif