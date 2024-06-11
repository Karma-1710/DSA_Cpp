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

    for(int i = 1;i<n;i++){
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

int Length(Node* p){
    int len = 0;
    while(p){
        len++;
        p=p->next;
    }
    return len;
}

int Delete(Node* p, int pos){
    int x = 0;
    Node* q;
    if(pos<0 || pos>Length(p)){
        return -1;
    }
    if(pos == 1){
        q = head;
        head= head->next;
        x = q->data;
        delete q;
        if(head){
            head->prev = NULL;
        }
    }else{
        for(int i=0;i<pos-1;i++){
            p=p->next;
        }
        p->prev->next = p->next;
        if(p->next){
            p->next->prev = p->prev;
        }
        x = p->data;
        delete p;
    }
    return x;
}   

int main(){
    int A[] = {3,5,7,9,1,0};
    int n = sizeof(A)/sizeof(A[0]);
    createDoublyLL(A, n);
    Delete(head, 3);
    DisplayDoublyLL(head);
    return 0;
}