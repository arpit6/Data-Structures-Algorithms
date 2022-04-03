#include <iostream>
using namespace std;

#ifndef QUEUECPP_H_INCLUDED
#define QUEUECPP_H_INCLUDED

class Node
{
public:
    Node *lchild;
    int data;
    Node *rchild;
};

class Queue
{
private:
    int size;
    int front;
    int rear;
    Node **Q;
public:
    Queue(){front=rear=-1; size=10; Q = new Node*[size];}
    Queue(int size)
    {
        this->size = size;
        front = rear = -1;
        Q = new Node*[this->size];
    }
    void Enqueue(Node* x);
    Node* Dequeue();
    int isEmpty(){return front==rear;}
    void Display();
};

void Queue::Enqueue(Node* x)
{
    if(rear==size-1)
        cout<<"Queue is full"<<endl;
    else
    {
        rear++;
        Q[rear] = x;
    }
}

Node* Queue::Dequeue()
{
    Node* x = NULL;
    if(front==rear)
        cout<<"Queue is Empty"<<endl;
    else
    {
        x = Q[front+1];
        front++;
    }
    return x;
}

void Queue::Display()
{
    int i;
    for(i=front+1; i<=rear; i++)
        cout<<Q[i]<<" ";
    cout<<endl;
}
#endif // QUEUECPP_H_INCLUDED
