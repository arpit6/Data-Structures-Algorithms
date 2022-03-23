#include <iostream>

using namespace std;

template <class T>
class Node
{
public:
    T data;
    Node *next;
};

template <class T>
class PriorityQueue
{
private:
    int size, priorities;
    Node<T>** A;
public:
    PriorityQueue(int size, int priorities)
    {
        this->size = size;
        this->priorities = priorities;
        A = new Node<T>*[this->priorities];
        for(int i=0; i<priorities; i++)
            A[i] = NULL;
    }
    void Enqueue(T x, int priority);
    T Dequeue();
    void Display();
};

template <class T>
void PriorityQueue<T>::Enqueue(T x, int priority)
{
    //Node<T> *p = A[priority-1];
    Node<T> *t = new Node<T>;
    if(t==NULL)
        cout<<"Queue is Full"<<endl;
    else
    {
        t->data = x;
        t->next = NULL;
        if(A[priority-1]==NULL)
            A[priority-1]=t;
        else
        {
            Node<T> *p = A[priority-1];
            while(p->next!=NULL)
            {
                p = p->next;
            }
            p->next = t;
        }
    }
}

template <class T>
T PriorityQueue<T>::Dequeue()
{
    T x = -1;
    Node<T> *p;
    for(int i=0; i<priorities; i++)
    {
        p = A[i];
        if(p==NULL)
            continue;
        else
        {
            x = p->data;
            A[i] = A[i]->next;
            break;
        }
    }
    return x;

}

template <class T>
void PriorityQueue<T>::Display()
{
    for(int i=0; i<priorities; i++)
    {
        Node<T> *p = A[i];
        cout<<"Queue->"<<i+1<<" is: ";
        if(p==NULL)
            cout<<"Empty";
        else
        {
            while(p)
            {
                cout<<p->data<<" ";
                p=p->next;
            }
        }
        cout<<endl;

    }
}
int main()
{
    PriorityQueue<char> *P = new PriorityQueue<char>(12, 3);
    P->Enqueue('A', 1);
    P->Enqueue('B', 1);
    P->Enqueue('C', 2);
    P->Enqueue('D', 3);
    P->Enqueue('E', 2);
    P->Enqueue('F', 1);
    P->Enqueue('G', 2);
    P->Enqueue('H', 3);
    P->Enqueue('I', 2);
    P->Enqueue('J', 2);
    P->Enqueue('K', 1);
    P->Enqueue('L', 1);
    P->Display();
    cout<<P->Dequeue()<<endl;
    cout<<P->Dequeue()<<endl;
    cout<<P->Dequeue()<<endl;
    P->Display();
    return 0;
}
