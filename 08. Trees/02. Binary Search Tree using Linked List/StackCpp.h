#include <iostream>
using namespace std;

#ifndef STACKCPP_H_INCLUDED
#define STACKCPP_H_INCLUDED

class StackNode
{
public:
    Node * data;
    StackNode *next;
};

class Stack {
private:
    StackNode* top;

public:
    int element;
    Stack(){top=NULL;}

    void Display();
    void Push(Node* x);
    Node* Pop();
    bool isEmpty();
    bool isFull();
    Node* Stacktop();
};

void Stack::Push(Node* x)
{
    StackNode *t = new StackNode;
    if (t == NULL) {
        cout << "Stack Overflow. Unable to push!" << endl;
    }
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}

Node* Stack::Pop() {
    StackNode* t;
    Node* x = NULL;

    if (top == NULL) {
        cout << "Stack Underflow. Unable to pop!" << endl;
    }
    else
    {
        t = top;
        top = top->next;
        x = t->data;
        delete t;
    }
    return x;
}

bool Stack::isEmpty() {
    if (top == NULL) {
        return true;
    }
    else {
        return false;
    }
}

bool Stack::isFull()
{
    StackNode* t = new StackNode;
    if (t == NULL) {
        delete t;
        return true;
    }
    else {
        delete t;
        return false;
    }

}

Node* Stack::Stacktop()
{
    if(top!=NULL)
            return top->data;

    else
    {
        Node *t = new Node;
        t->data = INT_MAX;
        t->lchild = t->rchild = NULL;
        return t;
    }
}



#endif // STACKCPP_H_INCLUDED
