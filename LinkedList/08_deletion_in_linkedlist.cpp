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
int count(Node* p) {
    int count = 0;
    while (p) {
        count++;
        p = p->next;
    }
    return count;
}

int Delete(Node* p,int position){
    Node* q = nullptr;
    int x = -1;
    if(position < 1 || position > count(p)){
        return -1;
    }
    if(position == 1){
        x = head->data;
        head = head->next;
        delete p;
    }else{
        for(int i=0; i<position-1 && p;i++){
            q=p;
            p=p->next;
        }
        if(p){
            x = p->data;
            q->next = p->next;
            delete p;
        }
    }
    return x;
}

int main(){
    int A[] = {3,5,7,9,0,1};
    int n = sizeof(A)/sizeof(A[0]);

    createLinkedList(A, n);
    // DisplayLinkedList(head);
    Delete(head,5);
    DisplayLinkedList(head);
    return 0;
}