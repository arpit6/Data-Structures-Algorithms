#include<iostream>
using namespace std;

#ifndef STACK_CPP_H_INCLUDED
#define STACK_CPP_H_INCLUDED

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
    Node<T>* top;
public:
    Stack(){top=NULL;}

    void Display()
    {
        Node<T> *p = top;
        while(p)
        {
            cout<<p->data<<" ";
            p = p->next;
        }
    }

    void ReverseDisplay()
    {
        ReverseRecDisplay(top);
    }
    void ReverseRecDisplay(Node<T> *p)
    {
        if(p==NULL)
            return;
        ReverseRecDisplay(p->next);
        cout<<p->data<<" ";
    }

    void Push(T x)
    {
        Node<T> *p = new Node<T>;
        if(p==NULL)
            cout<<"Stack Overflow"<<endl;
        else
        {
            p->data = x;
            p->next = top;
            top = p;
        }
    }

    T Pop()
    {
        T x = -1;
        Node<T> *p;
        if(top==NULL)
        {
            cout<<"Stack UnderFlow"<<endl;
        }
        else
        {
            p = top;
            top = top->next;
            x = p->data;
            delete p;
        }
        return x;
    }
    bool isEmpty()
    {
        if(top==NULL)
            return true;
        return false;
    }
    bool isFULL()
    {
        Node<T>* t = new Node<T>;
        if(t==NULL)
            return true;
        return false;
    }
};

#endif // STACK_CPP_H_INCLUDED
