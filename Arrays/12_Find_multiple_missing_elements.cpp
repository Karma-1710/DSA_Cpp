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
        void FindMultipleMissingEle();
};

Array::Array(int size){
    this->size = size;
    A = new int[size];
};

void Array::Create() {
    cout << "Enter the length " << endl;
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

void Array::FindMultipleMissingEle(){
    int i=0;
    int difference = A[i] - i;

    while(i < length){
        if(A[i] - i != difference){
            cout << "Missing element: " << difference + i << endl;
            difference++;
        }else{
            i++;
        }
    }
};

int main(){
    Array arr(10);
    arr.Create();
    arr.Display();
    cout << endl;
    arr.FindMultipleMissingEle();
    return 0;
}