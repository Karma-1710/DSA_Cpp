#include<iostream>
using namespace std;

class DEQueue{
    private:
        int size;
        int front;
        int rear;
        int* Q;
    public:
        DEQueue(int size);
        void Display();
        int isEmpty();
        int isFull();
        void EnqueueFront(int x);
        void EnqueueRear(int x);
        int DequeueFront();
        int DequeueRear();
};

DEQueue::DEQueue(int size){
    this->size = size;
    front = -1;
    rear = -1;
    Q = new int[size];
};

void DEQueue::Display(){
    for(int i=front+1;i<=rear;i++){
        cout << Q[i] << flush;
        if(i<rear){
            cout << "<-" << flush;
        }
    }
}

int DEQueue::isEmpty(){
    if(front == rear){
        return 1;
    }
    return 0;
}

int DEQueue::isFull(){
    if(rear == size-1){
        return 1;
    }
    return 0;
}

void DEQueue::EnqueueFront(int x){
    if(front == -1){
        cout << "Queue is Full";
    }else{
        Q[front] = x;
        front--;
    }
};

void DEQueue::EnqueueRear(int x){
    if(isFull()){
        cout << "Queue is Full";
    }else{
        rear++;
        Q[rear] = x;
    }
};

int DEQueue::DequeueFront(){
    int x = -1;
    if(isEmpty()){
        cout << "Queue is Empty" << endl;
    }else{
        x = Q[front];
        front++;
    }
    return x;
}

int DEQueue::DequeueRear(){
    int x=-1;
    if(rear == -1){
        cout << "Queue is Empty" << endl;
    }else{
        x = Q[rear];
        rear--;
    }
    return x;
}

int main(){
    int A[] = {1, 3, 5, 7, 9};
    int B[] = {2, 4, 6, 8};
 
    DEQueue deq(sizeof(A)/sizeof(A[0]));
 
    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
        deq.EnqueueRear(A[i]);
    }
    deq.Display();
    
    cout << endl;
    deq.EnqueueRear(11);
    cout << endl;
    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
        deq.DequeueFront();
    }
    deq.DequeueFront();

    cout << endl;
 
    for (int i=0; i<sizeof(B)/sizeof(B[0]); i++){
        deq.EnqueueFront(B[i]);
    }
    deq.Display();
    cout << endl;
    deq.EnqueueFront(10);
    deq.EnqueueFront(12);

    for (int i=0; i<sizeof(B)/sizeof(B[0]); i++){
        deq.DequeueRear();
    }
    cout << endl;
    deq.Display();
    cout << endl;
    deq.DequeueRear();
    deq.DequeueRear();
    return 0;
}