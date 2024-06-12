#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
};

class Stack{
    private:
        Node* top;
    public:
        Stack();
        void push(int x);
        int pop();
        int isFull();
        int isEmpty();
        int stackTop();
        int peek(int pos);
};

Stack::Stack(){
    top = nullptr;
}

void Stack::push(int x){
    Node* t = new Node;
    if(t == nullptr){
        cout << "Stack Overflow" << endl;
    }else{
        t->data = x;
        t->next = top;
        top = t;
    }
}

int Stack::pop(){
    int x = -1;
    if(top == nullptr){
        cout << "Stack Underflow" << endl;
    }else{
        Node *p = top;
        x = p->data;
        top = top->next;
        delete p;
    }
    return x;
}

int Stack::isFull(){
    Node *t = new Node;
    int r = t ? 0 : 1;
    delete t;
    return r;
};

int Stack::isEmpty(){
    if(top == nullptr){
        return 1;
    }
    return 0;
}

int Stack::stackTop(){
    if(top){
        return top->data;
    }   
    return -1;
}

int Stack::peek(int pos){
    if(isEmpty()){
        return -1;
    }else{
        Node *p = top;
        for(int i=0;i<pos-1 && p;i++){
            p=p->next;
        }
        if(p){
            return p->data;
        }else{
            return -1;
        }
    }
}

int main(){
    int A[] = {1,3,5,7,9};
    int n = sizeof(A)/sizeof(A[0]);
    Stack stk;

    for(int i=0;i<n;i++){
        stk.push(A[i]);
    };

    cout << "Stack peek at 3rd: " << stk.peek(3) << endl;
    cout << "Stack peek at 10th: " << stk.peek(10) << endl;
    cout << "Stack top: " << stk.stackTop() << endl;
    cout << "Stack full: " << stk.isFull() << endl;
    cout << "Stack empty: " << stk.isEmpty() << endl;

    cout << "Popped: " << flush;
    for (int i=0; i<n; i++){
        cout << stk.pop() << ", " << flush;
    }
    cout << endl;
    cout << stk.pop() << endl;
    return 0;
}