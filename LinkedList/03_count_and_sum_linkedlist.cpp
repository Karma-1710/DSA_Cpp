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
    head->data = A[0];
    head->next = nullptr;

    Node* temp;
    Node* last;
    last = head;

    for(int i=1; i<n;i++){
        temp = new Node;
        temp->data = A[i];
        temp->next = nullptr;
        last->next = temp;
        last = temp;
    }
}

int Count(Node* p){
    int count = 0;
    while(p){
        count++;
        p=p->next;
    }
    return count;
}

// Recursive Count
int RecursiveCount(Node* p){
    if(p==0){
        return 0;
    }
    return RecursiveCount(p->next) + 1;
};

// Sum of all elements in a Linked List

int Sum(Node* p){
    int sum = 0;
    while(p) {
        sum+=p->data;
        p=p->next;
    }
    return sum;
};

int recursiveSum(Node* p){
    if(p==0){
        return 0;
    }
    return  recursiveSum(p->next) + p->data;
}

int main(){
    int A[] = {3,4,5,6,7,8, 9,10};
    int n = sizeof(A)/sizeof(A[0]);

    CreateLinkedList(A, n);
    int count = Count(head);
    int recursiveCount = RecursiveCount(head);
    int ResultofSum = Sum(head);
    int ResultofRecursiveSum = recursiveSum(head);
    cout << "Number of nodes in the linked list: " << count << endl; // 8
    cout << "Number of nodes in the linked list using recursion: " << recursiveCount << endl; // 8
    cout << "Result of Sum of Elements in a Linked List: " << ResultofSum << endl; // 52 
    cout << "Result of Sum of Elements in a Linked List using recursion: " << ResultofRecursiveSum << endl; // 52
    return 0;
}