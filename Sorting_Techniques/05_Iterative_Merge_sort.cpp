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
            i++;
            k++;
        }else{
            B[k] = A[j];
            j++;
            k++;
        }
    }
    while(i <= mid){
        B[k] = A[i];
        k++;
        i++;
    }
    while(j <= h){
        B[k] = A[j];
        j++;
        k++;
    }
    for(i = l;i<=h;i++){
        A[i] = B[i];
    }
}

void IterativeMergeSort(int A[], int n){
    int p, i, l, mid, h;
    for(p = 2;p<=n;p=p*2){
        for(i=0;i+p-1<n;i=i+p){
            l = i;
            h = i+p-1;
            mid = (l + h)/2;
            Merge(A, l, mid, h);
        }
    }
    if(p/2 < n){
        Merge(A,0,p/2,n-1);
    }
}

void PrintArray(int A[], int n){
    for(int i=0;i<n;i++){
        cout << A[i] << " " << flush;
    }
}

int main(){
    int A[] = {8,3,7,4,9,2,6,5};
    int n = sizeof(A)/sizeof(A[0]);

    IterativeMergeSort(A, n);
    PrintArray(A, n);
    return 0;
}