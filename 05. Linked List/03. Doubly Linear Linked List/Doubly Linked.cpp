#include <iostream>

using namespace std;

template<class T>
class Node
{
    public:
    Node *prev;
    T data;
    Node *next;
};

template<class T>
class DoublyLinked
{
private:
    Node<T> *first;
public:
    DoublyLinked(){first = NULL;}

    DoublyLinked(T A[], int n)
    {
        Node<T> *t, *last;
        first = new Node<T>;
        first->prev = NULL;
        first->data = A[0];
        first->next = NULL;
        last = first;

        for(int i=1; i<n; i++)
        {
            t = new Node<T>;
            t->data = A[i];
            t->next = last->next;
            t->prev = last;
            last->next = t;
            last = t;
        }
    }
    void Display()
    {
        Node<T> *p;
        p = first;
        while(p)
        {
            cout<<p->data<<" ";
            p = p->next;
        }
        cout<<endl;
    }
    int Length()
    {
        int len=0;
        Node<T> *p = first;
        while(p)
        {
            len++;
            p=p->next;
        }
        return len;
    }
    void Reverse()
    {
        Node<T> *p, *temp;
        p = first;
        while(p)
        {
            temp = p->next;
            p->next = p->prev;
            p->prev = temp;
            p = p->prev;
            if(p!=NULL&&p->next==NULL)
                first = p;
        }
    }
    void Insert(int pos, int x)
    {
        if(pos<0 && pos>Length())
            return;

        Node<T> *p, *t;
        t = new Node<T>;
        t->data = x;
        t->prev = NULL;
        t->next = NULL;
        if(pos==0)
        {
            if(first==NULL)
                first = t;
            else
            {
                t->next = first;
                first->prev = t;
                first = t;
            }
        }
        else
        {
            p = first;
            for(int i=0; i<pos-2; i++)
                p = p->next;
            t->next = p->next;
            t->prev = p;
            if(p->next)
                p->next->prev = t;
            p->next = t;
        }
    }
    int Delete(int pos)
    {
        if(pos<0 && pos>Length())
            return -1;
        Node<T> *p;
        int x;
        if(pos==0)
        {
            p = first;
            first = first->next;
            x = p->data;
            delete p;
            if(first)
                first->prev = NULL;
        }
        else
        {
            p=first;
            for(int i=0; i<pos-1; i++)
                p=p->next;
            p->prev->next = p->next;
            if(p->next)
                p->next->prev = p->prev;
            x = p->data;
            delete p;
        }
        return x;
    }
};
int main()
{
    int A[]={1,2,3,4,5};
    DoublyLinked<int>* l = new DoublyLinked<int>(A, 5);
    l->Display();
    //l->Reverse();
    //cout<<l->Length();
    l->Insert(0, 0);
    l->Insert(7, 6);
    l->Display();
    l->Delete(4);
    l->Display();
    l->Reverse();
    l->Display();
    return 0;
}
