#include<iostream>
#include<cstring>
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
        int isEmpty();
        char stackTop();
};

Stack::Stack(){
    top = nullptr;
};

void Stack::push(char x){
    Node *t = new Node;
    if(t == nullptr){
        cout << "Stack Overflow" << endl;
    }else{
        t->data = x;
        t->next = top;
        top = t;
    };
};

char Stack::pop(){
    Node *p;
    char x;
    if(top == nullptr){
        cout << "Stack Underflow" << endl;
    }else{
        p=top;
        top=top->next;
        x = p->data;
        delete p;
    }
    return x;
};

void Stack::display(){
    Node *p = top;
    while(p){
        cout << p->data << " " << flush;
        p=p->next;
    };
};

int Stack::isEmpty(){
    if(top == nullptr){
        return 1;
    };
    return 0;
};

char Stack::stackTop(){
    if(top){
        return top->data;
    };
    return -1;
};

bool isOperand(char x){
    if(x == '+' || x == '-' || x == '*' || x == '/'){
        return false;
    };
    return true;
};

int precedence(char x){
    if(x == '+' || x == '-') {
        return 1;
    } else if(x == '*' || x == '/'){
        return 2;
    };
    return 0;
};

char* InfixToPostfix(const char* infix){
    int i=0,j=0;
    Stack stk;
    int len = strlen(infix);
    char* postfix = new char[len+1];
    while(infix[i] != '\0'){
        if(isOperand(infix[i])){
            postfix[j] = infix[i];
            i++;
            j++;
        }else{
            if(precedence(infix[i]) > precedence(stk.stackTop())){
                stk.push(infix[i]);
                i++;
            }else{
                postfix[j] = stk.pop();
                j++;
            };
        };
    };
    while(!stk.isEmpty()){
        postfix[j] = stk.pop();
        j++;
    };
    postfix[j] = '\0';
    return postfix;
};

int main(){
    const char* infix = "a+b*c-d/e";
    cout << InfixToPostfix(infix) << endl;
    return 0;
}