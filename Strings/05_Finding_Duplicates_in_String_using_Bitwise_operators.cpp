#include<iostream>
using namespace std;

int main(){
    char A[] = "findingsss";
    long int h1 = 0;
    long int h2 = 0;
    long int x = 0;

    for(int i=0;A[i] != '\0';i++){
        x = 1;
        x = x<<(A[i]-97);
        if( (x&h1) > 0){
            cout << A[i] << " is duplicate" << endl;
        }else{
            h1 = x | h1;
        }
    }
    return 0;
}