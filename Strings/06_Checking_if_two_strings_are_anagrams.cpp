#include<iostream>
using namespace std;

int main(){
    char A[] = "observe";
    char B[] = "verbose";

    int H[26] = {0};
    int i;
    for(i=0;A[i]!='\0';i++){
        H[A[i] - 97]++;
    }
    for(i=0;B[i]!='\0';i++){
        H[B[i] - 97]--;
        if(H[B[i]-97] < 0){
            cout << "Not an Anagram" << endl;
            break;
        }
    }if(H[B[i]] == '\0'){
        cout << "It is an Anagram" << endl;
    }
    return 0;
}