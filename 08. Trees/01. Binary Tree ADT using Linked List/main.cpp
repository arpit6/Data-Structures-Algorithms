#include <iostream>
#include "QueueCpp.h"
using namespace std;

class Tree
{
public:
    Node *root;
    Tree(){root =NULL;};

    void CreateTree();
    void Preorder(Node *p);
    void Postorder(Node *p);
    void Inorder(Node *p);
    void Levelorder(Node *p);
    int Height(Node *root);
    void Levelorder2(Node *root);
};

void Tree::CreateTree()
{
    Node *p, *t;
    int x;
    Queue q(100);

    cout<<"Enter root value ";
    cin>>x;
    root = new Node;
    root->data = x;
    root->lchild = root->rchild = NULL;
    q.Enqueue(root);

    while(!q.isEmpty())
    {
        p = q.Dequeue();
        cout<<"Enter left child of "<<p->data<<" ";
        cin>>x;
        if(x!=-1)
        {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            q.Enqueue(t);
        }
        cout<<"Enter right child of "<<p->data<<" ";
        cin>>x;
        if(x!=-1)
        {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            q.Enqueue(t);
        }
    }
}

void Tree::Preorder(Node *p)
{
    if(p)
    {
        cout<<p->data<<" ";
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}

void Tree::Inorder(Node *p)
{
    if(p)
    {
        Inorder(p->lchild);
        cout<<p->data<<" ";
        Inorder(p->rchild);
    }
}
void Tree::Postorder(Node *p)
{
    if(p)
    {
        Postorder(p->lchild);
        Postorder(p->rchild);
        cout<<p->data<<" ";
    }
}

void Tree::Levelorder(Node *root)
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

void Tree::Levelorder2(Node *root)
{
    Queue q(100);
    cout<<"   ";
    cout<<root->data<<endl;
    q.Enqueue(root);

    while(!q.isEmpty())
    {
        root = q.Dequeue();
        if(root->lchild)
        {
            cout<<"  /  \\\ "<<endl;
            cout<<" /    \\\ "<<endl;
            cout<<root->lchild->data<<"     ";
            q.Enqueue(root->lchild);
        }
        if(root->rchild)
        {
            cout<<root->rchild->data<<" ";
            q.Enqueue(root->rchild);
        }
    }
}

int Tree::Height(Node *root)
{
    int x=0, y=0;
    if(root==0)
        return 0;
    x = Height(root->lchild);
    y = Height(root->rchild);
    if(x>y)
        return x+1;
    else
        return y+1;
}
int main()
{
    Tree t;
    t.CreateTree();
    cout<<"\nPreOrder: ";
    t.Preorder(t.root);
    cout<<"\nInOrder: ";
    t.Inorder(t.root);
    cout<<"\nLevelOrder: ";
    t.Levelorder(t.root);
    cout<<endl;
    t.Levelorder2(t.root);
    return 0;
}
