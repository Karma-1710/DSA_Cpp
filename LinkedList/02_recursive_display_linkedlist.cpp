#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
};

Node* head = nullptr;

void CreateLinkedList(int A[], int n){
    head = new Node;
    Node* temp;
    Node* last;

    head->data = A[0];
    head->next = nullptr;
    last = head;

    // Creating a Linkedlist
    for(int i =1; i< n; i++){
        temp = new Node;
        temp->data = A[i];
        temp->next = nullptr;
        last->next = temp;
        last = temp;
    };
};
void Display(){
    Node* p = head;
    while(p!= nullptr){
        cout<< p->data << "->" << flush;
        p = p->next;       
    }
}
void RecursiveDisplay(Node* p){
    if(p!=nullptr){
        cout << p->data << "->" << flush;
        RecursiveDisplay(p->next);
    }
}
void ReverseDisplay(Node* p){
    if(p!=nullptr){
        ReverseDisplay(p->next);
        cout << p->data << "->" << flush;
    }
}
int main() {
    int A[] = {3,7,4,3,8,9};
    int n = sizeof(A)/sizeof(A[0]);

    CreateLinkedList(A, n);
    // Display();
    // RecursiveDisplay(head);
    ReverseDisplay(head);
    return 0;
}

//Output: 3->7->4->3->8->9
//Output 2: 9->8->3->4->7->3