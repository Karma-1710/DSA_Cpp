#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
};

class Queue{
    public:
        Node *front, *rear;
        Queue(){
            front = nullptr;
            rear = nullptr;
        };
        void enqueue(int x){
            Node *t = new Node;
            t->data = x;
            t->next = NULL;
            if(front == NULL){
                front = rear = t;
            }else{
                rear->next = t;
                rear = t;
            }
        };
        int dequeue(){
            Node* p;
            int x =-1;
            if(front == rear){
                cout << "Queue is empty" << endl;
            }else{
                p=front;
                front = front->next;
                x = p->data;
                delete p;
            }
            return x;
        };

        void display(){
            Node* p = front;
            while(p){
                cout << p->data << " " << flush;
                p=p->next;
            }
        };
        bool isEmpty(){
            if(front == nullptr){
                return true;
            }
            return false;
        }
}que1, que2, que3;

struct PriorityQueueNode{
    int data;
    int priority;
};

void popPriority(){
    if(!que1.isEmpty()){
        que1.dequeue();
    }else if(!que2.isEmpty()){
        que2.dequeue();
    }else{
        que3.dequeue();
    }
}

void DisplayPriority(){
    if(!que1.isEmpty()){
        que1.display();
    }else if(!que2.isEmpty()){
        que2.display();
    }else{
        que3.display();
    }
}

int main(){
    PriorityQueueNode Ar[8];
    for (int i = 0; i < 8; ++i){
		Ar[i].data = 10 *(i+1);
	} 

    Ar[0].priority = 1;
	Ar[1].priority = 1;
	Ar[2].priority = 2;
	Ar[3].priority = 3;
	Ar[4].priority = 2;
	Ar[5].priority = 1;
	Ar[6].priority = 2;
	Ar[7].priority = 3;

    for (int i = 0; i < 8; i++)
	{
		if (Ar[i].priority == 1)
			que1.enqueue(Ar[i].data);
 
		else if (Ar[i].priority == 2)
			que2.enqueue(Ar[i].data);
		
			else
				que3.enqueue(Ar[i].data);
	}
	
	DisplayPriority();
    popPriority();
	popPriority();
	popPriority();
	popPriority();
	popPriority();
	DisplayPriority();
    return 0;
}