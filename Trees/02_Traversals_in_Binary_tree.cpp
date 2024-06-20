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
};

bool Queue::isFull(){
    if(rear == size - 1){
        return true;
    }
    return false;
};

bool Queue::isEmpty(){
    if(front == rear){
        return true;
    }
    return false;
};


void Queue::enqueue(Node* x){
    if(isFull()){
        cout << "Queue is Full" << endl;
    }else{
        rear++;
        Q[rear] = x;
    }
};

Node* Queue::dequeue(){
    Node* x = nullptr;
    if(isEmpty()){
        cout << "Queue is Empty" << endl;
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
        Tree(){root = nullptr;}
        void createTree();
        void Preorder(){Preorder(root);}
        void Preorder(Node* p);
        void Inorder(){Inorder(root);}
        void Inorder(Node* p);
        void Postorder(){Postorder(root);}
        void Postorder(Node* p);
};

void Tree::createTree(){
    Node *p;
    Node* t;
    int x;
    Queue q(15);
    root = new Node;
    cout << "Enter root value: " << endl;
    cin >> x;
    root->data = x;
    root->lchild = root->rchild = nullptr;
    q.enqueue(root);

    while(!q.isEmpty()){
        p = q.dequeue();

        cout << "Enter the value for left child of " << p->data << ": " << endl;
        cin >> x;
        if(x != -1){
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = nullptr;
            p->lchild = t;
            q.enqueue(t);
        }
        cout << "Enter the value for right child of " << p->data << ": " << endl;
        cin >> x;
        if(x != -1){
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = nullptr;
            p->rchild = t;
            q.enqueue(t);
        }
    }
};

void Tree::Preorder(Node *p){
    if(p){
        cout << p->data << flush;
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
};

void Tree::Inorder(Node* p){
    if(p){
        Inorder(p->lchild);
        cout << p->data << flush;
        Inorder(p->rchild);
    }
}

void Tree::Postorder(Node* p){
    if(p){
        Postorder(p->lchild);
        Postorder(p->rchild);
        cout << p->data << flush;
    }
}

int main(){
    Tree t;
    t.createTree();
    cout << "Preorder traversal: ";
    t.Preorder();
    cout << endl;
    cout << "Inorder traversal: ";
    t.Inorder();
    cout << endl;
    cout << "Postorder traversal: ";
    t.Postorder();
    cout << endl;
    return 0;
}