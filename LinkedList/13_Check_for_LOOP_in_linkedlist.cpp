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
}

void DisplayLinkedList(Node* p){
    while(p){
        cout << p->data << " " << flush;
        p=p->next;
    }
}

bool isLoop(Node* p){
    Node* q;
    q = p;
    do{
        p=p->next;
        q=q->next;
        q = q ? q->next : q; 
    } while (p && q && p!= q); //while both p and q does not become NULL and they both do not become equal
    return p == q ? true : false;
}

int main(){
    int A[] = {3,5,7,9,10};
    int n = sizeof(A)/sizeof(A[0]);
    createLinkedList(A, n);

    Node* t1, *t2;
    t1 = head->next->next;
    t2 = head->next->next->next->next;
    t2->next = t1;
    // DisplayLinkedList(head);
    printf("\n");
    cout << isLoop(head) << endl;
    return 0;
}