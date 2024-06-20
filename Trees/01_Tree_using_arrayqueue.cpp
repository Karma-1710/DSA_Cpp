#include<iostream>
using namespace std;

class Node{
    public: 
        Node* lchild;
        int data;
        Node* rchild;
};

class Queue{
    private:
        int size;
        int front;
        int rear;
        Node **Q;
    public:
        Queue(int size);
        bool isFull();
        bool isEmpty();
        void enqueue(Node* x);
        Node* dequeue();
};

Queue::Queue(int size){
    this->size = size;
    front = -1;
    rear = -1;
    Q = new Node* [size];
}

bool Queue::isFull(){
    if(rear == size -1){
        return true;
    }
    return false;
}

bool Queue::isEmpty(){
    if(front == rear){
        return true;
    }
    return false;
}

void Queue::enqueue(Node* x){
    if(isFull()){
        cout << "Queue is Full!" <<  endl;
    }else{
        rear++;
        Q[rear] == x;
    }
}

Node* Queue::dequeue(){
    Node *x = nullptr; 
    if(isEmpty()){
        cout << "Queue Underflow" << endl;
    }else{
        front++;
        x = Q[front];
    }
    return x;
};

class Tree{
    private:
        Node* root;
    public:
        Tree() {root = nullptr;}
        void createTree();
};

void Tree::createTree(){
    Node* p;
    Node *t;
    int x;

    Queue q(25);

    root = new Node;
    cout << "Enter root value" << endl;
    cin >> x;
    root->data = x;
    root->lchild = root->rchild = nullptr;
    q.enqueue(root);

    while(!q.isEmpty()){
        p = q.dequeue();

        cout << "Enter left child value of " << p->data << ": " << endl;
        cin >> x;
        if(x != -1){
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = nullptr;
            p->lchild =  t;
            q.enqueue(t);
        }
        cout << "Enter right child value of " << p->data << endl;
        cin >> x;
        if(x != -1){
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = nullptr;
            p->rchild = t;
            q.enqueue(t);
        }
    }
}

int main(){
    Tree t;
    t.createTree();
    return 0;
}