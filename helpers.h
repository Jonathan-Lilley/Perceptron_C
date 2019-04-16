#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;

///////////////////////////////////////////////////////////////////////////////
//////////////////// generic functions and structs ////////////////////////////
///////////////////////////////////////////////////////////////////////////////

//data pair struct to help with pairing characters with ints
struct IntCharPair{
	int value;
	char letter;
};

//enumerator to help with printArray
enum Type{
    INT,
    CHAR
};

//prints array of ints or chars
void printArray(void* A, Type type, int len){
    switch(type){
        case INT:{
            cout << "int"<< endl;
            int* arr = static_cast<int*>(A);
            for(int i=0; i<len; i++){
                cout << *(arr+i) << " ";
            }
            cout << endl;
            break;
        }
        case CHAR:{
            cout << "char" << endl;
            char* arr = static_cast<char*>(A);
            for(int i=0; i<len; i++){
                cout << *(arr+i) << " ";
            }
            cout << endl;
            break;
        }
    }
}


///////////////////////////////////////////////////////////////////////////////
//////////////////////////////// char functions ///////////////////////////////
///////////////////////////////////////////////////////////////////////////////

// merge
void mergeChar(char A[], int p, int q, int r){
	int n = q - p + 1;
	int m = r - q;
	char L[n], R[m];
	for(int i=0; i<n; i++){
		L[i] = A[p+i];
	}
	for(int j=0; j<m; j++){
		R[j] = A[q+j+1];
	}
	int i = 0;
	int j = 0;
	int k = p;
	while(i<n && j<m){
		if(L[i] <= R[j]){
			A[k] = L[i];
			i++;
		}
		else{
			A[k] = R[j];
			j++;
		}
		k++;
	}
	while(i<n){
		A[k] = L[i];
		i++;
		k++;
	}
	while(j<m){
		A[k] = R[j];
		j++;
		k++;
	}
}

// merge sort
void mergeSortChar(char A[], int p, int r){
	if(p < r){
		int q = (r+p)/2;
		mergeSortChar(A, p, q);
		mergeSortChar(A, q+1, r);
		mergeChar(A, p, q, r);
	}
}

/**
 * Cuts out duplicates by creating a new array, then copying all non-duplicates
 * over to it and refilling the old array with the nonduplicates, setting
 * all the remaining values to 0 and returning the index of the last value
 */
int noDuplicatesChar(char A[], int len){
	mergeSortChar(A,0,len-1);
    char B[len];
    B[0] = A[0];
    int j = 1;
    for(int i=1; i<len; i++){
        if(A[i] == A[i-1]) continue;
        B[j] = A[i];
        j++;
    }
    int maxItem = A[len-1];
    int i = 1;
    A[0] = B[0];
    while(B[i-1]!=maxItem){
        A[i] = B[i];
        i++;
    }
    j = i;
    while(i<len){
        A[i] = -2;
        i++;
    }
    return j;
}

// fills input array with old input array up to a given value
void fillArrayChar(char A[], char C[], int maxitem){
    for(int i=0; i<maxitem; i++){
        C[i] = A[i];
    }
}

////////////////////////////////////////////////////////////////////////////////
///////////////////////////////// int functions ////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

// see above
int noDuplicatesInt(int A[], int len){
    int B[len];
    B[0] = A[0];
    int j = 1;
    for(int i=1; i<len; i++){
        if(A[i] == A[i-1]) continue;
        B[j] = A[i];
        j++;
    }
    int maxItem = A[len-1];
    int i = 1;
    A[0] = B[0];
    while(B[i-1]!=maxItem){
        A[i] = B[i];
        i++;
    }
    j = i;
    while(i<len){
        A[i] = '0';
        i++;
    }
    return j;
}

// see above
void fillArrayInt(int A[], int C[], int maxitem){
    for(int i=0; i<maxitem; i++){
        C[i] = A[i];
    }
}

// merge for int
void mergeInt(int A[], int p, int q, int r){
	int n = q - p + 1;
	int m = r - q;
	int L[n], R[m];
	for(int i=0; i<n; i++){
		L[i] = A[p+i];
	}
	for(int j=0; j<m; j++){
		R[j] = A[q+j+1];
	}
	int i = 0;
	int j = 0;
	int k = p;
	while(i<n && j<m){
		if(L[i] <= R[j]){
			A[k] = L[i];
			i++;
		}
		else{
			A[k] = R[j];
			j++;
		}
		k++;
	}
	while(i<n){
		A[k] = L[i];
		i++;
		k++;
	}
	while(j<m){
		A[k] = R[j];
		j++;
		k++;
	}
}

// merge sort for int
void mergeSortInt(int A[], int p, int r){
	if(p < r){
		int q = (r+p)/2;
		mergeSortInt(A, p, q);
		mergeSortInt(A, q+1, r);
		mergeInt(A, p, q, r);
	}
}