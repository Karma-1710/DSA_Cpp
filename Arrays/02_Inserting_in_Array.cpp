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
        void Insert(int index, int x);
};

Array::Array(int size){
    this->size = size;
    A = new int[size];
};

void Array::Create(){
    cout << "Enter the number of elements: " << endl;
    cin >> length;

    cout << "Enter the elements inside of an Array: " << endl;
    for(int i=0;i<length;i++){
        cout << "Array element: " << i << endl;
        cin >> A[i];
    }
};

void Array::Display(){
    for(int i=0; i<length; i++){
        cout << A[i] << " " << flush;
    }
};

void Array::Insert(int index, int x){
    for(int i=length;i>index;i--){
        A[i] = A[i-1];
    }
    A[index] = x;
    length++;
};

int main(){
    Array arr(10);
    arr.Create();
    arr.Display();
    arr.Insert(4, 15);
    cout << endl;
    arr.Display();
    return 0;
}