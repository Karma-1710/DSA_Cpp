#include<iostream>
using namespace std;

class Array{
    private:
        int size;
        int length;
        int* A;
    public:
        Array(int size);
        int getLength() {return length;}
        void Create();
        void Display();
        int Get(int index);
        void Set(int index, int value);
        int Max();
        int Min();
        int Sum();
        int RecursiveSum(int n);
        int Average();
};

Array::Array(int size){
    this->size = size;
    A = new int[size];
};

void Array::Create(){
    cout << "Enter the number of elements in Array: " << endl;
    cin >> length;

    cout << "Enter the elements of the array: " << endl;
    for(int i=0;i<length;i++){
        cout << "Enter the value at index " << i << endl;
        cin >> A[i];
    }
};

void Array::Display(){
    for(int i=0;i<length;i++){
        cout << A[i] << " " << flush;
    }
};

int Array::Get(int index){
    if(index >= 0 && index < length){
        return A[index];
    }
    return -1;
};

void Array::Set(int index, int value){
    if(index >= 0 && index < length){
        A[index] = value;
    }   
};

int Array::Max(){
    int max = A[0];
    for(int i=0; i<length; i++){
        if(A[i] > max){
            max = A[i];
        }
    }
    return max;
};

int Array::Min(){
    int min = A[0];
    for(int i=0;i<length;i++){
        if(A[i] < min){
            min = A[i];
        }
    }
    return min;
};

int Array::Sum(){
    int Sum = 0;
    for(int i=0;i<length;i++){
        Sum+=A[i];
    }
    return Sum;
};

int Array::RecursiveSum(int n){
    if(n < 0){
        return 0;
    }
    return A[n] + RecursiveSum(n-1);
};

int Array::Average(){
    int total = 0;
    for(int i=0;i<length;i++){
        total += A[i];
    }
    return static_cast<double>(total) / length;
}

int main(){
    Array arr(10);
    arr.Create();
    arr.Display();
    cout << endl;
    cout << arr.Get(2) << endl;
    cout << endl;
    arr.Set(2,10);
    arr.Display();
    cout << endl;
    cout << arr.Max() << endl;
    cout << arr.Min() << endl;
    cout << arr.Sum() << endl;
    cout << arr.RecursiveSum(arr.getLength() - 1) << endl;
    cout << arr.Average() << endl;
    return 0;
}