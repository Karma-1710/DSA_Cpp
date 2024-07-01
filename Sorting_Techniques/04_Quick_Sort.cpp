#include<iostream>
using namespace std;

void Swap(int* x, int* y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

int Partition(int A[], int low, int high){
    int pivot = A[low];
    int i = low;
    int j = high;

    do{
        do{i++;}while(A[i] <= pivot);
        do{j--;}while(A[j] > pivot);
        if(i < j){
            Swap(&A[i], &A[j]);
        } 
    } while (i < j);

    Swap(&A[low], &A[j]);
    return j;
}

void QuickSort(int A[], int low, int high){
    if(low < high){
        int j = Partition(A, low, high);
        QuickSort(A, low, j);
        QuickSort(A, j+1, high);
    }
}

void PrintArray(int A[], int n){
    for(int i=0;i<n;i++){
        cout << A[i] << " " << flush;
    }
}

int main(){
    int A[] = {50,70,60,90,40,80,10,80,20,30};
    int n = sizeof(A)/sizeof(A[0]);

    QuickSort(A, 0, n-1);
    PrintArray(A, n);
    return 0;
}