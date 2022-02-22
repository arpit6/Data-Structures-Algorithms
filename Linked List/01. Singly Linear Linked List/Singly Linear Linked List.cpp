#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class LinkedList
{
private:
    Node *first;

public:
    LinkedList(){first=0;}

    LinkedList(int A[], int n)
    {
        Node *last, *t;
        int i=0;

        first = new Node;
        first->data = A[0];
        first->next = NULL;
        last = first;

        for(i=1; i<n;i++)
        {
            t = new Node;
            t->data = A[i];
            t->next = NULL;
            last->next = t;
            last = t;
        }
    }

    void Display()
    {
        Node *p = first;
        while(p)
        {
            cout<<p->data<<" ";
            p = p->next;
        }
        cout<<endl;
    }

    int Length()
    {
        Node *p = first;
        int len=0;
        while(p)
        {
            len++;
            p = p->next;
        }
        return len;
    }
    int Sum()
    {
        Node *p = first;
        int sum=0;
        while(p)
        {
            sum = sum + p->data;
            p = p->next;
        }
        return sum;
    }
    int Max()
    {
        Node *p = first;
        int maxi = -32768;
        while(p)
        {
            if(maxi < p->data)
                maxi = p->data;
            p = p->next;
        }
        return maxi;
    }

    Node * LSearch(int key)
    {
        Node *p = first;
        while(p)
        {
            if(key == p->data)
                return p;
            p = p->next;
        }
        return 0;
    }
    Node * LSearchImp(int key)
    {
        Node *p = first, *q=first;
        while(p)
        {
            if(key == p->data)
            {
                q->next = p->next;
                p->next = first;
                first = p;
                return p;
            }
            q=p;
            p=p->next;
        }
        return 0;
    }
    void Insert(int index, int x)
    {
        Node *t,*p = first;
        if(index<0 || index>Length())
            return;
        t = new Node;
        t->data = x;
        t->next = NULL;

        if(index==0)
        {
            t->next = first;
            first = t;
        }
        else
        {
            for(int i=0; i<index-1; i++)
                p = p->next;
            t->next = p->next;
            p->next = t;
        }
    }
    void SortedInsert(int x)
    {
        Node *t = new Node;
        Node *p = first;
        Node *q = NULL;
        t->data = x;
        t->next = NULL;

        if(first == NULL)
        {
            first = t;
        }
        else
        {
            while(p && t->data > p->data )
            {
                q = p;
                p = p->next;
            }
            if(p==first)
            {
                t->next = first;
                first = t;
            }
            else
            {
                t->next = q->next;
                q->next = t;
            }
        }
    }

    int Delete(int pos)
    {
        Node *p, *q;
        int x = -1, i;
        if(pos==1)
        {
            x = first->data;
            p = first;
            first = first->next;
            delete p;
        }
        else
        {
            p = first;
            q = NULL;
            for(i=0; i<pos-1 && p; i++)
            {
                q = p;
                p = p->next;
            }
            if(p)
            {
                q->next = p->next;
                x = p->data;
                delete p;
            }
        }
        return x;
    }
    void SortedOrNot()
    {
        Node *p = first, *q=NULL;
        int k=0;
        for(int i=0; i<Length()-2 ; i++)
        {
            q = p;
            p = p->next;
            if(q->data > p->data)
            {
                k++;
                break;
            }
        }
        if(k==0)
            cout<<"Sorted Linked List"<<endl;
        else
        cout<<"Not Sorted Linked List"<<endl;
    }

    void SortedOrNot2() //Method 2
    {
        Node *p = first;
        int x = -23768;
        int k=0;
        while(p)
        {
            if(p->data<x)
            {
                k++;
                break;
            }
            x = p->data;
            p = p->next;
        }
        if(k==0)
            cout<<"Sorted Linked List"<<endl;
        else
            cout<<"Not Sorted Linked List"<<endl;
    }
    void RemoveDuplicates()
    {
        Node *p = first, *q=first->next;
        while(q)
        {
            if(p->data!=q->data)
            {
                p = q;
                q = q->next;
            }
            else
            {
                p->next = q->next;
                delete q;
                q = p->next;
            }
        }
    }

    void Reverse()
    {
        Node *p=first;
        Node *q = NULL, *r=NULL;
        while(p)
        {
            r = q;
            q = p;
            p = p->next;
            q->next = r;
        }
        first = q;
    }
    int isLoop()
    {
        Node *p, *q;
        p = q = first;
        do
        {
            p = p->next;
            q = q->next;
            q = q!=NULL ? q->next : NULL;
        }while(p&&q);
        return p==q?true:false;
    }
};

int main()
{
    Node *temp;
    int A[] = {8,2,3,4,6};
    LinkedList l(A,5);
/*    l.Display();
    cout<<l.Length()<<endl;
    cout<<l.Sum()<<endl;
    cout<<l.Max()<<endl;
    if(l.LSearch(3))
    {
        cout<<"Key Found "<<endl;
    }
    else
    {
        cout<<"Not Found"<<endl;
    }

    if(l.LSearchImp(4))
    {
        cout<<"Key Found"<<endl;
    }
    else
    {
        cout<<"Not Found"<<endl;
    }
    l.Display();*/
    l.Insert(0,0);
    l.SortedInsert(5);
    l.Display();
    cout<<"Deleted Value: "<<l.Delete(8)<<endl;
    l.Display();
    l.SortedOrNot();
    l.SortedOrNot2();

    int B[] = {5,5,8,8,8};
    LinkedList l2(B,5);
    l2.Display();
    l2.RemoveDuplicates();
    l2.Display();

    l.Reverse();
    l.Display();
    cout<<l.isLoop();
    return 0;
}
