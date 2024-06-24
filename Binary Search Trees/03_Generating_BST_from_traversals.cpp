#include<iostream>
#include<stack>
using namespace std;

class Node{
    public:
        Node* lchild;
        int data;
        Node* rchild;
};

class BST{
    private:
        Node* root;
    public:
        BST() {root = nullptr;}
        Node* getRoot() {return root;}
        void Insert(int key);
        void Inorder(Node* p);
        Node* Search(int key);
        Node* RecursiveInsert(Node* p, int key);
        Node* RecursiveSearch(Node* p, int key);
        int Height(Node* p);
        Node* InPredecessor(Node* p);
        Node* InSuccessor(Node* p);
        Node* Delete(Node* p, int key);
        void CreateFromPreorder(int pre[], int n);
};

void BST::Insert(int key){
    Node* t = root;
    Node* p;
    Node* r;

    if(root == nullptr){
        p = new Node;
        p->data = key;
        p->lchild = p->rchild = nullptr;
        root = p;
        return;
    }
    while(t!=nullptr){
        r = t;
        if(key < t->data){
            t = t->lchild;
        }else if(key > t->data){
            t = t->rchild;
        }else{
            return;
        }
    }
    p= new Node;
    p->data = key;
    p->lchild = p->rchild = nullptr;
    if(key < r->data){
        r->lchild = p;
    }else{
        r->rchild = p;
    }
};

void BST::Inorder(Node* p){
    if(p){
        Inorder(p->lchild);
        cout << p->data;
        Inorder(p->rchild);
    }
};

Node* BST::Search(int key){
    Node* t = root;
    while(t != nullptr){
        if(key == t->data){
            return t;
        } else if(key < t->data){
            t = t->lchild;
        }else{
            t = t->rchild;
        }
    }
    return nullptr;
};

Node* BST::RecursiveInsert(Node* p, int key){
    Node* t;
    if(p == nullptr){
        t = new Node;
        t->data = key;
        t->lchild = t->rchild = nullptr;
        return t;
    }
    if(key < p->data){
        p->lchild = RecursiveInsert(p->lchild, key);
    }else if(key > p->data){
        p->rchild = RecursiveInsert(p->rchild, key);
    }
    return p;
}

Node* BST::RecursiveSearch(Node* p, int key){
    if(p == nullptr){
        return nullptr;
    }
    if(key == p->data){
        return p;
    }else if(key < p->data){
        return RecursiveSearch(p->lchild, key);
    }else{
        return RecursiveSearch(p->rchild, key);
    }
    return nullptr;
};

int BST::Height(Node* p){
    int x, y;
    if(p == nullptr){
        return 0;
    }
    x = Height(p->lchild);
    y = Height(p->rchild);
    return x > y ? x+1 : y+1;
};

Node* BST::InPredecessor(Node* p){
    while(p && p->rchild != nullptr){
        p = p->rchild;
    }
    return p;
};

Node* BST::InSuccessor(Node* p){
    while(p && p->lchild != nullptr){
        p = p->lchild;
    }
    return p;
};


Node* BST::Delete(Node* p, int key){
    Node* q;
    if(p == nullptr){
        return nullptr;
    }
    if(p->lchild == nullptr && p->rchild == nullptr){
        if(p == root){
            root = nullptr;
        }
        delete p;
        return nullptr;
    }
    if(key < p->data){
        p->lchild = Delete(p->lchild, key);
    }else if(key > p->data){
        p->rchild = Delete(p->rchild, key);
    }else{
        if(Height(p->lchild) > Height(p->rchild)){
            q = InPredecessor(p->lchild);
            p->data = q->data;
            p->lchild = Delete(p->lchild, q->data);
        }else{
            q = InSuccessor(p->rchild);
            p->data = q->data;
            p->rchild = Delete(p->rchild, q->data);
        }
    }
    return p;
};

void BST::CreateFromPreorder(int* pre, int n){
    int i = 0;
    root = new Node;
    root->data = pre[0];
    i++;
    root->lchild = root->rchild = nullptr;

    Node* t;
    Node* p = root;
    stack<Node*> stk;

    while(i < n){
        if(pre[i] < p->data){
            t = new Node;
            t->data = pre[i];
            i++;
            t->lchild = t->rchild = nullptr;
            p->lchild = t;
            stk.push(t);
            p = t;
        }else{
            if(pre[i] > p->data && pre[i] < stk.empty() ? 32767 : stk.top()->data){
                t = new Node;
                t->data = pre[i];
                i++;
                t->lchild = t->rchild = nullptr;
                p->rchild = t;
                p = t;
            }else{
                p = stk.top();
                stk.pop();
            }
        }
    }
}


int main(){
    BST bst;

    bst.Insert(10);
    bst.Insert(5);
    bst.Insert(20);
    bst.Insert(8);
    bst.Insert(30);

    bst.Inorder(bst.getRoot());
    cout << endl;

    Node* temp = bst.Search(2);
    if(temp!=nullptr){
        cout << temp->data << endl;
    }else{
        cout << "Element Not Found" << endl;
    }

    temp = bst.RecursiveSearch(bst.getRoot(), 10);
    if(temp != nullptr){
        cout << temp->data << endl;
    }else{
        cout << "Element Not Found" << endl;   
    }

    bst.RecursiveInsert(bst.getRoot(), 50);
    bst.RecursiveInsert(bst.getRoot(), 70);
    bst.RecursiveInsert(bst.getRoot(), 1);
    bst.Inorder(bst.getRoot());
    cout << "\n" << endl;

    BST bs;
    bs.Insert(5);
    bs.Insert(2);
    bs.Insert(8);
    bs.Insert(7);
    bs.Insert(9);
    bs.Insert(1);
 
    temp = bs.InPredecessor(bs.getRoot());
    cout << "InPre: " << temp->data << endl;

    temp = bs.InSuccessor(bs.getRoot());
    cout << "InSucc: " << temp->data << endl;
 
    bs.Inorder(bs.getRoot());
    cout << endl;

    bs.Delete(bs.getRoot(), 7);
    bs.Inorder(bs.getRoot());

    cout << "BST from Preorder: " << flush;
    int pre[] = {30, 20, 10, 15, 25, 40, 50, 45};
    int n = sizeof(pre)/sizeof(pre[0]);
 
    BST b;
    b.CreateFromPreorder(pre, n);
    b.Inorder(b.getRoot());
    cout << endl;
    
    return 0;
}