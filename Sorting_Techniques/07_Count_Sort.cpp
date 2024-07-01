#include<iostream>
using namespace std;

int findMax(int A[], int n){
    int max = A[0];
    for(int i=1;i<n;i++){
        if(A[i] > max){
            max = A[i];
        }
    }
    return max;
}

void CountSort(int A[], int n){
    int max = findMax(A, n);
    int* C;
    C = new int[max+1];
    for(int i=0;i<max+1;i++){
        C[i] = 0;
    }
    for(int i=0;i<n;i++){
        C[A[i]]++;
    }
    int i = 0, j =0;
    while(i < max+1){
        if(C[i] > 0){
            A[j] = i;
            j++;
            C[i]--;
        }else{
            i++;
        }
    }
}

void PrintArray(int A[], int n){
    for(int i=0;i<n;i++){
        cout << A[i] << " " << flush;
    }
}

int main(){
    int A[] = {6,3,9,10,15,6,8,12,3,6};
    int n = sizeof(A)/sizeof(A[0]);

    CountSort(A, n);
    PrintArray(A, n);
    return 0;
}