#ifndef _TEST_H
#define _TEST_H
#include "Excep.h"
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

    // template<typename T>
    // void printTree(T arr[], int n){
    //     if( n >= 100){
    //         throw Excep("size too long, can't print");
    //     }

    //     if(typeid(arr[0]) != typeid(int)){
    //         throw Excep("could only print int type");
    //     }

    //     for(int i=1; i<n; i++){
    //         cout << arr[i] << " ";
    //     }
    //     cout << "\r\n\r\n";
    //     int max_level = 0;
    //     int number_per_level = 1;
    // }
}

#endif