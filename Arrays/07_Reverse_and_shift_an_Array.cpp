#include<iostream>
using namespace std;

class Array{
    private:
        int size;
        int length;
        int* A;
    public: 
        Array(int size);
        void Create();
        void Display();
        void Reverse();
        void ReverseBySwap();
};

Array::Array(int size){
    this->size;
    A = new int[size];
};

void Array::Create(){
    cout << "Enter the number of elements: " << endl;
    cin >> length;

    cout << "Enter the values of Array" << endl;
    for(int i=0;i<length;i++){
        cout << "Element at index " << i << endl;
        cin >> A[i];
    }
};

void Array::Display(){
    for(int i=0;i<length;i++){
        cout << A[i] << " "  << flush;
    }
};

void Array::Reverse(){
    int* B = new int[length];
    int i,j;
    for(i=length-1,j=0;i>=0;i--,j++){
        B[j] = A[i];
    }
    for(i=0;i<length;i++){
        A[i] = B[i];
    }
};

void Swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
};

void Array::ReverseBySwap(){
    int i, j;
    for(i=0,j=length-1;i<j;i++,j--){
        Swap(&A[i], &A[j]);
    }
};

int main(){
    Array arr(10);
    arr.Create();
    arr.Display();
    arr.ReverseBySwap();
    cout << endl;
    arr.Display();
    return 0;
}