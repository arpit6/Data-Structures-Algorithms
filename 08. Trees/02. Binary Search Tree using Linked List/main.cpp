#include <iostream>
#include "QueueCpp.h"
#include "StackCpp.h"

using namespace std;
class BTree
{
public:
    Node *root;
    BTree(){root=NULL;}
    void Insert(int key);
    void Inorder(Node *p);
    void Levelorder(Node *root);
    Node* RInsert(Node *p, int key);
    Node * Delete(Node *p, int key);
    Node* InSucc(Node *p);
    Node* InPre(Node *p);
    int Height(Node *p);
    void CreatePre(int A[], int n);
};

void BTree::Insert(int key)
{
    Node *r = NULL, *p;
    Node *t = root;
    if(root==NULL)
    {
        p= new Node;
        p->data=key;
        p->lchild=p->rchild=NULL;
        root=p;
        return;
    }
    while(t!=NULL)
    {
        r = t;
        if(key==t->data)
            return;
        else if(key<t->data)
            t = t->lchild;
        else
            t = t->rchild;
    }
    p = new Node;
    p->data = key;
    p->lchild=p->rchild = NULL;
    if (p->data<r->data) r->lchild = p;
    else r->rchild = p;
}

Node* BTree::RInsert(Node *p, int key)
{
    Node *t;
    if(p==NULL)
    {
        t = new Node;
        t->data = key;
        t->lchild = t->rchild = NULL;
        return t;
    }

    if(key<p->data)
        p->lchild = RInsert(p->lchild, key);

    else if(key>p->data)
        p->rchild = RInsert(p->rchild, key);
    return p;
}
void BTree::Inorder(Node *p)
{
    if(p)
    {
        Inorder(p->lchild);
        cout<<p->data<<" ";
        Inorder(p->rchild);
    }
}

void BTree::Levelorder(Node *root)
{
    Queue q(100);
    cout<<root->data<<" ";
    q.Enqueue(root);

    while(!q.isEmpty())
    {
        root = q.Dequeue();
        if(root->lchild)
        {
            cout<<root->lchild->data<<" ";
            q.Enqueue(root->lchild);
        }
        if(root->rchild)
        {
            cout<<root->rchild->data<<" ";
            q.Enqueue(root->rchild);
        }
    }
}

int BTree:: Height(Node *p)
{
    int x,y;
    if(p==NULL)return 0;
    x=Height(p->lchild);
    y=Height(p->rchild);
    return x>y?x+1:y+1;
}

Node* BTree::InPre(Node *p)
{
    while(p&&p->rchild!=NULL)
        p = p->rchild;
    return p;
}

Node* BTree::InSucc(Node *p)
{
    while(p&&p->lchild!=NULL)
        p = p->lchild;
    return p;
}
Node* BTree:: Delete(Node *p, int key)
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
    if(key < p->data)
        p->lchild=Delete(p->lchild,key);

    else if(key > p->data)
        p->rchild=Delete(p->rchild,key);

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
    return p;
}

//Binary Tree using PreOrder
void BTree::CreatePre(int pre[], int n)
{
    int i = 0;
    root = new Node;
    root->data = pre[i];
    i++;
    root->lchild = root->rchild = NULL;

    Node *t;
    Node *p = root;
    Stack stk;
    while(i<n)
    {
        if(pre[i] < p->data)
        {
            t = new Node;
            t->data = pre[i];
            i++;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            stk.Push(p);
            cout<<"Pushed: "<<p->data<<endl;
            p = t;
        }
        else
        {
            if(pre[i]>p->data && pre[i]<(stk.Stacktop())->data)
            {
                t = new Node;
                t->data = pre[i++];
                t->lchild = t->rchild = NULL;
                p->rchild = t;
                p = t;
            }
            else
            {
                p = stk.Pop();

                cout<<"Poped: "<<p->data<<endl;
            }
        }
    }
}
int main()
{
    BTree p;
    p.root = p.RInsert(p.root,30);
    p.RInsert(p.root,15);
    p.RInsert(p.root,10);
    p.RInsert(p.root,20);
    p.RInsert(p.root,50);
    p.RInsert(p.root,40);
    p.RInsert(p.root,60);
    cout<<"\nInOrder: ";
    p.Inorder(p.root);
    cout<<"\nLevelOrder: ";
    p.Levelorder(p.root);
    p.Delete(p.root, 30);
    cout<<"\nLevelOrder: ";
    p.Levelorder(p.root);

    cout<<"\n\nBinary Tree using Preorder\n";
    BTree pr;

    int pre[] = {30, 20, 10, 15, 25, 40, 50, 45};
    int n = sizeof(pre)/sizeof(pre[0]);
    pr.CreatePre(pre, n);
    cout<<"\nInOrder: ";
    pr.Inorder(pr.root);

    return 0;
}
