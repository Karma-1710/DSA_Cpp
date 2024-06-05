#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
};

Node* head = nullptr;

void createLinkedList(int A[], int n){
    head = new Node;
    Node* temp;
    Node* last;

    head->data = A[0];
    head->next = nullptr;
    last = head;
    
    for(int i=1; i<n;i++){
        temp = new Node;
        temp->data = A[i];
        temp->next = nullptr;
        last->next = temp;
        last = temp;
    }
};

void DisplayLinkedList(Node* p){
    while(p){
        cout << p->data << "->" << flush;
        p = p->next;
    }
}

void Insert(int pos, int value){
    Node* t;
    Node* p;

    if(pos == 0){
        t = new Node;
        t->data = value;
        t->next = head;
        head = t;
    }else if(pos > 0){
        p = head;
        for(int i =0; i<pos-1 && p;i++){
            p=p->next;
        }
        t = new Node;
        t->data= value;
        t->next = p->next;
        p->next = t;
    }
}

int main(){
    int A[] = {3,6,8,5,1,2};
    int n = sizeof(A)/sizeof(A[0]);
    
    createLinkedList(A, n);
    // DisplayLinkedList(head);
    Insert(6, 9);
    DisplayLinkedList(head);
    return 0;
}