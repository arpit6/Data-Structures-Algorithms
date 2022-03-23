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
class Queue
{
    Node<T> *front, *rear;
public:
    Queue(){front=rear=NULL;}

    void Enqueue(T x);
    T Dequeue();
    void Display();
};

template <class T>
void Queue<T>::Enqueue(T x)
{
    Node<T> *t = new Node<T>;
    if(t==NULL)
        cout<<"Queue is full"<<endl;
    else
    {
        t->data = x;
        t->next = NULL;
        if(front==NULL)
            front = rear = t;
        else
        {
            rear->next = t;
            rear = t;
        }
    }
}

template <class T>
T Queue<T>::Dequeue()
{
    T x = -1;
    Node<T> *p;
    if(front==NULL)
        cout<<"Queue is Empty"<<endl;
    else
    {
        p = front;
        front = front->next;
        x = p->data;
    }
    delete(p);
    return x;
}

template <class T>
void Queue<T>::Display()
{
    Node<T> *p;
    if(front==NULL)
        cout<<"Queue is Empty"<<endl;
    else
    {
        p = front;
        cout<<"Queue is: ";
        while(p)
        {
            cout<<p->data<<" ";
            p = p->next;
        }
        cout<<endl;
    }
}
int main()
{
    Queue<int> *Q = new Queue<int>();
    Q->Enqueue(1);
    Q->Enqueue(2);
    Q->Enqueue(3);
    Q->Enqueue(4);
    Q->Enqueue(5);
    Q->Enqueue(6);
    Q->Display();
    cout<<"Deleted Element: "<<Q->Dequeue()<<endl;
    cout<<"Deleted Element: "<<Q->Dequeue()<<endl;
    cout<<"Deleted Element: "<<Q->Dequeue()<<endl;
    cout<<"Deleted Element: "<<Q->Dequeue()<<endl;
    cout<<"Deleted Element: "<<Q->Dequeue()<<endl;
    cout<<"Deleted Element: "<<Q->Dequeue()<<endl;
    cout<<"Deleted Element: "<<Q->Dequeue()<<endl;
    Q->Display();
    return 0;
}
