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
    int* weights;
    int maxFeats;
    int maxClasses
    public:
    Perceptron() { maxIter = 50; verbose = true; trained = false; 
                    weights = NULL; maxFeats = 10; maxClasses = 10; }
    Perceptron(int mi, bool v, int mf, int mc) { maxIter = mi; verbose = v; 
                    trained = false; weights = NULL; maxFeats = mf; maxClasses = mc; }
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

int Perceptron::update(char inputFeatures[maxFeats][10], char inputClasses[10], int numExamples, int numClasses){
    // sets up raw features array
    char rawFeats[maxClasses*maxFeats];
    int k = 0;
    for(int i=0; i<maxClasses; i++){
        for(int j=0; j<maxFeats; j++){
            rawFeats[k] = inputFeatures[i][j];
            k++;
        }
    }
    // sets up feature set
    int numFeats = noDuplicatesChar(rawFeats, maxClasses*maxFeats);
    char featSet[numFeats];
    fillArrayChar(rawFeats, featSet, numFeats);
    // sets up feature-value pairs array
    IntCharPair inttofeat[numFeats];
    for(int i=0; i<numFeats; i++){
        inttofeat[i].value = i;
        inttofeat[i].letter = featSet[i];
    }
    // sets up original features as values
    int features[maxClasses][maxFeats];
    for(int i=0; i<maxClasses; i++){
        for(int j=0; j<maxFeats; j++){
            
        }
    }
    // sets up class set
    numClasses = noDuplicatesInt(inputClasses, 10);
    int classSet[numClasses];
    fillArrayInt(inputClasses,classSet,numClasses);
    // sets up class-value array
    IntCharPair inttoclass[numClasses];
    for(int i=0; i<numClasses; i++){
        inttoclass.value = i;
        inttoclass.letter = classSet[i];
    }
    // initializes weights
    int tempWeights[numClasses][numFeats];
    for(int i=0; i<numClasses; i++){
        for(int j=0; j<numFeats; j++){
            tempWeights[i][j] = (rand()%3)-1;
        }
    }
    
}