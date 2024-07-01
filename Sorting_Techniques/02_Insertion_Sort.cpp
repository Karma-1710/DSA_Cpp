#include<iostream>
using namespace std;

void InsertionSort(int A[], int n){
    for(int i=1;i<n;i++){
        int j=i-1;
        int x = A[i];
        while(j > -1 && A[j] > x){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = x;
    }
};

void PrintArray(int A[], int n){
    for(int i=0;i<n;i++){
        cout << A[i] << " " << flush;
    }
}

int main(){
    int A[] = {8,5,7,3,2};
    int n = sizeof(A)/sizeof(A[0]);
    InsertionSort(A, n);
    PrintArray(A, n);
    return 0;
}