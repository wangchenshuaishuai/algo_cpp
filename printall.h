#ifndef _PRINTALL_H_
#define _PRINTALL_H_

template <typename T>
void printall(T arr[], int n){
    for(int i=0; i<n; i++){
        std::cout << arr[i] << " ";
    }
    std::cout << "\r\n";
}

#endif