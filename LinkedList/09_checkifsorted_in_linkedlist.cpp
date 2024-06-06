#include<iostream>
#include<climits>
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

int isSorted(Node* p){
    int x = INT_MIN;
    while(p){
        if(p->data < x){
            return 0;
        }
        x = p->data;
        p=p->next;
    }
    return 1;

}

int main(){
    int A[] = {3,5,7,9};
    int n = sizeof(A)/sizeof(A[0]);
    createLinkedList(A, n);
    // DisplayLinkedList(head);
    cout << isSorted(head) << endl;
    return 0;
}