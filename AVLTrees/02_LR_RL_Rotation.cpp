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
        AVL(){root = nullptr;}

        int NodeHeight(Node* p);
        int BalanceFactor(Node* p);
        Node* LRRotation(Node* p);
        Node* RLRotation(Node* p);
        Node* rInsert(Node* p,int key);

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
}

int AVL::BalanceFactor(Node* p){
    int hl;
    int hr;

    hl = (p && p->lchild) ? p->lchild->height : 0;
    hr = (p && p->rchild) ? p->rchild->height : 0;

    return hl-hr;
}

Node* AVL::LRRotation(Node* p){
    Node* pl = p->lchild; // Meaning B
    Node* plr = pl->rchild; // Meaning C

    pl->rchild = plr->lchild;
    p->lchild = plr->rchild;

    plr->lchild = pl;
    plr->rchild = p;

    // Update height
    pl->height = NodeHeight(pl);
    p->height = NodeHeight(p);
    plr->height = NodeHeight(plr);

    //Update the root
    if(p == root){
        root = plr;
    }
    return plr;
}

Node* AVL::RLRotation(Node* p){
    Node* pr = p->rchild;
    Node* prl = pr->lchild;

    pr->lchild = prl->rchild;
    p->rchild = prl->lchild;

    prl->lchild = p;
    prl->rchild = pr;

    // Update the height
    prl->height = NodeHeight(prl);
    pr->height = NodeHeight(pr);
    p->height = NodeHeight(p);

    if(root == p){
        root = prl;
    }
    return prl;
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

    if(BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == -1){
        return LRRotation(p);
    }else if(BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == 1){
        return RLRotation(p);
    }

    return p;
}

void AVL::Inorder(Node* p){
    if(p){
        Inorder(p->lchild);
        cout << p->data << " " << flush;
        Inorder(p->rchild);
    }
}

int main(){
    AVL TreeLR;
    TreeLR.root = TreeLR.rInsert(TreeLR.root, 50);
    TreeLR.root = TreeLR.rInsert(TreeLR.root, 10);
    TreeLR.root = TreeLR.rInsert(TreeLR.root, 20);
    TreeLR.Inorder();
    cout << endl;
    cout << TreeLR.root->data << endl;

    AVL trl;
    trl.root = trl.rInsert(trl.root, 20);
    trl.root = trl.rInsert(trl.root, 50);
    trl.root = trl.rInsert(trl.root, 30);
 
 
    trl.Inorder();
    cout << endl;
    cout << trl.root->data << endl;
    return 0;
}