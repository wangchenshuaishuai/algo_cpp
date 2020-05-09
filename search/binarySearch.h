#ifndef _AABINARY_SEARCH_H
#define _AABINARY_SEARCH_H

// namespace testBinarySearch{
    //非递归版本的二分查找法
    template<typename T>
    class BinarySearch{
    public:
        BinarySearch(){
            floor = -1;
            ceil = -1;
        };
        ~BinarySearch(){};
        int binarySearch(T arr[], int n, T target); //非递归版本二分查找
        int binarySearchRec(T arr[], int n, T target);  //递归版本二分查找
        int getFloor();
        int getCeil();
    private:
        int floor;
        int ceil;
        int __binarySearchRec(T arr[], int target, int l, int r);
        void findFloorCeil(T arr[], int m, int l, int r);
    };

    template<typename T>
    int BinarySearch<T>::binarySearch(T arr[], int n, T target){
        int l = 0;
        int r = n-1;
        while(l <= r){
            int m = (r-l)/2+l;
            if(target == arr[m]){
                findFloorCeil(arr, m, l, r);
                return m;
            }else if (target > arr[m]){
                l = m+1;
            }else{
                r = m-1;
            }
        }

        floor = r - 1;
        ceil = r;
        return -1;
    }    

    //递归版本的二分查找法
    template<typename T>
    int BinarySearch<T>::__binarySearchRec(T arr[], int target, int l, int r){
        if(l > r){
            floor = r-1;
            ceil = r;
            return -1;
        }

        int m = (r-l)/2 + l;
        if(target == arr[m]){
            findFloorCeil(arr, m, l, r);
            return m;
        }else if (target > arr[m]){
            return __binarySearchRec(arr, target, m+1, r);
        }else{
            return __binarySearchRec(arr, target, l, m-1);
        }
    }

    template<typename T>
    int BinarySearch<T>::binarySearchRec(T arr[], int n, T target){
        return __binarySearchRec(arr, target, 0, n-1);
    }

    template<typename T>
    void BinarySearch<T>::findFloorCeil(T arr[], int m, int l, int r){

        for(int i=m; i<=r; i++){
            if(arr[i] == arr[m]){
                ceil = i;
            }
        }
        for(int i=m; i>=l; i--){
            if(arr[i] == arr[m]){
                floor = i;
            }
        }
    }

    template<typename T>
    int BinarySearch<T>::getFloor(){
        return floor;
    }

    template<typename T>
    int BinarySearch<T>::getCeil(){
        return ceil;
    }
// }


#endif