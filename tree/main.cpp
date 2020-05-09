#include <iostream>
#include "test.h"
#include "bsTree.h"
#include <string>

using std::string;
using namespace std;
int main(int argc, char* argv[]){
    test();
    BSTree<int, string> bsTree;
    bsTree.insert(5, "hello");
    bsTree.insert(1, "dog");
    bsTree.insert(2, "cat");

    cout << "contain 1?  " << bsTree.contain(3) << endl;
    cout << "contain 5?  " << bsTree.contain(5) << endl;

    try{
        cout << "get 1" << bsTree.get(1) << endl;
    }catch(exception e){
        cout << e.what() << endl;
    }

    try{
        cout << __LINE__ << "get 3" << bsTree.get(3) << endl;
    }catch(exception e){
        cout << __LINE__ << e.what() << endl;
    }
    return 1;
}