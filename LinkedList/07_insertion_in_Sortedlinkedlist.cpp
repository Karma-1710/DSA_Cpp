#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
};

Node* head= nullptr;

void createLinkedList(int A[], int n){
    head = new Node;
    Node* temp;
    Node* last;

    head->data = A[0];
    head->next = nullptr;
    last = head;

    for(int i=1;i<n;i++){
        temp = new Node;
        temp->data = A[i];
        temp->next = nullptr;
        last->next = temp;
        last = temp;
    }
}

void DisplayLinkedList(Node* p){
    while(p){
        cout << p->data << "->" << flush;
        p=p->next;
    }
};

void InsertAtLast(Node* p, int value){
    Node* t = new Node;
    Node *q;

    t->data = value;
    t->next = nullptr;

    if(head == NULL){
        head = t;
    }
    else{
        while(p && p->data < value){
            q=p;
            p=p->next;
        }
        if(p == head){
            t->next = head;
            head = t;
        }
        t->next = q->next;
        q->next = t;
    }
}

int main() {
    int A[] = {3,5,7,9,1,2};
    int n = sizeof(A)/sizeof(A[0]);

    createLinkedList(A, n);
    // DisplayLinkedList(head);
    InsertAtLast(head, 10);
    InsertAtLast(head, 45);
    DisplayLinkedList(head);
    return 0;
}