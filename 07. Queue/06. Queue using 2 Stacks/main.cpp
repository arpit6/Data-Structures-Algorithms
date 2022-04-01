#include <iostream>
#include "Stack_Cpp.h"

using namespace std;

template <class T>
class QueueStack
{
private:
    Stack<T> Stk1;
    Stack<T> Stk2;
public:
    QueueStack(){}
    void Enqueue(T x);
    T Dequeue();
    void Display();
    bool isFull();
    bool isEmpty();
};

template<class T>
void QueueStack<T>::Enqueue(T x)
{
    if(isFull())
        cout<<"Queue is FULL"<<endl;
    else
    {
        Stk1.Push(x);
        cout << x << " Enqueued" << endl;
    }
}

template<class T>
T QueueStack<T>::Dequeue()
{
    if(Stk2.isEmpty())
    {
        if(Stk1.isEmpty())
        {
            cout<<"Queue is Empty"<<endl;
            return -1;
        }
        else
        {
            while(!Stk1.isEmpty()){
                Stk2.Push(Stk1.Pop());}
        }
    }
    return Stk2.Pop();
}

template<class T>
bool QueueStack<T>::isFull()
{
    return Stk1.isFULL();
}

template <class T>
bool QueueStack<T>::isEmpty()
{
    if(Stk2.isEmpty())
    {
        if(Stk1.isEmpty())
        {
            return true;
        }
        else return false;
    }
    return false;
}

template <class T>
void QueueStack<T>::Display()
{
    if(!Stk2.isEmpty())
    {
        Stk2.Display();
        if(!Stk1.isEmpty())
            Stk1.ReverseDisplay();
    }
    else
    {
        if(!Stk1.isEmpty())
            Stk1.ReverseDisplay();
    }
    cout<<endl;
}
int main()
{
    QueueStack<int> *Q = new QueueStack<int>();
    Q->Enqueue(6);
    Q->Enqueue(3);
    Q->Enqueue(9);
    cout<<"\nQueue is: ";
    Q->Display();
    cout<<"Deleted is: "<<Q->Dequeue()<<endl;
    Q->Enqueue(5);
    Q->Enqueue(4);
    cout<<"\nQueue is: ";
    Q->Display();
    return 0;
}
