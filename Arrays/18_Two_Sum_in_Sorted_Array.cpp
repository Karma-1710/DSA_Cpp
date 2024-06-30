#include<iostream>
using namespace std;

void TwoSumInSorted(int A[], int size, int sum){
    int i=0, j = size-1;
    while(i<j){
        if(A[i] + A[j] == sum){
            cout << A[i] << " + " << A[j] << " = " << sum << endl;
            i++;
            j--;
        }else if(A[i] + A[j] < sum) {
            i++;
        } else {
            j--;
        }
    }
}

int main(){
    int* A;
    int size;

    cout << "Enter number of elements: " << endl;
    cin >> size;
    A = new int[size];

    for(int i=0;i<size;i++){
        cout << "Element at index " << i << endl;
        cin >> A[i];
    }

    int sum;
    cout << "Enter the sum of two elements: " << endl;
    cin >> sum;
    TwoSumInSorted(A, size, sum);
    return 0;
}