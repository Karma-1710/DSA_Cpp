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
    Node* last;
    Node* temp;

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
        cout << p->data << " " << flush;
        p = p->next;
    }
}

void removeDuplicates(Node* p){
    Node* q = head->next;

    while(q != NULL){
        if(p->data != q->data){
            p = q;
            q = q->next;
        }else{
            p->next = q->next;
            delete q;
            q = p->next;
        }
    }
}

int main(){
    int A[] = {3,5,5,8,8};
    int n = sizeof(A)/sizeof(A[0]);

    createLinkedList(A, n);
    removeDuplicates(head);
    DisplayLinkedList(head);

}