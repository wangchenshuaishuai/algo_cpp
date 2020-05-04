#ifndef _HEAP_H
#define _HEAP_H
#include <string.h>
#include "test.h"
#include "Excep.h"
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
    std::string toString();
    T extractMax();
private:
    void shiftUp(int index);
    void shiftDown(int index);
    void capacityExpand();
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
    count = n;

    for(int i=count/2; i>=1; i--){
        shiftDown(i);
    }
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
void Heap<T>::capacityExpand(){
    if((count+1) > capacity){
        // std::cout << "capacity:" << capacity << "  count:" << count << std::endl;
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
}

template<typename T>
void Heap<T>::insert(T item){
    capacityExpand();
    pData[++count] = item;
    shiftUp(count);
}

/**
 * 向堆中插入一个元素
 * 过程：和其父节点比较，如果元素比父节点大，则交换
 */ 
template<typename T>
void Heap<T>::shiftUp(int n){
    for(int i = n; i>1; i/=2){
        if(pData[i] > pData[i/2]){
            std::swap(pData[i], pData[i/2]);
        }else{
            break;
        }
    }
}

template<typename T>
void Heap<T>::shiftDown(int n){
    T c = pData[n];
    // int v = n;
    while(2*n <= count){
        int j = 2*n;
        if(j+1<=count && pData[j+1]>pData[j]){
            j++;
        }

        if(c >= pData[j]){
            break;
        }else{
            // std::swap(pData[n], pData[j]);
            pData[n] = pData[j];
            n = j;
        }
    }
    pData[n] = c;
}

template<typename T>
T Heap<T>::extractMax(){
    if(count == 0){
        throw Excep("heap empty");
    }
    
    std::swap(pData[1], pData[count]);
    count--;

    shiftDown(1);
    return pData[count+1];
}

template<typename T>
std::string Heap<T>::toString(){
    std::string ret = "";
    for(int i=0; i<count; i++){
        ret.append(std::to_string(pData[i+1]));
        ret.append(" ");
    }

    return ret;
}




#endif