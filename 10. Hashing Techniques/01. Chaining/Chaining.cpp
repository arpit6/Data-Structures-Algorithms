#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class Chaining
{
    Node **A;
public:
    Chaining()
    {
        A = new Node*[10];
        for(int i=0; i<10; i++)
            A[i] = NULL;
    }

    void Insert(int data){Insert(A, data);}
    void Insert(Node** A, int data);
    bool Search(int value);
    int Delete(int value);
    void Display();
};

void Chaining::Insert(Node** A, int data)
{
    Node *t = new Node;
    Node *k;
    Node *q = NULL;

    int modu = data%10;
    t->data = data;
    t->next = NULL;

    if(A[modu]==NULL)
        A[modu] = t;
    else
    {
        k = A[modu];
        while(k && k->data<data)
        {
            q = k;
            k = k->next;
        }
        if(k==A[modu])
        {
            t->next = A[modu];
            A[modu] = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
}

bool Chaining:: Search(int value)
{
    int modu = value%10;
    Node *k = A[modu];
    if(k==NULL)
        return false;
    else
    {
        while(k)
        {
            if(k->data == value)
                return true;
            k = k->next;
            if(k->data>value)
                return false;
        }
    }
    return false;
}

int Chaining::Delete(int value)
{
    int temp = -1;
    int modu = value%10;
    Node *k = A[modu];
    Node *q =NULL;

    if(k==NULL)
        return temp;
    else
    {
        q = k;
        while(k){
        if(k->data == value)
        {
            if(k==A[modu])
            {
                temp = A[modu]->data;
                A[modu] = A[modu]->next;
                delete(k);
                return temp;
            }
            else
            {
                q->next = k->next;
                temp = k->data;
                delete(k);
                return temp;
            }
        }
        else if(k->next!=NULL && k->data<value)
        {
            q = k;
            k = k->next;
        }
        else
            return temp;
        }
    }
    return temp;
}

void Chaining::Display()
{
    cout<<"Hash Table is: ";
    for(int i=0; i<10; i++)
    {
        Node *k = A[i];
        while(k)
        {
            cout<<k->data<<" ";
            k = k->next;
        }
    }
    cout<<endl;
}
int main()
{
    Chaining Hash;
    Hash.Insert(16);
    Hash.Insert(12);
    Hash.Insert(25);
    Hash.Insert(39);
    Hash.Insert(6);
    Hash.Insert(122);
    Hash.Insert(5);
    Hash.Insert(68);
    Hash.Insert(75);
    Hash.Display();
    if(Hash.Search(25))
        cout<<"25 is Successfully Searched"<<endl;

    cout<<"Deleted: "<<Hash.Delete(75)<<endl;

    Hash.Display();

    return 0;
}
