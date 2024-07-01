#include<iostream>
using namespace std;

void Merge(int A[], int l, int mid, int h){
    int i, j, k;
    int B[h+1];
    i = l;
    j = mid+1;
    k = l;
    while(i <= mid && j <= h){
        if(A[i] < A[j]){
            B[k] = A[i];
            k++;
            i++;
        }else{
            B[k] = A[j];
            j++;
            k++;
        }
    }
    while(i <= mid){
        B[k++] = A[i++];
    }
    while(j <= h){
        B[k++] = A[j++];
    }
    for(int i=l;i<=h;i++){
        A[i] = B[i];
    }
}

void MergeSort(int A[], int l, int h){
    if(l < h){
        int mid = (l+h)/2;
        MergeSort(A, l, mid);
        MergeSort(A, mid+1, h);
        Merge(A, l, mid, h);
    }
}

void PrintArray(int A[], int n){
    for(int i=0;i<n;i++){
        cout << A[i] << " " << flush; 
    }
}

int main(){
    int A[] = {8,2,9,6,5,3,7,4};
    int n = sizeof(A)/sizeof(A[0]);

    MergeSort(A, 0, n-1);
    PrintArray(A, n);
    return 0;
}