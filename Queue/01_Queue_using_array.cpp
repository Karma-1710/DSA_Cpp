#include<iostream>
using namespace std;

class Queue{
    private:
        int size;
        int front;
        int rear;
        int* Q;
    public:
        Queue(int size);
        int isFull();
        int isEmpty();
        void enqueue(int x);
        int dequeue();
        void Display();
};

Queue::Queue(int size){
    this->size = size;
    front = -1;
    rear = -1;
    Q = new int[size];
};

int Queue::isFull(){
    if(rear == size - 1){
        return 1;
    }
    return 0;
}

int Queue::isEmpty(){
    if(front ==  rear){
        return 1;
    }
    return 0;
}

void Queue::enqueue(int x){
    if(isFull()){
        cout << "Queue is Full" << endl;       
    }else{
        rear++;
        Q[rear] = x;
    }
}

int Queue::dequeue(){
    int x=-1;
    if(isEmpty()){
        cout << "Queue is empty" << endl;
    }else{
        front++;
        x = Q[front];
    }
    return x;
}

void Queue::Display(){
    for(int i=front+1;i<=rear;i++){
        cout << Q[i] << flush;
        if(i < rear){
            cout << "<-" << flush;
        }
    }
}

int main(){
    int A[] = {1,3,5,7,9};
    int size = sizeof(A)/sizeof(A[0]);
    Queue q(size);

    for(int i=0;i<size;i++){
        q.enqueue(A[i]);
    }
    q.Display();
    cout << endl;
    q.enqueue(10);
    for(int i=0;i<size;i++){
        q.dequeue();
    }
    q.dequeue();

    return 0;
}