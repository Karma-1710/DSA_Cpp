#include<iostream>
using namespace std;

void FindDuplicates(int A[], int size){
    int lastDuplicate = 0;
    for(int i=0;i<size;i++){
        if(A[i] == A[i+1] && A[i] != lastDuplicate){
            cout << "Duplicate Element: " << A[i] << endl;
            lastDuplicate = A[i];
        }
    }
};

void CountDuplicates(int A[], int size){
    for(int i=0; i<size;i++){
        if(A[i] == A[i+1]){
            int j = i+1;
            while(A[j] == A[i]){j++;}
            cout << A[i] << " is appearing " << j-i << "times" << endl;
            i = j-1;
        }
    }
}

int main(){
    int* A;
    int size;

    cout << "Enter the number of elements in the array: " << endl;
    cin >> size;

    A = new int[size];
    for(int i=0;i<size;i++){
        cout << "Element at index " << i << endl;
        cin >> A[i];
    };
    FindDuplicates(A, size);
    CountDuplicates(A, size);
    return 0;
}