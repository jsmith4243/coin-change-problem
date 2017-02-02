#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <sstream>
#include "filehelper.hpp"
 
void makeArray(const std::string &stringArray, int& size, int (&intArray)[100]){
    std::string delimiters = ", ";
    std::string tempstring;
    size = 0;
    int * returnArray;
    std::string::size_type lastPos = stringArray.find_first_not_of(delimiters, 0);
    std::string::size_type pos     = stringArray.find_first_of(delimiters, lastPos);
    while (std::string::npos != pos || std::string::npos != lastPos)
    {
        intArray[size] = atoi((stringArray.substr(lastPos, pos - lastPos)).c_str());
        //std::cout << intArray[size] << "::";
        size++;
        lastPos = stringArray.find_first_not_of(delimiters, pos);
        pos = stringArray.find_first_of(delimiters, lastPos);
    }
    std::cout << std::endl;
    return;
}
 
void parseFile(char* filename, int (&totals)[100],int (&sizes)[100],int& trials, int (&coinmatrix)[100][100]){
    std::ifstream ifs;
    std::string line;
    int iter = 0;
    bool parse = true;
    int i,j;
    ifs.open(filename);
    if (ifs){
        while (getline(ifs,line)){
            if (parse){
                int size = 0;
                makeArray(bracketStrip(line),size,coinmatrix[iter]);
                sizes[iter]=size;
            }
            else {
                totals[iter] = atoi(line.c_str());
                iter++;
            }
            parse = !parse;//switch boolean that governs if statements
        }
    }
    else {
        std::cerr << "File open fail. Exiting program." << std::cout;
        exit(4);
    }
    ifs.close();
    /*
    std::cout << "Printing coin matrix: " << std::endl;
    for (i=0;i<iter;i++){
        for (j=0;j<sizes[i];j++){
            std::cout << coinmatrix[i][j] << ", ";
        }
        std::cout << std::endl;
        std::cout << totals[i] << std::endl;
    }
     */
    trials = iter;
    return;
}
 
//for testing purposes only
/*int main (int argc, char**argv){
    int coinmatrix[100][100];
    int totals[100];
    int sizes[100];
    int trials;
    parseFile(argv[1],totals,sizes,trials,coinmatrix);
    return 0;
}*/