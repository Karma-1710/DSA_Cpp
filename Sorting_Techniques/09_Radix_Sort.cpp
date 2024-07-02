#include<iostream>
#include<cmath>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
};

int findMax(int A[], int n){
    int max = A[0];
    for(int i=0;i<n;i++){
        if(A[i] > max){
            max = A[i];
        }
    }
    return max;
}

int CountDigits(int max){
    int count = 0;
    while(max!=0){
        max=max/10;
        count++;
    }
    return count;
}

int getBinIndex(int x, int index){
    return (int)(x/pow(10, index))%10;
}

void Insert(Node** binsPtr, int value, int index){
    Node* t= new Node;
    t->data = value;
    t->next = nullptr;

    if(binsPtr[index] == nullptr){
        binsPtr[index] = t;
    }else{
        Node* p = binsPtr[index];
        while(p->next!=nullptr){
            p =p->next;
        }
        p->next = t;
    }
}

int Delete(Node** binsPtr, int index){
    Node* p = binsPtr[index];
    binsPtr[index] = binsPtr[index]->next;
    int x = p->data;
    delete p;
    return x;
}

void RadixSort(int A[], int n){
    int max = findMax(A,n);
    int passes = CountDigits(max);

    Node** bins = new Node*[10];
    for(int i=0;i<10;i++){
        bins[i] = nullptr;
    }
    for(int pass=0;pass<passes;pass++){
        for(int i=0;i<n;i++){
            int binIndex = getBinIndex(A[i], pass);
            Insert(bins, A[i], binIndex);
        }
        int i=0;
        int j=0;
        while(i<10){
            while(bins[i] != nullptr){
                A[j] = Delete(bins, i);
                j++;
            }
            i++;
        }
        for(int i=0;i<10;i++){
            bins[i] = nullptr;
        }
    }
    delete[] bins;
}

void PrintArray(int A[], int n){
    for(int i=0;i<n;i++){
        cout << A[i] << " " << flush;
    }
}

int main(){
    int A[] = {237,146,259,348,152,163,235,48,36,62};
    int n = sizeof(A)/sizeof(A[0]);

    RadixSort(A, n);
    PrintArray(A, n);
    return 0;
}