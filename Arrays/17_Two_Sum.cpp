#include<iostream>
using namespace std;

void TwoSum(int A[], int size, int sum){
    for(int i=0;i<size-1;i++){
        for(int j=i+1;j<size;j++){
            if(A[i] + A[j] == sum){
                cout << A[i] << " + " << A[j] << " = " << sum << endl;
            }
        }
    }
};

int max(int A[], int size){
    int max = A[0];
    for(int i=0;i<size;i++){
        if(A[i] > max){
            max = A[i];
        }
    }
    return max;
};

void TwoSumWithHash(int A[], int B[], int h, int size, int sum){
    for(int i=0;i<size;i++){
        if(sum-A[i]>0 && B[sum - A[i]] != 0){
            cout << A[i] << " + " << sum - A[i] << " = " << sum << endl;
        }
        B[A[i]]++;
    }
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
    };
    
    int sum;
    cout << "Enter sum of two numbers: " << endl;
    cin >> sum;
    // TwoSum(A, size, sum);

    int h = max(A, size);
    int B[h+1] = {0};
    TwoSumWithHash(A, B, h, size, sum);
    return 0;
}