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
    Node* last = head;

    for(int i=1; i<n;i++){
        temp = new Node;
        temp->data = A[i];
        temp->next = nullptr;
        last->next=temp;
        last=temp;
    }
}

Node* Search(Node* p, int key){
    while(p!=nullptr){
        if(key == p->data){
            return p;
        }
        p=p->next;
    }
    return NULL;
}


int main(){
    int A[] = {3,6,1,7,8,5};
    int n = sizeof(A)/sizeof(A[0]);

    createLinkedList(A, n);
    cout << Search(head, 8) << endl;
    return 0;
}