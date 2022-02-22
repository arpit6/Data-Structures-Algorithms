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
    LinkedList()
    {
        first=NULL;
    }
    LinkedList(int A[], int n)
    {
        Node *t, *last;
        first = new Node;
        first->data = A[0];
        first->next = NULL;
        last = first;
        for(int i=0; i<n; i++)
        {
            t = new Node;
            t->data = A[i];
            t->next = NULL;
            last->next = t;
            last = t;
        }
    }
    void InsertData(int x)
    {
        Node *t = new Node;
        t->data = x;
        t->next = NULL;
        if(first == NULL)
        {
            first = t;
        }
        else
        {
            Node *last = first;
            while(last->next!=NULL)
            {
                last = last->next;
            }
            last->next = t;
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

};
int main()
{
    int n;
    LinkedList l;
    cout<<"Enter number of elements: ";
    cin>>n;
    cout<<"\nEnterElements: \n";
    for(int i=0; i<n; i++)
    {
        int k;
        cin>>k;
        l.InsertData(k);
    }
    l.Display();
    return 0;
}
