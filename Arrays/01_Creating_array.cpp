#include<iostream>
using namespace std;

class Array{
    private:
        int* A;
        int size;
        int length;
    public:
        Array(int size);
        void Create();
        void Display();
};

Array::Array(int size){
    this->size = size;
    A = new int[size];
};

void Array::Create(){
    cout << "Enter number of Elements : " << endl;
    cin >> length;
    cout << "Enter the array elements: " << endl;
    for(int i=0;i<length;i++){
        cout << "Array element " << i << " = " << flush;
        cin >> A[i];
    }
};

void Array::Display(){
    for(int i=0;i<length;i++){
        cout << A[i] << flush;
    }
};

int main(){
    Array arr(10);
    arr.Create();
    arr.Display();
    return 0;
}