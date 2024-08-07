#include<iostream>
using namespace std;

void Heapify(int A[], int n){
    for(int i=(n/2)-1;i>=0;i--){
        int j = 2*i + 1;
        while(j < n-1){
            if(A[j+1] > A[j]){
                j+=1;
            }
            if(A[i] < A[j]){
                int temp = A[i];
                A[i] = A[j];
                A[j] = temp;
                i=j;
                j=2*j+1;
            }else{
                break;
            }
        }
    }
}

void Print(int A[], int n){
    for(int i=0;i<n;i++){
        cout << A[i] << " " << flush;
    }
}

int main(){
    int A[] = {5,10,30,20,35,40,15};
    int n = sizeof(A)/sizeof(A[0]);
    Print(A, n);
    Heapify(A, n);
    cout << endl;
    Print(A, n);
    return 0;
}