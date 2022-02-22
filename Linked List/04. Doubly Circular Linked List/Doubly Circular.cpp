#include <iostream>

using namespace std;

class Node
{
public:
    Node *prev;
    int data;
    Node *next;
};
class CircularDoubly
{
private:
    Node *head;
public:
    CircularDoubly(){head=NULL;}

    CircularDoubly(int A[], int n)
    {
        head = new Node;
        Node *t, *last;
        head->data = A[0];
        head->prev = head;
        head->next = head;
        last = head;

        for(int i=1; i<n; i++)
        {
            t = new Node;
            t->data = A[i];
            t->next = last->next;
            t->prev = last;
            last->next = t;
            head->prev = t;
            last = t;
        }
    }
    void Display()
    {
        Node *h = head;
        if(head==NULL)
            return;
        do
        {
            cout<<h->data<<" ";
            h = h->next;
        }while(h!=head);
        cout<<endl;
    }
    int Length()
    {
        int len=0;
        Node *h = head;
        if(head==NULL)
            return len;
        do
        {
            len++;
            h = h->next;
        }while(h!=head);
        return len;
    }
    void Insert(int pos, int x)
    {
        if(pos<0 || pos>Length())
            return;

        Node *t, *p;
        t = new Node;
        t->data = x;
        if(pos==0)
        {
            if(head==NULL)
            {
                head = t;
                head->next = head;
                head->prev = head;
            }
            else
            {
                p = head;
                while(p->next!=head)
                    p = p->next;
                p->next = t;
                t->next = head;
                t->prev = p;
                head->prev = t;
                head = t;
            }
        }
        else
        {
            p = head;
            for(int i=0;i<pos-1; i++)
                p = p->next;
            t->prev = p;
            t->next = p->next;
            p->next->prev = t;
            p->next = t;
        }
    }
    int Delete(int pos)
    {
        if(pos<0 || pos>Length())
            return -1;

        int x;
        Node *h, *q=NULL;
        if(pos==0)
        {
            h = head;
            x = head->data;
            if(head->prev == head)
            {
                delete head;
                head = NULL;
            }
            else
            {
                head->next->prev = head->prev;
                head->prev->next = head->next;
                head = head->next;
                delete h;

            }
        }
        else
        {
            h = head;
            for(int i=0; i<pos-1; i++)
                h = h->next;
            q = h->next;
            h->next = q->next;
            q->next->prev = h;
            x = q->data;
            delete q;
        }
        return x;
    }
};
int main()
{
    int A[] = {1,2,3,5,6};
    CircularDoubly l(A, 5);
    l.Display();
    l.Insert(0,0);
    l.Insert(5, 4);
    l.Display();
    l.Delete(0);
    l.Delete(4);
    l.Display();
    return 0;
}
