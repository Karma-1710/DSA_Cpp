#include<iostream>
using namespace std;

int main(){
    char A[] = "WELCOME";
    cout << A << endl;
    int i;
    for(i=0;A[i] != '\0';i++){}
    cout << "Length of the String is: " << i << endl; 

    for(i=0;A[i]!='\0';i++){
        A[i]+=32;
    }
    cout << A << endl;

    char B[] = "WELcome";
    for(i =0;B[i]!='\0';i++){
        if(B[i] >=65 && B[i] <= 90){
            B[i]+=32;
        }else if(B[i] >= 'a' && B[i] <= 122){
            B[i]-=32;
        }
    }
    cout << B << endl;
    return 0;
}