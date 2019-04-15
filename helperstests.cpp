#include <iostream>
#include <string>
#include "helpers.h"
using namespace std;

int main(){
    int B[] = {5,4,3,2,1};
    cout << "original: ";
    printArray(B,INT,sizeof(B)/sizeof(int));
    mergeSortInt(B,0,sizeof(B)/sizeof(int)-1);
    cout << endl << "sorted: ";
    printArray(B,INT,sizeof(B)/sizeof(int));
    cout << endl;
    char A[] = {'c','b','d','a','a'};
    cout << "original: ";
    printArray(A,CHAR,sizeof(A)/sizeof(char));
    mergeSortChar(A,0,sizeof(A)/sizeof(char)-1);
    cout << endl << "sorted: ";
    printArray(A,CHAR,sizeof(A)/sizeof(char));
    int maxitem = noDuplicatesChar(A,sizeof(A)/sizeof(char));
    char C[maxitem];
    fillArrayChar(A,C,maxitem);
    cout << endl << "noduplicates: ";
    printArray(C,CHAR,sizeof(C)/sizeof(char));
    return 0;
}