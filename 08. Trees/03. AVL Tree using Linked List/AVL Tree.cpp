#include <iostream>

using namespace std;


class Node
{
public:
    Node *lchild;
    int height;
    int data;
    Node *rchild;
};

class AVLTree
{
public:
    Node *root;
    AVLTree(){root = NULL;}

    Node* RInsert(Node *p, int key);
    int NodeHeight(Node *p);
    int BalanceFactor(Node *p);
    Node *LLRotation(Node *p);
    Node *LRRotation(Node *p);
    Node *RRRotation(Node *p);
    Node *RLRotation(Node *p);

    Node* Delete(Node* p, int key);
    int Height(Node *p);

    Node* InPre(Node *p);
    Node* InSucc(Node *p);

    void preOrder(Node *p);
    void inOrder(Node *p);
    void postOrder(Node *p);
};

int AVLTree::NodeHeight(Node *p)
{
    int hl, hr;
    hl = p&&p->lchild?p->lchild->height:0;
    hr = p&&p->rchild?p->rchild->height:0;
    return hl>hr?hl+1:hr+1;
}

int AVLTree::BalanceFactor(Node *p)
{
    int hl, hr;
    hl = p&&p->lchild?p->lchild->height:0;
    hr = p&&p->rchild?p->rchild->height:0;
    return hl-hr;

}

Node* AVLTree::LLRotation(Node *p)
{
    Node *pl = p->lchild;
    Node *plr = pl->rchild;

    pl->rchild = p;
    p->lchild = plr;

    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);

    cout<<"\nLL Rotation data: "<<pl->data;
    if(root == p)
        root = pl;
    return pl;
}

Node* AVLTree::LRRotation(Node *p)
{
    Node *pl = p->lchild;
    Node *plr = pl->rchild;

    pl->rchild = plr->lchild;
    p->lchild = plr->rchild;

    plr->lchild = pl;
    plr->rchild = p;

    pl->height = NodeHeight(pl);
    p->height = NodeHeight(p);
    plr->height = NodeHeight(plr);

    cout<<"\nLR Rotation data: "<<plr->data;
    if(root == p)
        root = plr;

    return plr;
}

Node* AVLTree::RRRotation(Node *p)
{
    Node *pl = p->rchild;
    Node *plr = pl->lchild;

    pl->lchild = p;
    p->rchild = plr;

    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);

    cout<<"\nRR Rotation data: "<<pl->data;
    if(root == p)
        root = pl;

    return pl;
}
Node* AVLTree::RLRotation(Node *p)
{
    Node *pl = p->rchild;
    Node *plr = pl->lchild;

    pl->lchild = plr->rchild;
    p->rchild = plr->lchild;

    plr->lchild = p;
    plr->rchild = pl;

    pl->height = NodeHeight(pl);
    p->height = NodeHeight(p);
    plr->height = NodeHeight(plr);

    cout<<"\nRL Rotation data: "<<plr->data;
    if(root == p)
        root = plr;

    return plr;
}
Node* AVLTree::RInsert(Node *p, int key)
{
    Node *t;
    if(p==NULL)
    {
        t = new Node;
        t->data = key;
        t->height = 1;
        t->lchild = t->rchild = NULL;
        return t;
    }

    if(key<p->data)
        p->lchild = RInsert(p->lchild, key);

    else if(key>p->data)
        p->rchild = RInsert(p->rchild, key);

    p->height = NodeHeight(p);

    if(BalanceFactor(p)==2 && BalanceFactor(p->lchild)==1)
        return LLRotation(p);

    else if(BalanceFactor(p)==2 && BalanceFactor(p->lchild)==-1)
        return LRRotation(p);

    else if(BalanceFactor(p)==-2 && BalanceFactor(p->rchild)==-1)
        return RRRotation(p);

    else if(BalanceFactor(p)==-2 && BalanceFactor(p->rchild)==1)
        return RLRotation(p);

    return p;
}

int AVLTree:: Height(Node *p)
{
    int x,y;
    if(p==NULL)return 0;
    x=Height(p->lchild);
    y=Height(p->rchild);
    return x>y?x+1:y+1;
}

Node* AVLTree::InPre(Node *p)
{
    while(p&&p->rchild!=NULL)
        p = p->rchild;
    return p;
}

Node* AVLTree::InSucc(Node *p)
{
    while(p&&p->lchild!=NULL)
        p = p->lchild;
    return p;
}

Node* AVLTree::Delete(Node* p, int key)
{
    Node *q;
    if(p==NULL)
        return NULL;
    if(p->lchild==NULL && p->rchild==NULL)
    {
        if(p==root)
            root = NULL;
        delete(p);
        return NULL;
    }

    if(key<p->data)
        p->lchild = Delete(p->lchild, key);

    else if(key>p->data)
        p->rchild = Delete(p->lchild, key);

    else
    {
        if(Height(p->lchild)>Height(p->rchild))
        {
            q=InPre(p->lchild);
            p->data=q->data;
            p->lchild=Delete(p->lchild,q->data);
        }
        else
        {
            q=InSucc(p->rchild);
            p->data=q->data;
            p->rchild=Delete(p->rchild,q->data);
        }
    }
    p->height = NodeHeight(p);

    if(BalanceFactor(p)==2 && BalanceFactor(p->lchild)==1)
        LLRotation(p);
    else if(BalanceFactor(p)==2 && BalanceFactor(p->lchild)==-1)
        LRRotation(p);
    else if(BalanceFactor(p)==2 && BalanceFactor(p->lchild)==0)
        LLRotation(p); //or LRRotation(p);

    else if(BalanceFactor(p)==-2 && BalanceFactor(p->lchild)==-1)
        RRRotation(p);
    else if(BalanceFactor(p)==-2 && BalanceFactor(p->lchild)==1)
        RLRotation(p);
    else if(BalanceFactor(p)==-2 && BalanceFactor(p->lchild)==0)
        RRRotation(p); //or RRRotation(p);

    return p;
}

void AVLTree :: preOrder(Node *p)
{
    if(p)
    {
        cout<<p->data<<" ";
        preOrder(p->lchild);
        preOrder(p->rchild);
    }
}

void AVLTree :: inOrder(Node *p)
{
    if(p)
    {
        inOrder(p->lchild);
        cout<<p->data<<" ";
        inOrder(p->rchild);
    }
}

void AVLTree :: postOrder(Node *p)
{
    if(p)
    {
        postOrder(p->lchild);
        postOrder(p->rchild);
        cout<<p->data<<" ";
    }
}

int main()
{
    AVLTree avl;
    avl.root = avl.RInsert(avl.root, 10);
    avl.RInsert(avl.root, 20);
    avl.RInsert(avl.root, 30);
    avl.RInsert(avl.root, 25);
    avl.RInsert(avl.root, 28);
    avl.RInsert(avl.root, 27);
    avl.RInsert(avl.root, 5);
    cout<<"\nFinal Root: "<<avl.root->data;
    cout<<"\nPreOrder: ";
    avl.preOrder(avl.root);
    cout<<"\nInOrder: ";
    avl.inOrder(avl.root);
    cout<<"\nPostOrder: ";
    avl.postOrder(avl.root);

    avl.Delete(avl.root, 25);
    cout<<"\n\nDeleted: 25";
    cout<<"\nFinal Root: "<<avl.root->data;
    cout<<"\nPreOrder: ";
    avl.preOrder(avl.root);
    cout<<"\nInOrder: ";
    avl.inOrder(avl.root);
    cout<<"\nPostOrder: ";
    avl.postOrder(avl.root);

    return 0;
}
