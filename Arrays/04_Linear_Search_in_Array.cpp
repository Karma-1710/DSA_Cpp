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
        int LinearSearch(int key);
        int TranspositionLinearSearch(int key);
        int MoveToFrontLinearSearch(int key);
};

Array::Array(int size){
    this->size = size;
    A = new int[size];
};

void Array::Create(){
    cout << "Enter the number of Elements: " << endl;
    cin >> length;

    cout << "Enter the elements of the array: " << endl;
    for(int i=0;i<length;i++){
        cout << "Element of index " << i << endl;
        cin >> A[i];
    }
};

void Array::Display(){
    for(int i=0;i<length;i++){
        cout << A[i] << " " << flush;
    }
};

void Swap(int *x, int *y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
};

int Array::LinearSearch(int key){
    for(int i=0;i<length;i++){
        if(key == A[i]){
            return i;
        }
    }
    return -1;
};

int Array::TranspositionLinearSearch(int key){
    for(int i=0;i<length;i++){
        if(key == A[i]){
            Swap(&A[i], &A[i-1]);
            return i;
        }
    }
    return -1;
};

int Array::MoveToFrontLinearSearch(int key){
    for(int i=0; i<length;i++){
        if(key == A[i]){
            Swap(&A[0], &A[i]);
            return i;
        }
    }
    return -1;
}

int main(){
    Array arr(10);
    arr.Create();
    arr.Display();
    cout << endl;
    cout << arr.LinearSearch(5) << endl;
    cout << endl;
    cout << arr.TranspositionLinearSearch(0) << endl;
    arr.Display();
    cout << endl;
    cout << arr.MoveToFrontLinearSearch(0) << endl;
    arr.Display();
    return 0;
}