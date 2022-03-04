#include <iostream>
#include<string.h>

using namespace std;

class Stack
{
private:
    char *st;
    int size;
    int top;

public:
    Stack(){size = 10; top=-1; st = new char[size]; }
    Stack(char *infix)
    {
        this->size = strlen(infix);
        top = -1;
        st = new char[this->size];
    }

    void Push(char x);
    char Pop();
    char Stacktop();
    int isEmpty();
    int isFull();
    void Display();
    char* Convert(char *infix);
    int isOperand(char x);
    int Precision(char x);
};

void Stack::Push(char x)
{
    if(isFull())
        cout<<"Stack Overflow"<<endl;
    else
    {
        top++;
        st[top] = x;
    }
}

char Stack::Pop()
{
    char x = '-1';
    if(isEmpty())
        cout<<"Stack Underflow"<<endl;
    else
    {
        x = st[top];
        top--;
    }
    return x;
}

char Stack::Stacktop()
{
    if(isEmpty())
        return -1;
    return st[top];
}

int Stack::isFull()
{
    return top==size-1;
}

int Stack::isEmpty()
{
    return top==-1;
}

void Stack::Display()
{
    int i;
    for(i=top; i>=0; i--)
        cout<<st[i]<<" ";
    cout<<endl;
}

int Stack::isOperand(char x)
{
    if(x=='+'||x=='-'||x=='*'||x=='/')
        return 0;
    return 1;
}

int Stack::Precision(char x)
{
    if(x=='+'||x=='-')
        return 1;
    else if(x=='*'||x=='/')
        return 2;
    return 0;
}

char* Stack::Convert(char *infix)
{
    char *postfix = new char[strlen(infix)+1];

    int i=0, j=0;

    while(infix[i]!='\0')
    {
        if(isOperand(infix[i]))
            postfix[j++] = infix[i++];
        else
        {
            if(Precision(infix[i])>Precision(Stacktop()))
                Push(infix[i++]);
            else
                postfix[j++] = Pop();
        }
    }
    while(!isEmpty())
        postfix[j++] = Pop();
    postfix[j] = '\0';

    return postfix;
}



int main()
{
    char *infix = "a+b*c-d/e";
    Stack stk(infix);
    char *postfix = stk.Convert(infix);
    cout<<postfix;
    return 0;
}
