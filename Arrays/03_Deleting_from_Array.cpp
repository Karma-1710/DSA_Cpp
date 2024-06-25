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
        int Delete(int index);
};

Array::Array(int size){
    this->size = size;
    A = new int[size];
};

void Array::Create(){
    cout << "Enter the number of elements: " << endl;
    cin >> length;

    cout << "Enter the elements inside an Array: " << endl;
    for(int i=0;i<length;i++){
        cout << "Array Element " << i << endl;
        cin >> A[i];
    }
};

void Array::Display(){
    for(int i = 0;i<length;i++){
        cout << A[i] << " " <<  flush;
    }
};

int Array::Delete(int index){
    int x = A[index];
    if(index>=0 && index<=length){
        for(int i=index; i<length-1;i++){
            A[i] = A[i+1];
        }
        length--;
    }
    return x;
};

int main(){
    Array arr(10);
    arr.Create();
    arr.Display();
    arr.Delete(3);
    cout << endl;
    arr.Display();
    return 0;
}