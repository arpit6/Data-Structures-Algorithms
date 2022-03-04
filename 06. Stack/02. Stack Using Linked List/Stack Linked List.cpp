#include <iostream>

using namespace std;

template <class T>
class Node
{
public:
    T data;
    Node<T> *next;
};

template <class T>
class Stack
{
private:
    Node<T> *top;
public:
    Stack()
    {
        top = NULL;
    }
    void Push(T x);
    T Pop();
    T Peek(int pos);
    T Stacktop();
    int isEmpty();
    int isFull();
    void Display();
};

template <class T>
void Stack<T>::Push(T x)
{
    Node<T> *t = new Node<T>;

    if(t==NULL)
        cout<<"Stack Overflow";
    t->data = x;
    t->next = NULL;

    if(top==NULL)
        top = t;
    else
    {
        t->next = top;
        top = t;
    }
}

template <class T>
T Stack<T>::Pop()
{
    Node<T> *p;
    T x=-1;
    if(top==NULL)
        cout<<"Stack Underflow";
    else
    {
        p = top;
        top = top->next;
        x = p->data;
        delete(p);
    }
    return x;
}

template <class T>
T Stack<T>::Peek(int pos)
{
    int i;
    Node<T> *p = top;
    for(i=1; p!=NULL&&i<pos; i++)
        p=p->next;
    if(p!=NULL)
        return p->data;
    return -1;
}

template <class T>
int Stack<T>::isEmpty()
{
    if(top==NULL)
        cout<<"Stack is Empty";
    return;
}

template <class T>
int Stack<T>::isFull()
{
    Node<T> *t = new Node<T>;
    if(t==NULL)
        cout<<"Stack is FULL";
    return;
}

template <class T>
T Stack<T>::Stacktop()
{
    if(top)
        return top->data;
    return -1;
}

template <class T>
void Stack<T>::Display()
{
    Node<T> *p = top;
    while(p)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}
int main()
{
    Stack<char>* stk = new Stack<char>();
    stk->Push('a');
    stk->Push('b');
    stk->Push('c');
    stk->Push('d');
    stk->Push('e');
    stk->Push('f');
    stk->Display();
    stk->Pop();
    stk->Display();
    cout<<stk->Peek(2)<<endl;
    cout<<stk->Stacktop();
    return 0;
}
