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
        Array Merge(Array &arr2);
};

Array::Array(int size){
    this->size = size;
    A = new int[size];
};

void Array::Create(){
    cout << "Enter the length: " << endl;
    cin >> length;

    cout << "Enter the elements: " << endl;
    for(int i=0;i<length;i++){
        cout << "Element at index" << i << endl;
        cin >> A[i];
    }
};

void Array::Display(){
    for(int i=0;i<length;i++){
        cout << A[i] << " " << flush;
    }
    cout << endl;
};

Array Array::Merge(Array& arr2){
    int i=0, j=0, k=0;
    Array arr3(length + arr2.length);

    while(i < length && j < arr2.length){
        if(A[i] < arr2.A[j]){
            arr3.A[k] = A[i];
            i++;
            k++;
        }else{
            arr3.A[k] = arr2.A[j];
            j++;
            k++;
        }
    }

    while(i<length){
        arr3.A[k] = A[i];
        i++;
        k++;
    }
    while(j<arr2.length){
        arr3.A[k] = arr2.A[j];
        j++;
        k++;
    }
    arr3.length = k;
    return arr3;
}

int main(){
    Array arr1(10);
    Array arr2(10);
    arr1.Create();
    arr2.Create();
    arr1.Display();
    arr2.Display();
    Array arr3 = arr1.Merge(arr2);
    arr3.Display();
    return 0;
}