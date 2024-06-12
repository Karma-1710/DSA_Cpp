#include<iostream>
using namespace std;

class Node{
    public:
        char data;
        Node* next;
};

class Stack{
    private:
        Node* top;
    public:
        Stack();
        void push(char x);
        char pop();
        void display();
        int isBalanced(const char* exp);
};

Stack::Stack(){
    top = nullptr;
}

void Stack::push(char x){
    Node* t = new Node;
    if(t == nullptr){
        cout << "Stack Overflow" << endl;
    }else{
        t->data = x;
        t->next = top;
        top = t;
    }
}

char Stack::pop(){
    char x;
    Node* p;
    if(top == nullptr){
        cout << "Stack underflow" << endl;
    }else{
        p = top;
        top = top->next;
        x = p->data;
        delete p;
    }
    return x;
}

void Stack::display(){
    Node* p;
    p=top;
    while(p){
        cout << p->data << " " << flush;
        p=p->next;
    }
}

int Stack::isBalanced(const char *exp){
    for(int i=0;exp[i]!='\0';i++){
        if(exp[i] == '('){
            push(exp[i]);
        }else if(exp[i]==')'){
            if(top == NULL){
                return 0;
            }else{
                pop();
            }
        }
    }
    if(top == NULL){
        return 1;
    }else{
        return 0;
    }
}

int main(){
    const char *exp = "((a+b)*(c-d))";
    Stack stk;
    cout << stk.isBalanced(exp) << endl;
    return 0;
}