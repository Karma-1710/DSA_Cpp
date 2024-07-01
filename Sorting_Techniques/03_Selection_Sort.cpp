#include<iostream>
using namespace std;

void Swap(int* x, int* y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void SelectionSort(int A[], int n){
    int i, j, k;
    for(i = 0; i< n-1;i++){
        for(j = k = i;j<n;j++){
            if(A[j] < A[k]){
                k = j;
            }
        }
        Swap(&A[i], &A[k]);
    }
}

void PrintArray(int A[], int n){
    for(int i=0;i<n;i++){
        cout << A[i] << " " << flush;
    }
}

int main(){
    int A[] = {8,6,3,2,5,4};
    int n = sizeof(A)/sizeof(A[0]);

    SelectionSort(A, n);
    PrintArray(A, n);
    return 0;
}