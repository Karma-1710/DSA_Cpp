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
    Node *p;
    char x;
    if(top == nullptr){
        cout << "Stack Underflow" << endl;
    }else{
        p = top;
        top = top->next;
        x = p->data;
        delete p;
    };
    return x;
};

void Stack::display(){
    Node* p = top;
    while(p){
        cout << p->data << " " << flush;
        p=p->next;
    };
};

int Stack::isEmpty(){
    if(top == nullptr){
        return 1;
    }
    return 0;
}

char Stack::stackTop(){
    char x;
    if(top){
        x =top->data;
    }
    return x;
}

int isOperand(char x){
    if(x == '+' || x == '-' || x == '*' || x == '/' || x == '^' || x == '(' || x == ')'){
        return 0;
    }
    return 1;
}

int OutstackPre(char x){
    if(x == '+' || x == '-'){
        return 1;
    }else if(x == '*' || x == '/'){
        return 3;
    }else if(x == '^'){
        return 6;
    }else if(x == '('){
        return 7;
    }else if(x == ')'){
        return 0;
    }
    return -1;
}

int InstackPre(char x){
    if(x == '+' || x == '-'){
        return 2;
    }else if(x == '*' || x == '/'){
        return 4;
    }else if(x == '^'){
        return 5;
    }else if(x == '('){
        return 0;
    }
    return -1;
}

char* InfixToPostfix(const char* infix){
    int i=0,j=0;
    int len = strlen(infix);
    Stack stk;
    char* postfix = new char[len+1];
    while(infix[i] != '\0'){
        if(isOperand(infix[i])){
            postfix[j] = infix[i];
            i++;
            j++;
        }else{
            if(stk.isEmpty() || OutstackPre(infix[i]) > InstackPre(stk.stackTop())){
                stk.push(infix[i]);
                i++;
            } else if(OutstackPre(infix[i]) == InstackPre(stk.stackTop())){
                stk.pop();
                i++;
            }else{
                postfix[j] = stk.pop();
                j++;
            }
        }
    }
    while(!stk.isEmpty()){
        postfix[j] =stk.pop();
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}

int main(){
    const char* infix = "((a+b)*c)-d^e^f";
    cout << InfixToPostfix(infix) << endl;
    return 0;
}