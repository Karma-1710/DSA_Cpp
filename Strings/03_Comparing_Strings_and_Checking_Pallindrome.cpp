#include<iostream>
using namespace std;

int CheckPallindrome(char C[]){
    int i=0, j=0;
    for(j=0;C[j] != '\0';j++){};
    j = j-1;
    while(i < j){
        if(C[i] != C[j]){
            return 0;
        }else{
            i++;
            j--;
        }
    }
    return 1;
}

int main(){
    char A[] = "Painter";
    char B[] = "Painting";
    int i, j;
    for(i=0,j=0;A[i] != '\0' && B[j] != '\0';i++,j++){
        if(A[i] != B[j]){
            break;
        }
    }
    if(A[i] == B[j]){
        cout << "Strings are equal" << endl;
    } else if(A[i] < B[j]){
        cout << "String A is Smaller" << endl;
    } else{
        cout << "String A is Greater" << endl;
    }

    char C[] = "MadaMMadaM";
    cout <<  CheckPallindrome(C) << endl;
    return 0;
}