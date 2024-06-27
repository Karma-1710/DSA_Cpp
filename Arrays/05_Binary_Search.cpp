#include<iostream>
#include<cmath>
using namespace std;

class Array{
    private:
        int size;
        int length;
        int* A;
    public:
        Array(int size);
        int getLength(){return length;}
        void Create();
        void Display();
        int BinarySearch(int key);
        int RecursiveBinarySearch(int low, int high, int key);
};

Array::Array(int size){
    this->size = size;
    A = new int[size];
};

void Array::Create(){
    cout << "Enter the number of elements in Array: " << endl;
    cin >> length;

    cout << "Enter the elements inside of the array: " << endl;
    for(int i=0;i<length;i++){
        cout << "Element at index" << i << endl;
        cin >> A[i];
    }
};

void Array::Display(){
    for(int i=0;i<length;i++){
        cout << A[i] << " " << flush;
    }
};

int Array::BinarySearch(int key){
    int low = 0;
    int high = length-1;
    while(low <= high){
        int mid = floor((low + high)/2);
        if(key == A[mid]){
            return mid;
        }else if(key < A[mid]){
            high = mid-1;
        }else{
            low = mid + 1;
        }
    }
    return -1;
}

int Array::RecursiveBinarySearch(int low, int high, int key){
    if(low <= high){
        int mid = (low+high)/2;
        if(key == A[mid]){
            return mid;
        } else if(key < A[mid]){
            return RecursiveBinarySearch(low, mid-1, key);
        } else{
            return RecursiveBinarySearch(mid+1, high, key);
        }
    }
    return -1;
}

int main(){
    Array arr(10);
    arr.Create();
    arr.Display();
    cout << endl;
    cout << arr.RecursiveBinarySearch(0, arr.getLength() , 3) << endl;
    return 0;
}