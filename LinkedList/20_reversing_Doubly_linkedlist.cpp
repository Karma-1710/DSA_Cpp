#include<iostream>
using namespace std;

class Node{
    public:
        Node* prev;
        int data;
        Node* next;
};

Node* head = nullptr;

void createDoublyLL(int A[], int n){
    head = new Node;
    head->data = A[0];
    head->prev = head->next = NULL;

    Node* temp;
    Node* last;
    last = head;
    for(int i=1;i<n;i++){
        temp = new Node;
        temp->data = A[i];
        temp->next = last->next;
        temp->prev = last;
        last->next = temp;
        last = temp;
    }
};

void DisplayDoublyLL(Node* p){
    while(p){
        cout << p->data << " " << flush;
        p=p->next;
    }
}

void ReverseDoublyLL(Node* p){
    Node* temp;
    while(p){
        temp = p->next;
        p->next = p->prev;
        p->prev = temp;
        p=p->prev;
        if(p!=NULL && p->next == NULL){
            head = p;
        }
    }
}

int main(){
    int A[] = {3,5,7,9,1,0};
    int n = sizeof(A)/sizeof(A[0]);
    createDoublyLL(A,n);
    ReverseDoublyLL(head);
    DisplayDoublyLL(head);
    return 0;
}