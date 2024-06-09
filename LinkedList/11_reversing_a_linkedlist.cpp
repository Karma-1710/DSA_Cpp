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
    head->data = A[0];
    head->next = nullptr;
    Node* temp;
    Node* last;
    last = head;

    for(int i=1; i<n;i++){
        temp = new Node;
        temp->data = A[i];
        temp->next = nullptr;
        last->next = temp;
        last = temp;
    }
}

void DisplayLinkedList(Node* p){
    while(p!= NULL){
        cout << p->data << " " << flush;
        p = p->next;
    }
};

int count(Node* p){
    int count = 0;
    while(p!=NULL){
        count++;
        p=p->next;
    }
    return count;
}

void Reverse1(Node* p){
    int n = count(p);
    int *A, i=0;
    Node* q = p;
    A = new int[n];
    while(q!=NULL){
        A[i] = q->data;
        q=q->next;
        i++;
    }
    i--;
    q = p;
    while(q!= NULL){
        q->data = A[i];
        q=q->next;
        i--;
    }
    delete []A;
}


// Using Sliding pointers
void Reverse2(Node* p){
    int n = count(p);
    Node *q = nullptr;
    Node *r = nullptr;
    // p pointer points towards the head node of linked list and r and q are Null pointers
    while(p!=NULL){
        r=q;
        q=p;
        p=p->next;
        q->next = r;
    }
    head = q;
    // we reach the end of the node when p points to NULL, q is pointing to last node of LL and r is pointing to 2nd last element
}


void RecursiveReverse(Node* q, Node* p){
    if(p!=NULL){
        RecursiveReverse(p, p->next);
        p->next = q;
    }else{
        head = q;
    }
}


int main() {
    int A[] = {3,5,7,9,1,0};
    int n = sizeof(A)/sizeof(A[0]);
    createLinkedList(A, n);
    // DisplayLinkedList(head);
    // Reverse2(head);
    RecursiveReverse(nullptr, head);
    DisplayLinkedList(head);
    return 0;
}