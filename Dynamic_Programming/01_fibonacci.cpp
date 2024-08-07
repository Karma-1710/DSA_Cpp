#include<bits/stdc++.h>
using namespace std;

int dynamicFibonacci(int n){
    int F[n];
    if(n <= 1){
        return n;
    }
    F[0] = 0;
    F[1] = 1;
    for(int i=2;i<n;i++){
        F[i] = F[i-2] + F[i-1];
    }
    return F[n-1];
}

int main(){
    int n = 7;
    cout << dynamicFibonacci(n) << endl;
    return 0;
}