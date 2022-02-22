#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class CircularLinkedList
{
private:
    Node *Head;
public:
    CircularLinkedList(int A[], int n)
    {
        int i;
        Node *t, *last;
        Head = new Node;
        Head->data = A[0];
        Head->next = Head;
        last = Head;

        for(i=1; i<n; i++)
        {
            t = new Node;
            t->data = A[i];
            t->next = last->next;
            last->next = t;
            last = t;
        }
    }
    void Display()
    {
        Node *h = Head;
        do
        {
            cout<<h->data<<" ";
            h = h->next;
        }while(h!=Head);
        cout<<"\n";
    }

    int Length()
    {
        int len = 0;
        Node *p = Head;
        do
        {
            len++;
            p =p->next;
        }while(p!=Head);
        return len;
    }
    void Insert(int pos, int x)
    {
        if(pos<0||pos>Length())
            return;

        Node *t, *p;
        t = new Node;
        t->data = x;

        if(pos==0)
        {
            if(Head == NULL)
            {
                Head = t;
                Head->next = Head;
            }
            else
            {
                p = Head;
                while(p->next!=Head)
                    p=p->next;
                p->next = t->next;
                t->next = Head;
                Head = t;
            }
        }
        else
        {
            p=Head;
            for(int i=0; i<pos-1; i++)
                p =p->next;
            t->next = p->next;
            p->next = t;
        }
    }

    int Delete(int pos)
    {
        Node *p, *q;
        int x;
        if(pos==1)
        {
            p = Head;
            while(p->next!=Head)
                p = p->next;
            x = Head->data;
            if(p==Head)
            {
                delete Head;
                Head = NULL;
            }
            else
            {
                p->next = Head->next;
                delete Head;
                Head = p->next;
            }
        }
        else
        {
            p = Head;
            for(int i=0; i<pos-2; i++)
                p=p->next;
            q->next = p->next;
            x = q->data;
            delete q;
        }
        return x;
    }

};
int main()
{
    int A[] = {1,2,3,4,5};
    CircularLinkedList l(A, 5);
    l.Display();
    //l.Insert(0,0);
    //l.Display();
    l.Delete(1);
    l.Display();
    return 0;
}
