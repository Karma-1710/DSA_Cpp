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
        void Display();
        void enqueue(int x);
        int dequeue();
};

Queue::Queue(int size){
    this->size = size;
    front = 0;
    rear = 0;
    Q = new int[size];
};

int Queue::isFull(){
    if((rear + 1)%size == front){
        return 1;
    }
    return 0;
};

int Queue::isEmpty(){
    if(front == rear){
        return 1;
    }
    return 0;
}

void Queue::enqueue(int x){
    if(isFull()){
        cout << "Queue is Full" << endl;
    }else{
        rear = (rear + 1)%size;
        Q[rear] = x;
    };
};

int Queue::dequeue(){
    int x = -1;
    if(isEmpty()){
        cout << "Queue is Empty" << endl;
    }else{
        front = (front + 1)%size;
        x = Q[front];
    }
    return x;
}

void Queue::Display(){
    int i = front + 1;
    do{
        cout << Q[i] << flush;
        if(i<rear){
            cout << "<-" << flush;
        }
        i = (i+1)%size;
    }while(i != (rear + 1)%size);
}

int main(){
    int A[] = {1,3,5,7,9};
    int size = sizeof(A)/sizeof(A[0]);

    Queue cq(size + 1);
    for(int i=0; i<size;i++){
        cq.enqueue(A[i]);
    }
    cq.Display();   
    cout << endl;
    // cq.enqueue(10);
    for (int i=0; i<size; i++){
        cq.dequeue();
    }
 
    cq.dequeue();
    return 0;
}