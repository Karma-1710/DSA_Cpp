#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
};

Node* first = nullptr;
Node* second = nullptr;
Node* third = nullptr;

void createLinkedList(int A[], int n){
    first = new Node;
    Node* temp;
    Node* last;

    first->data = A[0];
    first->next = nullptr;
    last = first;
    for(int i=1;i<n;i++){
        temp = new Node;
        temp->data = A[i];
        temp->next = nullptr;
        last->next = temp;
        last = temp;
    };
}
void createLinkedList2(int B[], int m){
    second = new Node;
    Node* temp;
    Node* last;

    second->data = B[0];
    second->next = nullptr;
    last = second;
    for(int i=1;i<m;i++){
        temp = new Node;
        temp->data = B[i];
        temp->next = nullptr;
        last->next = temp;
        last = temp;
    };
}

void DisplayLinkedList(Node* p){
    while(p!=NULL){
        cout << p->data << " " << flush;
        p=p->next;
    }
}

void Concatenate(Node* p, Node* q){
    third = p;
    while(p->next != NULL){
        p=p->next;
    }
    p->next = q;
}

void Merge(Node* p, Node* q){
    Node* last;
    if(first->data < second->data){
        third = first;
        last = first;
        first = first->next;
        last->next = nullptr;
    }
    else{
        third = second;
        last = second;
        second = second->next;
        last->next = nullptr;
    }
    while(first !=NULL && second !=NULL){
        if(first->data < second->data){
            last->next = first;
            last = first;
            first = first->next;
            last->next=nullptr;
        }else{
            last->next = second;
            last = second;
            second = second->next;
            last->next = nullptr;
        }
    }
    if(first!=NULL){
        last->next = first;
    }else{
        last->next = second;
    }
}

int main(){
    int A[] = {3,5,7,9};
    int B[] = {2,4,6,8};

    int n = sizeof(A)/sizeof(A[0]);
    int m = sizeof(B)/sizeof(B[0]);
    createLinkedList(A, n);
    createLinkedList2(B, m);
    // DisplayLinkedList(first); 
    // cout << " " << endl;
    // DisplayLinkedList(second);
    // Concatenate(first, second);
    // printf("\n");
    // DisplayLinkedList(third);
    Merge(first, second);
    DisplayLinkedList(third);
    return 0;
}