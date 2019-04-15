#include <iostream>
#include <string>
#include <fstream>
#include "helpers.h"
using namespace std;

class Perceptron{
    private:
    int maxIter;
    bool verbose;
    bool trained;
    public:
    Perceptron() { maxIter = 50; verbose = true; trained = false; }
    Perceptron(int mi, bool v) { maxIter = mi; verbose = v; trained = false; }
    int activation(int, int[]);
    int classify(int[]);
    void update(char[], char[]);
    void fit();
    void decisionFn();
    int predict();
};

int Perceptron::activation(int i, int outs[]){
    if(outs[i] > 0) return 1;
    return 0;
}

int Perceptron::classify(int outs[]){
    int c = 0;
    int max = 0;
    int act;
    for(int i=0; i<sizeof(outs)/sizeof(int); i++){
        act = activation(i, outs);
        if(act > max){
            max = act;
            c = i;
        }
    }
    return c;
}

int Perceptron::update(char features[], char classes[]){
    
}