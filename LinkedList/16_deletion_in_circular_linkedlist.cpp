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
    for(int i=1;i<n;i++){
        temp = new Node;
        temp->data = A[i];
        temp->next = last->next;
        last->next = temp;
        last= temp;
    }
}

void DisplayCircularLL(Node* p){
    do
    {
        cout << p->data << " " << flush;
        p=p->next;
    } while (p!=head);
    
}
int Length(Node* p){
    int count = 0;
    do
    {
        count++;
        p=p->next;
    } while (p != head);
    return count;
}

int Delete(Node* p, int pos){
    int x = 0;
    if(pos<0 || pos>Length(p)){
        return -1;
    }
    if(pos == 1){
        while(p->next != head){
            p=p->next;
        }
        x=head->data;
        if(p == head){
            delete head;
            head = NULL;
        }else{
            p->next = head->next;
            delete head;
            head = p->next;
        }
    }else{
        Node* q;
        for(int i=0; i<pos-2;i++){
            p=p->next;
        }
        q=p->next;
        p->next = q->next;
        x = q->data;
        delete q;
    }
    return x;
}

int main(){
    int A[] = {3,5,7,9,10};
    int n = sizeof(A)/sizeof(A[0]);
    
    createCircularLL(A, n);
    // DisplayCircularLL(head);
    Delete(head, 1);
    DisplayCircularLL(head);
    return 0;
}