#include<iostream>
using namespace std;

void Perm(char S[], int k){
    static int A[10] = {0};
    static char Res[10] = {0};
    int i;
    if(S[k] == '\0'){
        Res[k] = '\0';
        cout << Res << endl;
    }else{
        for(i=0;S[i] != '\0'; i++){
            if(A[i] == 0){
                Res[k] = S[i];
                A[i] = 1;
                Perm(S, k+1);
                A[i] = 0;
            }
        }
    }
}

void swap(char* x, char* y){
    char temp = *x;
    *x = *y;
    *y = temp;
}

void PermUsingSwap(char S[], int l, int h){
    int i;
    if(l == h){
        cout << S << endl;
    }else{
        for(i=l;i<=h;i++){
            swap(S[l], S[i]);
            PermUsingSwap(S, l+1, h);
            swap(S[l], S[i]);
        }
    }
}

int main(){
    char S[] = "ABC";
    // Perm(S, 0);
    int i;
    for(i=0;S[i]!='\0';i++);
    PermUsingSwap(S, 0, i-1);
    return 0;
}