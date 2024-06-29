#include<iostream>
using namespace std;

void FindAndCountDuplicates(int A[], int size){
    for(int i=0;i<size-1;i++){
        int count = 1;
        if(A[i] != -1){
            for(int j = i+1;j<size;j++){
                if(A[i] == A[j]){
                    count++;
                    A[j] = -1;
                }
            }
            if(count > 1){
                cout << "Element " << A[i] << " appeared " << count << " times" << endl; 
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
}

void FindAndCountDuplicatesUsingHash(int A[], int B[], int h, int size){
    for(int i=0;i<size;i++){
        B[A[i]]++;
    }
    for(int i=0;i<=h;i++){
        if(B[i] > 1){
            cout << "Element " << i << " appeared " << B[i] << " times" << endl;
        }
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
    }

    // FindAndCountDuplicates(A, size);
    int h = max(A, size);
    int B[h+1] = {0};

    FindAndCountDuplicatesUsingHash(A,B,h,size);
    return 0;
}