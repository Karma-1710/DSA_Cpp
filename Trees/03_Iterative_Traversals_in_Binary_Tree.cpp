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
        Tree() { root = nullptr;}
        void createTree();
        void IterativePreorder(Node *p);
        void IterativePreorder() {IterativePreorder(root);}
        void IterativeInorder(Node* p);
        void IterativeInorder() {IterativeInorder(root);}
        void IterativePostorder(Node* p);
        void IterativePostorder() {IterativePostorder(root);}
};

void Tree::createTree(){
    Node* p;
    Node* t;
    int x;
    queue<Node*> q;

    root = new Node;
    cout << "Enter the root node value: " << endl;
    cin >> x;
    root->data = x;
    root->lchild = root->rchild = nullptr;
    q.emplace(root);

    while(!q.empty()){
        p = q.front();
        q.pop();

        cout << "Enter the left child of " << p->data << ": " << endl;
        cin >> x;
        if(x != -1){
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = nullptr;
            p->lchild = t;
            q.emplace(t);
        }

        cout << "Enter the right child of " << p->data << ": " << endl;
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

void Tree::IterativePreorder(Node *p){
    stack<Node*> stk;
    while(p!=NULL || !stk.empty()){
        if(p != NULL){
            cout << p->data << flush;
            stk.emplace(p);
            p = p->lchild;
        }else{
            p = stk.top();
            stk.pop();
            p=p->rchild;
        }
    }
    cout << endl;
};

void Tree::IterativeInorder(Node* p){
    stack<Node*> stk;
    while(p!=NULL || !stk.empty()){
        if(p != NULL){
            stk.emplace(p);
            p=p->lchild;
        }else{
            p = stk.top();
            stk.pop();
            cout << p->data << flush;
            p=p->rchild;
        }
    }
};

void Tree::IterativePostorder(Node* p){
    stack<long int> stk;
    long int temp;
    while(p != nullptr || !stk.empty()){
        if(p != nullptr){
            stk.emplace((long int) p);
            p = p->lchild;
        }else{
            temp = stk.top();
            stk.pop();
            if(temp > 0){
                stk.emplace(-temp);
                p = ((Node*)temp)->rchild;
            }else{
                cout << ((Node*)(-1 * temp))->data << flush;
                p=nullptr;
            }
        }
    }

    cout << endl;
}

int main(){
    Tree bt;
    bt.createTree();
    cout << "Iterative Preorder: " << flush;
    bt.IterativePreorder();
 
    cout << "Iterative Inorder: " << flush;
    bt.IterativeInorder();
    cout << endl;

    cout << "Iterative Postorder: " << flush;
    bt.IterativePostorder();
    return 0;
};