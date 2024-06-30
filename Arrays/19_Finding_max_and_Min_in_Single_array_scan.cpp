#include<iostream>
using namespace std;

void FindMaxAndMin(int A[], int size){
    int Min = A[0];
    int Max = A[0];

    for(int i=0;i<size;i++){
        if(A[i] < Min){
            Min = A[i];
        } else if(A[i] > Max){
            Max = A[i];
        }
    }

    cout << "Max Element: " << Max << " and Min Element: " << Min << endl;
}

int main(){
    int* A;
    int size;

    cout << "Enter the number of elements: " << endl;
    cin >> size;
    A = new int[size];

    for(int i=0;i<size;i++){
        cout << "Element at index " << i << endl;
        cin >> A[i];
    }

    FindMaxAndMin(A, size);
    return 0;
}