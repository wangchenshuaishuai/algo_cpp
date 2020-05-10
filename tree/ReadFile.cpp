#include "ReadFile.h"
#include <fstream>
using namespace std;
void readFile(string file){
    std::ifstream infile;
    infile.open(file, ifstream::in);
    if(infile.is_open()){
        std::stringstream buffer;
        buffer << infile.rdbuf();

        infile.close();        
    }
    
}

void getAllWords(ifstream file){
    while(!file.eof()){
        
    }
}