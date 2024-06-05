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

    for(int i = 1; i<n;i++){
        temp = new Node;
        temp->data = A[i];
        temp->next = nullptr;   
        last->next = temp;
        last = temp;
    }
}

int MaxElement(Node* p) {
    int max = INT_MIN;
    while(p){
        if(p->data > max){
            max = p->data;
        }
        p = p->next;
    }
    return max;
}

int recursiveMax(Node* p){
    int x = 0;
    if(p == 0){
        return INT_MIN;
    }
    x = recursiveMax(p->next);
    return x > p->data ? x : p->data;
};

int main(){
    int A[] = {7,3,6,9,1,51};
    int n = sizeof(A)/sizeof(A[0]);
    
    createLinkedList(A, n);
    int maximumElement = MaxElement(head);
    int maximumeElementUsingRecursion = recursiveMax(head); 
    cout << maximumElement << endl; // 51
    cout << maximumeElementUsingRecursion << endl; // 51
    return 0;
}