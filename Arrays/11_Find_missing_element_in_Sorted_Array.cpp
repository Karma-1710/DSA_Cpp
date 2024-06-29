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
        int FindMissingEle();
};

Array::Array(int size){
    this->size = size;
    A = new int[size];
};

void Array::Create(){
    cout << "Enter length: " <<  endl;
    cin >> length;

    cout << "Enter the elements: " << endl;
    for(int i=0;i<length;i++){
        cout << "Element at index " << i << endl;
        cin >> A[i]; 
    }
};

void Array::Display(){
    for(int i=0;i<length;i++){
        cout << A[i] << " " << flush;
    }
};

int Array::FindMissingEle(){
    int i=0;
    int difference = A[i] - i;
    for(int i=0;i<length;i++){
        if(A[i]-i != difference){
            return i+difference;
        }
    }
    return 0;
}

int main() {
    Array arr(10);
    arr.Create();
    arr.Display();
    cout << endl;
    cout << "Missing Element: " << arr.FindMissingEle() << endl;
    return 0;
}