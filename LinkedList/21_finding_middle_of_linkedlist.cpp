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
    head->next = NULL;

    Node* temp;
    Node* last;
    last = head;
    for(int i=1;i<n;i++){
        temp = new Node;
        temp->data = A[i];
        temp->next = last->next;
        last->next = temp;
        last = temp;
    }
}

void DisplayLinkedList(Node* p){
    while(p){
        cout << p->data << " " << flush;
        p=p->next;
    }
}

int midElement(Node* p){
    Node* q = head;
    while(p){
        p=p->next;
        if(p){
            p=p->next;
        }
        if(p){
            q=q->next;
        }
    }
    return q->data;
}

int main(){
    int A[] = {3,5,7,9,1};
    int n = sizeof(A)/sizeof(A[0]);
    createLinkedList(A, n);
    DisplayLinkedList(head);
    printf("\n");
    cout << midElement(head) << endl;
    return 0;
}