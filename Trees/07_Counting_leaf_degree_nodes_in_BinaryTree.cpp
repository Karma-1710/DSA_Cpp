#include<iostream>
#include<queue>
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
        int CountLeafNodes(Node* p);
        int CountLeafNodes() {return CountLeafNodes(root);}
        int CountNodesWithDegree2(Node* p);
        int CountNodesWithDegree2() {return CountNodesWithDegree2(root);}
        int CountNodesWithDegree1or2(Node* p);
        int CountNodesWithDegree1or2() {return CountNodesWithDegree1or2(root);}
        int CountNodesWithDegree1(Node* p);
        int CountNodesWithDegree1() {return CountNodesWithDegree1(root);}
};

void Tree::CreateTree(){
    Node* p;
    Node* t;
    int x;
    queue<Node*> q;

    root = new Node;
    cout << "Enter the value of Root Node: " << endl;
    cin >> x;
    root->data = x;
    root->lchild = root->rchild = nullptr;
    q.emplace(root);
    while(!q.empty()){
        p = q.front();
        q.pop();
        cout << "Enter the value of Left child of " << p->data << endl;
        cin >> x;
        if(x != -1){
            t= new Node;
            t->data = x;
            t->lchild = t->rchild = nullptr;
            p->lchild = t;
            q.emplace(t);
        }

        cout << "Enter the value of Right child of " << p->data << endl;
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

int Tree::CountLeafNodes(Node* p){
    int x=0, y=0;
    if(p!=NULL){
        x = CountLeafNodes(p->lchild);
        y = CountLeafNodes(p->rchild);
        if(p->lchild == nullptr && p->rchild == nullptr){
            return x+y+1;
        }else{
            return x+y;
        }
    }
    return 0;
};

int Tree::CountNodesWithDegree2(Node* p){
    int x=0, y=0;
    if(p!=NULL){
        x= CountNodesWithDegree2(p->lchild);
        y= CountNodesWithDegree2(p->rchild);
        if(p->lchild!=NULL && p->rchild!=NULL){
            return x+y+1;
        }else{
            return x+y;
        }
    }
    return 0;
};

int Tree::CountNodesWithDegree1or2(Node* p){
    int x=0, y=0;
    if(p!=NULL){
        x= CountNodesWithDegree1or2(p->lchild);
        y= CountNodesWithDegree1or2(p->rchild);
        if(p->lchild !=NULL || p->rchild != NULL){
            return x+y+1;
        }else{
            return x+y;
        }
    }
    return 0;
};

int Tree::CountNodesWithDegree1(Node* p){
    int x=0, y=0;
    if(p!=NULL){
        x = CountNodesWithDegree1(p->lchild);
        y = CountNodesWithDegree1(p->rchild);
        if(p->lchild != NULL ^ p->rchild != NULL){
            return x+y+1;
        }else{
            return x+y;
        }
    }
    return 0;
}

int main(){
    Tree bt;
    bt.CreateTree();
    cout << endl;
    cout << bt.CountLeafNodes() << endl;
    cout << bt.CountNodesWithDegree2() << endl;
    cout << bt.CountNodesWithDegree1or2() << endl;
    cout << bt.CountNodesWithDegree1() << endl;
    return 0;
}