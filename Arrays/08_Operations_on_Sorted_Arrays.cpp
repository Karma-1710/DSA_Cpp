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
        void InsertInSorted(int val);
        bool isSorted();
        void ShiftNegativesAtLeft();
};

Array::Array(int size){
    this->size = size;
    A = new int[size];
};

void Array::Create(){
    cout << "Enter the number of Elements: " << endl;
    cin >> length;

    cout << "Enter the elements : " << endl;
    for(int i=0;i<length;i++){
        cout << "Element at index: " << i << endl;
        cin >> A[i];
    }
};

void Array::Display(){
    for(int i=0;i<length;i++){
        cout << A[i] << " " << flush;
    }
};

void Array::InsertInSorted(int val){
    int i = length-1;
    while(A[i] > val){
        A[i+1] = A[i];
        i--;
    }
    A[i+1] = val;
    length++;
};

bool Array::isSorted(){
    for(int i=0;i<length - 1;i++){
        if(A[i] > A[i+1]){
            return false;
        }
    }
    return true;
}

void Swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void Array::ShiftNegativesAtLeft(){
    int i = 0;
    int j = length - 1;
    while(i < j){
        while(A[i] < 0){i++;};
        while(A[j] > 0){j--;};
        if(i < j){
            Swap(&A[i], &A[j]);
        }
    }
}

int main(){
    Array arr(10);
    arr.Create();
    arr.Display();
    // arr.InsertInSorted(5);
    // cout << endl;
    // arr.Display();
    // cout << endl;
    // cout << arr.isSorted() << endl;
    cout << endl;
    arr.ShiftNegativesAtLeft();
    arr.Display();
    return 0;
}