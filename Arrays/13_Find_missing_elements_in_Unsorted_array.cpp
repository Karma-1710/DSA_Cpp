#include<iostream>
using namespace std;

int min(int arr[], int size){
    int min = arr[0];
    for(int i=0;i<size;i++){
        if(arr[i] < min){
            min = arr[i];
        }
    }    
    return min;
};

int max(int arr[], int size){
    int max = arr[0];
    for(int i=0;i<size;i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    return max;
};

void missingElement(int A[], int B[], int size, int l, int h){
    for(int i=0;i<size;i++){
        B[A[i]]++;
    }
    for(int i = l;i<=h;i++){
        if(B[i] == 0){
            cout << "Missing Elements: " << i << " " << endl;
        }
    }
}

int main(){
    int* A;
    int size;

    cout << "Enter the size of Array: " << endl;
    cin >> size;

    A = new int[size];
    for(int i=0;i<size;i++){
        cout << "Enter element at index" << i << endl;
        cin >> A[i]; 
    };

    int l = min(A, size);
    int h = max(A, size);

    int B[h+1] = {0};

    missingElement(A, B, size, l, h);
    return 0;
}