#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
};

void Insert(Node** ptrBins, int index){
    Node* t = new Node;
    t->data = index;
    t->next = nullptr;
    if(ptrBins[index] == nullptr){
        ptrBins[index] = t;
    }else{
        Node* p = ptrBins[index];
        while(p->next != nullptr){
            p = p->next;
        }
        p->next = t;
    }
}

int Delete(Node** ptrbins, int index){
    Node* p = ptrbins[index];
    ptrbins[index] = ptrbins[index]->next;
    int x = p->data;
    delete p;
    return x;
}


int findMax(int A[], int n){
    int max = A[0];
    for(int i=1;i<n;i++){
        if(A[i] > max){
            max = A[i];
        }
    }
    return max;
}

void BinSort(int A[], int n){
    int max = findMax(A, n);
    Node** bins;
    bins = new Node*[max+1]; 
    for(int i=0;i<max+1;i++){
        bins[i] = nullptr;
    }
    for(int i=0;i<n;i++){
        Insert(bins, A[i]);
    }
    int i=0,j=0;
    while(i < max+1){
        while(bins[i] != nullptr){
            A[j] = Delete(bins, i);
            j++;
        }
        i++;
    }
    delete[] bins;
}

void PrintArray(int A[], int n){
    for(int i=0;i<n;i++){
        cout << A[i] << " " << flush;
    }
}

int main(){
    int A[] = {6,8,3,10,15,6,9,12,6,3};
    int n = sizeof(A)/sizeof(A[0]);

    BinSort(A, n);
    PrintArray(A, n);
    return 0;
}