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
        Tree(){root = nullptr;}
        void createTree();
        void Preorder(Node* p);
        void Preorder() {Preorder(root);}
        void Inorder(Node* p);
        void Inorder(){Inorder(root);}
        void Postorder(Node* p);
        void Postorder(){Postorder(root);}
        void IterativePreorder(Node* p);
        void IterativePreorder() {IterativePreorder(root);}
        void IterativeInorder(Node* p);
        void IterativeInorder() {Inorder(root);}
        void IterativePostorder(Node* p);
        void IterativePostorder(){IterativePostorder(root);}
        void LevelOrder(Node* p);
        void LevelOrder() {LevelOrder(root);}
};

void Tree::createTree(){
    Node* p;
    Node* t;
    int x;
    queue<Node*> q;

    root = new Node;

    cout << "Enter value of Root Node: " << endl;
    cin >> x;
    root->data = x;
    root->lchild = root->rchild = nullptr;
    q.emplace(root);

    while(!q.empty()){
        p = q.front();
        q.pop();

        cout << "Enter the value of Left Child of " << p->data << ": " << endl;
        cin >> x;
        if(x != -1){
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = nullptr;
            p->lchild = t;
            q.emplace(t);
        }

        cout << "Enter the value of Right Child of " << p->data << ": " << endl;
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

void Tree::Preorder(Node* p){
    if(p){
        cout << p->data << flush;
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
};

void Tree::Inorder(Node* p){
    if(p){
        Inorder(p->lchild);
        cout << p->data << flush;
        Inorder(p->rchild);
    }
};

void Tree::Postorder(Node* p){
    if(p){
        Postorder(p->lchild);
        Postorder(p->rchild);
        cout << p->data << flush;
    }
};

void Tree::IterativePreorder(Node* p){
    stack<Node*> stk;
    while(p != NULL || !stk.empty()){
        if(p != NULL){
            cout << p->data << flush;
            stk.emplace(p);
            p=p->lchild;
        }else{
            p = stk.top();
            stk.pop();
            p=p->rchild;
        }
    }
};

void Tree::IterativeInorder(Node* p){
    stack<Node*> stk;
    while(p != NULL || !stk.empty()){
        if(p != NULL){
            stk.emplace(p);
            p = p->lchild;
        }else{
            p = stk.top();
            stk.pop();
            cout << p->data;
            p = p->rchild;
        }
    }
};

void Tree::IterativePostorder(Node* p){
    stack<long int> stk;
    long int temp;

    while(p!= NULL || !stk.empty()){
        if(p!=NULL){
            stk.emplace((long int) p);
            p = p->lchild;
        }else{
            temp = stk.top();
            stk.pop();
            if(temp > 0){
                stk.emplace(-temp);
                p = ((Node*)temp)->rchild;
            }else{
                cout << ((Node*)(-1*temp))->data << flush;
                p=nullptr;
            }
        }
    }
};

void Tree::LevelOrder(Node* p){
    queue<Node*> q;
    cout << root->data << flush;
    q.emplace(root);

    while(!q.empty()){
        p = q.front();
        q.pop();

        if(p->lchild){
            cout << p->lchild->data << flush;
            q.emplace(p->lchild);
        }if(p->rchild){
            cout << p->rchild->data << flush;
            q.emplace(p->rchild);
        }
    }
}

int main(){
    Tree bt;
    bt.createTree();
    cout << "Preorder" << endl;
    bt.Preorder();
    cout << endl;

    cout << "Inorder" << endl;
    bt.Inorder();
    cout << endl;

    cout << "Postorder" << endl;
    bt.Postorder();
    cout << endl;
 
    cout << "Iterative Preorder" << endl;
    bt.IterativePreorder();
    cout << endl;

    cout << "Iterative Inorder" << endl;
    bt.IterativeInorder();
    cout << endl;

    cout << "Iterative Postorder" << endl;
    bt.IterativePostorder();
    cout << endl;

    cout << "Level order" << endl;
    bt.LevelOrder();
    cout << endl;
    return 0;
}