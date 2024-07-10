#include<iostream>
using namespace std;

class Node{
    public:
        Node* lchild;
        int data;
        Node* rchild;
        int height;
};

class AVL{
    public:
        Node* root;
        AVL() {root = nullptr;}

        int NodeHeight(Node* p);
        int BalanceFactor(Node* p);
        Node* LLRotation(Node* p);
        Node* LRRotation(Node* p);
        Node* RRRotation(Node* p);
        Node* RLRotation(Node* p);

        //Inserting
        Node* rInsert(Node* p, int key);
        void Inorder(Node* p);
        void Inorder() {Inorder(root);}
        Node* getRoot() {return root;}
};

int AVL::NodeHeight(Node* p){
    int hl; 
    int hr;

    hl = (p && p->lchild) ? p->lchild->height : 0;
    hr = (p && p->rchild) ? p->rchild->height : 0;

    return hl > hr ? hl+1 : hr+1;
};

int AVL::BalanceFactor(Node* p){
    int hl;
    int hr;

    hl = (p && p->lchild) ? p->lchild->height : 0;
    hr = (p && p->rchild) ? p->rchild->height : 0;

    return hl-hr;
};

Node* AVL::LLRotation(Node* p){
    Node* pl = p->lchild;
    Node* plr = pl->rchild;

    pl->rchild = p;
    p->lchild = plr;

    // Updating height
    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);

    //Update root as well
    if(root == p){
        root = pl;
    }
    return pl;
}

Node* AVL::RRRotation(Node* p){
    Node* pr = p->rchild;
    Node* prl = pr->lchild;

    pr->rchild = p;
    p->rchild = prl;

    //Update the height
    pr->height = NodeHeight(pr);
    p->height = NodeHeight(p);

    //Update the root 
    if(root == p){
        root = pr;
    }
    return pr;
}

Node* AVL::LRRotation(Node *p) {
    return nullptr;
}
 
Node* AVL::RLRotation(Node *p) {
    return nullptr;
}
 

Node* AVL::rInsert(Node* p, int key){
    Node* t;
    if(p == nullptr){
        t = new Node;
        t->data = key;
        t->lchild = t->rchild = nullptr;
        t->height = 1;
        return t;
    }

    if(key < p->data){
        p->lchild = rInsert(p->lchild, key);
    }else if(key > p->data){
        p->rchild = rInsert(p->rchild, key);
    }

    p->height = NodeHeight(p);

    // Balance factor and Rotation
    if(BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 1){
        return LLRotation(p);
    }else if(BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == -1){
        return LRRotation(p);
    }else if(BalanceFactor(p) == -2 && BalanceFactor(p->lchild) == -1){
        return RRRotation(p);
    } else if(BalanceFactor(p) == -2 && BalanceFactor(p->lchild) == 1){
        return RLRotation(p);
    }

    return p;
}

void AVL::Inorder(Node* p){
    if(p!=nullptr){
        Inorder(p->lchild);
        cout << p->data << " " << flush;
        Inorder(p->rchild);
    }
}

int main(){
    AVL tree;
    tree.root = tree.rInsert(tree.root, 30);
    tree.root = tree.rInsert(tree.root, 20);
    tree.root = tree.rInsert(tree.root, 10);

    tree.Inorder();
    cout << endl;

    AVL treeRR;
    treeRR.root = tree.rInsert(treeRR.root, 10);
    treeRR.root = tree.rInsert(treeRR.root, 20);
    treeRR.root = tree.rInsert(treeRR.root, 30);
    treeRR.Inorder();
    cout << endl;

    return 0;
}   