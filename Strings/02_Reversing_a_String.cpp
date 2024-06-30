#include<iostream>
using namespace std;

int GetLength(char A[]){
    int i;
    for(i=0;A[i]!='\0';i++){}
    return i;
}

int main(){
    char A[] = "Python";
    int length = GetLength(A);
    cout << length << endl;
    int i, j;
    char temp;

    for(j=0;A[j]!='\0';j++){};
    j--;
    for(i=0;i<j;i++,j--){
        temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }

    cout << A << endl;
    return 0;
}