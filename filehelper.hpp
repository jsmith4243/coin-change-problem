#ifndef FILEHELPER_H
#define FILEHELPER_H
#include <string>
 
//strips line of beginning and ending brackets
inline std::string bracketStrip(std::string line) {return line.substr(1,(line.length()-3)); };
//tokenizer that returns int array
void makeArray(const std::string&,int&,int (&intArray)[100]);
//read file function arguments will be filename, int array of money totals,
//int array of coin array sizes, number of trials. Will return NULL if error.
void parseFile(char[],int (&totals)[100],int (&sizes)[100],int&,int(&coinmatrix)[100][100]);
 
#endif