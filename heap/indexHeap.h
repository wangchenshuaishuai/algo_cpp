#ifndef _INDEX_HEAP_H
#define _INDEX_HEAP_H
#include <string.h>
#include "test.h"
#include "Excep.h"
template<typename T>
class IndexHeap{
private:
    T *pData;
    int *pIndex;
    int *pReverse;
    int count;
    int capacity;

public:
    IndexHeap();
    IndexHeap(int capacity);
    IndexHeap(T arr[], int n);
    ~IndexHeap();
    void reverseInit();
    int size();
    bool empty();
    void insert(int index, T item);
    int Capacity();
    std::string toString();
    T extractMax();
    int extractIndexMax();
    T getItem(int i);
    void change(int i, T item);
private:
    void shiftUp(int index);
    void shiftDown(int index);
    void capacityExpand();
};

template<typename T>
IndexHeap<T>::IndexHeap(int capacity){
    pData = new T[capacity+1];
    pIndex = new int[capacity+1];
    pReverse = new int[capacity+1];
    reverseInit();
    count = 0;
    this->capacity = capacity;
}

template<typename T>
IndexHeap<T>::IndexHeap(){
    capacity = 1;
    pData = new T[capacity+1];
    pIndex = new int[capacity+1];
    pReverse = new int[capacity+1];
    reverseInit();
    count = 0;
}

template<typename T>
IndexHeap<T>::IndexHeap(T arr[], int n){
    capacity = n;
    pData = new T[capacity+1];
    pIndex = new int[capacity+1];
    pReverse = new int[capacity+1];
    reverseInit();

    memcpy(pData+1, arr, n*sizeof(int));
    count = n;

    for(int i=count/2; i>=1; i--){
        shiftDown(i);
    }
}

template<typename T>
void IndexHeap<T>::reverseInit(){
    for(int i=0; i<=capacity; i++){
        pReverse[i] = 0;
    }
}

template<typename T>
IndexHeap<T>::~IndexHeap(){
    delete []pData;
    delete []pIndex;
    delete []pReverse;
}

template<typename T>
int IndexHeap<T>::size(){
    return count;
}

template<typename T>
int IndexHeap<T>::Capacity(){
    return this->capacity;
}

template<typename T>
bool IndexHeap<T>::empty(){
    return count==0;
}

template<typename T>
void IndexHeap<T>::capacityExpand(){
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
void IndexHeap<T>::insert(int i, T item){
    capacityExpand();
    i++;
    pData[i] = item;
    pIndex[count+1] = i;
    pReverse[i] = count + 1;
    count++;
    shiftUp(count);
}

/**
 * 向堆中插入一个元素
 * 过程：和其父节点比较，如果元素比父节点大，则交换
 */ 
template<typename T>
void IndexHeap<T>::shiftUp(int n){
    for(int i = n; i>1; i/=2){
        if(pData[pIndex[i]] > pData[pIndex[i/2]]){
            std::swap(pIndex[i], pIndex[i/2]);
            pReverse[pIndex[i]] = i;
            pReverse[pIndex[i/2]] = i/2;
        }else{
            break;
        }
    }
}

template<typename T>
void IndexHeap<T>::shiftDown(int n){
    // T c = pData[n];
    int indexc = n;
    while(2*n <= count){
        int j = 2*n;
        if(j+1<=count && pData[pIndex[j+1]]>pData[pIndex[j]]){
            j++;
        }

        if(pData[indexc] >= pData[pIndex[j]]){
            break;
        }else{
            // std::swap(pData[n], pData[j]);
            pIndex[n] = pIndex[j];
            pReverse[pIndex[n]] = n;
            n = j;
        }
    }
    pIndex[n] = indexc;
    pReverse[pIndex[n]] = n;
}

template<typename T>
T IndexHeap<T>::extractMax(){
    if(count == 0){
        throw Excep("heap empty");
    }
    
    std::swap(pIndex[1], pIndex[count]);
    pReverse[pIndex[1]] = 1;
    pReverse[pIndex[count]] = 0;
    count--;

    shiftDown(1);
    return pData[pIndex[count+1]];
}

template<typename T>
int IndexHeap<T>::extractIndexMax(){
    if(count == 0){
        throw Excep("heap empty");
    }
    
    std::swap(pIndex[1], pIndex[count]);
    pReverse[pIndex[1]] = 1;
    pReverse[pIndex[count]] = 0;
    count--;

    shiftDown(1);
    return pIndex[count+1]-1;
}

template<typename T>
T IndexHeap<T>::getItem(int i){
    if(i+1>capacity || pReverse[i+1]==0){
        throw Excep("no contain data");
    }
    return pData[i+1];
}

template<typename T>
void IndexHeap<T>::change(int i, T item){
    if(i+1>capacity || pReverse[i+1]==0){
        throw Excep("no contain data");
    }
    i++;
    pData[i] = item;
    int j = pReverse[i];
    shiftUp(j);
    shiftDown(j);
    // for(int j=1; j<=count; j++) {
    //     if(pIndex[j] == i){
    //         shiftUp(j);
    //         shiftDown(j);
    //         return;
    //     }
    // }
}

template<typename T>
std::string IndexHeap<T>::toString(){
    std::string ret = "";
    for(int i=0; i<count; i++){
        ret.append(std::to_string(pData[i+1]));
        ret.append(" ");
    }

    return ret;
}


#endif