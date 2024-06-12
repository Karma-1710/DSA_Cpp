#include<iostream>
using namespace std;

class Stack{
    private:
        int size;
        int top;
        int* S;
    public:
        Stack(int size);
        void push(int x);
        int pop();
        int peek(int pos);
        int isFull();
        int isEmpty();
        void Display();
        int stackTop();
};

Stack::Stack(int size){
    this->size = size;
    top = -1;
    S= new int[size];
};

void Stack::push(int x){
    if(isFull()){
        cout << "Stack Overflow" << endl;
    }else{
        top++;
        S[top] = x;
    }
}

int Stack::pop(){
    int x = 1;
    if(isEmpty()){
        cout << "Stack Underflow" << endl;
    }else{
        S[top] = x;
        top--;
    }
    return x;
}

int Stack::peek(int pos){
    int x = -1;
    if(top - pos + 1 < 0 || top-pos+1 == size){
        cout << "Invalid Position" << endl;
    }else{
        x = S[top-pos+1];
    }
    return x;
}

int Stack::isFull(){
    if(top == size-1){
        return 1;
    }
    return 0;
}

int Stack::isEmpty(){
    if(top == -1){
        return 1;
    }
    return 0;
}

void Stack::Display(){
    for(int i=top;i>=0;i--){
        cout << S[i] << " " << flush;
    }
    cout << endl;
}

int Stack::stackTop(){
    if(isEmpty()){
        return -1;
    }
    return S[top];
}

int main(){
    int A[] = {3,5,7,9,1,10};
    int n = sizeof(A)/sizeof(A[0]);

    Stack stk(n);
    for(int i=0;i<n;i++){
        stk.push(A[i]);
    }
    stk.push(11);

    cout << "Stack Full: " << stk.isFull() << endl;
    cout << "Stack: " << flush;
    stk.Display();

    // Peek
    cout << "Peek at 1th: " << stk.peek(1) << endl;
    cout << "Peek at 3rd: " << stk.peek(3) << endl;
    cout << "Peek at 10th: " << stk.peek(10) << endl;
 
    // Top element
    cout << "Top element: " << stk.stackTop() << endl;
 
    // Pop out elements from stack
    cout << "Popped out elements: " << flush;
    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
        cout << stk.pop() << ", " << flush;
    }
    cout << endl;
    stk.pop();
 
    cout << "Stack empty: " << stk.isEmpty() << endl;
}