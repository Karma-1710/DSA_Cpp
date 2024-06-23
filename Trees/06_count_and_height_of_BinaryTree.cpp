#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class Node{
    public:
        Node* lchild;
        int data;
        Node* rchild;
};

class Tree{
    private:
        Node* root;
    public:
        Tree() {root = nullptr;}
        void CreateTree();
        int Count(Node* p);
        int Count(){ return Count(root); }
        int Height(Node* p);
        int Height() { return Height(root);}
};

void Tree::CreateTree(){
    Node* p;
    Node* t;
    int x;
    queue<Node*> q;

    root = new Node;
    cout << "Enter the data inside root node: " << endl;
    cin >> x;
    root->data = x;
    root->lchild = root->rchild = nullptr;
    q.emplace(root);

    while(!q.empty()){
        p = q.front();
        q.pop();

        cout << "Enter the data inside left child of " << p->data << endl;
        cin >> x;
        if(x!=-1){
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = nullptr;
            p->lchild = t;
            q.emplace(t);
        }

        cout << "Enter the data inside right child of " << p->data << endl;
        cin >> x;
        if(x != -1){
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = nullptr;
            p->rchild = t;
            q.emplace(t);
        }
    }
};

int Tree::Count(Node* p){
    int x, y;
    if(p!=nullptr){
        x = Count(p->lchild);
        y = Count(p->rchild);
        return x+y+1;
    }
    return 0;
};

int Tree::Height(Node* p){
    int x=0, y=0;
    if(p!=nullptr){
        x = Height(p->lchild);
        y = Height(p->rchild);
        if(x>y){
            return x+1;
        }else{
            return y+1;
        }
    }
    return 0;
}

int main(){
    Tree bt;
    bt.CreateTree();
    cout << endl;
    cout << bt.Count() << endl;
    cout << bt.Height() << endl;
    return 0;
}