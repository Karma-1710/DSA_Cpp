#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
};

class Queue{
    private:
        Node* front;
        Node* rear;
    public:
        Queue();
        void enqueue(int x);
        int dequeue();
        void Display();
};

Queue::Queue(){
    front = nullptr;
    rear = nullptr;
};

void Queue::enqueue(int x){
    Node* t = new Node;
    if(t == nullptr){
        cout << "Queue is Full" << endl;
    }else{
        t->data = x;
        t->next = nullptr;
        if(front == nullptr){
            front = rear = t;
        }else{
            rear->next = t;
            rear = t;
        }
    };
};

int Queue::dequeue(){
    int x =-1;
    Node* p;
    if(front == NULL){
        cout << "Queue is Empty" << endl;
    }else{
        p = front;
        front = front->next;
        x = p->data;
        delete p;
    }
    return x;
};

void Queue::Display(){
    Node *p = front;
    while(p){
        cout << p->data << " " << flush;
        p=p->next;
    }
}

int main(){
    int A[] = {1,3,5,7,9};
    int n = sizeof(A)/sizeof(A[0]);

    Queue q;
    for(int i=0;i<n;i++){
        q.enqueue(A[i]);
    }

    q.Display();

    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
        q.dequeue();
    }
    q.dequeue();
    return 0;
}