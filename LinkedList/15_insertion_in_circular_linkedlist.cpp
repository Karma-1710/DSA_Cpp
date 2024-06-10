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
    last=head;
    for(int i=1; i<n;i++){
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
    } while (p!=head);
}

void InsertinCircularLL(Node* p, int pos, int x){
    Node* t;
    if(pos == 0){
        t = new Node;
        t->data = x;
        if(head == NULL){
            head=t;
            head->next = head;
        }else{
            while(p->next != head){
                p=p->next;
            }
            p->next = t;
            t->next = head;
            head=t;
        }
    }else{
        t = new Node;
        t->data = x;
        for(int i=0;i<pos-1;i++){
            p=p->next;
        }
        t->next = p->next;
        p->next = t;
    }
}

int main(){
    int A[] = {3,5,7,9,10};
    int n = sizeof(A)/sizeof(A[0]);
    createCircularLL(A, n);
    // DisplayCircularLL(head);
    InsertinCircularLL(head, 0, 45);
    DisplayCircularLL(head);
    return 0;
}