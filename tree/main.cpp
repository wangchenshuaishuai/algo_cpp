#include <iostream>
#include "test.h"
#include "bsTree.h"
#include <string>
// #include "ReadFile.h"

using std::string;
using namespace std;
int main(int argc, char* argv[]){
    test();

    // readFile("bible");
    BSTree<int, string> bsTree;
    bsTree.insert(6, "hello");
    bsTree.insert(4, "dog");
    bsTree.insert(9, "cat");
    bsTree.insert(1, "phone");
    bsTree.insert(5, "telephone");
    bsTree.insert(7, "pen");
    bsTree.insert(10, "bike");
    bsTree.insert(109, "bike");
    bsTree.insert(72, "bike");
    bsTree.insert(39, "bike");

    cout << "contain 1?  " << bsTree.contain(3) << endl;
    cout << "contain 5?  " << bsTree.contain(5) << endl;

    try{
        cout << "get 1:   " << bsTree.get(1) << endl;
    }catch(exception e){
        cout << e.what() << endl;
    }

    try{
        cout << __LINE__ << "get 3:   " << bsTree.get(3) << endl;
    }catch(exception e){
        cout << __LINE__ << e.what() << endl;
    }

    cout << "------front-----"<< endl;
    bsTree.travelFront();
    cout << "------Middle-----"<< endl;
    bsTree.travelMiddle();
    cout << "------end-----"<< endl;
    bsTree.travelEnd();

    cout << "------ travel level ------" << endl;
    bsTree.travelLevel();
    return 1;
}