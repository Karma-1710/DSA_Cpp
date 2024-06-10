#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
};

Node* head = nullptr;

void createCircularLL(int A[], int n){
    head = new Node;
    head->data = A[0];
    head->next = head;

    Node* temp;
    Node* last;
    last = head;

    for(int i =1;i<n;i++){
        temp = new Node;
        temp->data = A[i];
        temp->next = last->next;
        last->next = temp;
        last = temp;
    }
}

void DisplayCircularLL(Node* p){
    do
    {
        cout << p->data << " " << flush;
        p=p->next;
    } while (p != head); 
}

void RecursiveDisplayCircularLL(Node* p){
    static int flag = 0;
    if(p != head || flag == 0){
        flag=1;
        cout << p->data << " " << flush;
        RecursiveDisplayCircularLL(p->next);
    }flag=0;
}

int main(){
    int A[] = {3,5,7,9,10};
    int n = sizeof(A)/sizeof(A[0]);
    createCircularLL(A, n);
    // DisplayCircularLL(head);
    RecursiveDisplayCircularLL(head);
    return 0;
}