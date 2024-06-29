#include<iostream>
using namespace std;

int max(int A[], int size){
    int max = A[0];
    for(int i=0;i<size;i++){
        if(A[i] > max){
            max = A[i];        
        } 
    }
    return max;
};

void FindAndCountDuplicates(int A[], int B[], int h, int size){
    for(int i=0;i<size;i++){
        B[A[i]]++;
    }
    for(int i=0;i<=h;i++){
        if(B[i] > 1){
            cout << "Element " << i << " appeared " << B[i] << " times";
        }
    }
}

int main(){
    int* A;
    int size;

    cout << "Enter the number of elements: " << endl;
    cin >> size;
    A = new int[size];
    for(int i=0;i<size;i++){
        cout << "Element at index " << i << endl;
        cin >> A[i];
    }

    int h =  max(A, size);
    int B[h+1] = {0};

    FindAndCountDuplicates(A,B,h,size);
    return 0;
}