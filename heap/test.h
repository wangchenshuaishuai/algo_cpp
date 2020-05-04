#ifndef _TEST_H
#define _TEST_H

namespace test{
    template<typename T>
    void printAll(T arr[], int n){
        for(int i=0; i<n; i++){
            std::cout << arr[i] << " " ;
        }
        std::cout << std::endl;
    }

    template<typename T>
    void copy(T dest[], T src[], int n){
        for(int i=0; i<n; i++){
            dest[i] = src[i];
        }
    }
}

#endif