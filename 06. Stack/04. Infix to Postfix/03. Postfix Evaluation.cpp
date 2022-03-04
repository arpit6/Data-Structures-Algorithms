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
    int OutStackPre(char x);
    int InStackPre(char x);
    int Evaluation(char *postfix);
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
    if(x=='+'||x=='-'||x=='*'||x=='/'||x=='^'||x=='('||x==')')
        return 0;
    return 1;
}

int Stack::OutStackPre(char x)
{
    if(x=='+'||x=='-')
        return 1;
    else if(x=='*'||x=='/')
        return 3;
    else if(x=='^')
        return 6;
    else if(x=='(')
        return 7;
    else if(x==')')
        return 0;
    return -1;
}

int Stack::InStackPre(char x)
{
    if(x=='+'||x=='-')
        return 2;
    else if(x=='*'||x=='/')
        return 4;
    else if(x=='^')
        return 5;
    else if(x=='(')
        return 0;
    return -1;

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
            if(OutStackPre(infix[i])>InStackPre(Stacktop()))
                Push(infix[i++]);
            else if(OutStackPre(infix[i])==InStackPre(Stacktop()))
            {
                Pop();
                i++;
            }
            else
                postfix[j++] = Pop();
        }
    }
    while(!isEmpty())
        postfix[j++] = Pop();

    postfix[j] = '\0';

    return postfix;
}

int Stack::Evaluation(char *postfix)
{
    int i,x1,x2,r;
    char k;
    for(i=0;postfix[i]!='\0';i++)
    {
        if(isOperand(postfix[i]))
            Push(postfix[i]);
        else
        {
           x2 = Pop()-48;
           x1 = Pop()-48;
           switch(postfix[i])
           {
               case '+': r = x1+x2; break;
               case '-': r = x1-x2; break;
               case '/': r = x1/x2; break;
               case '*': r = x1*x2; break;
           }
           k=r+48;
           Push(k);
        }
    }
    return int(Stacktop())-48;
}
int main()
{
    char *infix = "3*5+6/2-4";
    Stack stk(infix);
    char *postfix = stk.Convert(infix);
    cout<<"Infix: "<<infix<<endl;
    cout<<"Postfix: "<<postfix<<endl;
    cout<<"Evaluation: "<<stk.Evaluation(postfix)<<endl;
    return 0;
}
