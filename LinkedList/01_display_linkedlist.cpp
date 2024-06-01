#include<iostream>
using namespace std;

//Creating the structure of a node using class
class Node{
    public:
        int data;
        Node* next;
};


int main() {
    int A[] = {3,5,6,7,9,1};

    Node* head = new Node;
    Node* temp;
    Node* last;

    head->data = A[0];
    head->next = nullptr;
    last = head;

    // Creating a Linked List
    for(int i=1; i<sizeof(A)/sizeof(A[0]); i++){
        temp =  new Node;
        temp->data = A[i];
        temp->next = nullptr;
        last->next = temp;
        last = temp;
    }

    // Displaying a Linked List
    Node* p = head;
    while(p != nullptr){
        cout << p->data << "->" << flush;
        p=p->next;
    }

    return 0;
}


// OUTPUT: 3->5->6->7->9->1

