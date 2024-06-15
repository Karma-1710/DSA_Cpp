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
        void Display();
        int isEmpty();
        char stackTop();
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
    };
};

char Stack::pop(){
    Node* p;
    char x;
    if(top == nullptr){
        cout << "Stack Underflow" << endl;
    }else{
        p = top;
        top = top->next;
        x = p->data;
        delete p;
    }
    return x;
};

int Stack::isEmpty(){
    if(top == nullptr){
        return 1;
    };
    return 0;
};

char Stack::stackTop(){
    char x = '\0';
    if(top){
        x = top->data;
    }
    return x;
};


void Stack::Display(){
    Node* p = top;
    while(p){
        cout << p->data << " " << flush;
        p=p->next;
    };
};

int isOperand(char x){
    if(x == '+' || x == '-' || x == '*' || x == '/'){
        return 0;
    }
    return 1;
};

int EvaluatePostfix(const char* postfix){
    int i, x1, x2, r;
    Stack stk;
    for(i=0;postfix[i]!='\0';i++){
        if(isOperand(postfix[i])){
            stk.push(postfix[i] - '0');
        }else{
            x2 = stk.pop();
            x1 = stk.pop();
            switch (postfix[i])
            {
            case '+':
                r = x1 + x2;
                stk.push(r);
                break;
            case '-':
                r = x1 - x2;
                stk.push(r);
                break;
            case '*':
                r = x1 * x2;
                stk.push(r);
                break;
            case '/':
                r = x1 / x2;
                stk.push(r);
                break;
            default:
                break;
            }
        }
    }
    return stk.pop();
}


int main(){
    const char* postfix = "35*62/+4-";
    cout << EvaluatePostfix(postfix);
    return 0;
}