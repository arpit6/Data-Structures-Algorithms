Pa#include <iostream>
#include<string.h>

using namespace std;

template<class T>
class Stack
{
private:
    T *st;
    int size;
    int top;
public:
    Stack(){size=10;top=-1;st=new T[size];}
    Stack(char *exp){size=strlen(exp); top=-1; st=new T[size];}
    void Push(T x);
    T Pop();
    int isEmpty();
    int isFull();
    int isBalanced(char *exp);
};

template<class T>
void Stack<T>::Push(T x)
{
    if(isFull())
        cout<<"Stack Overflow"<<endl;
    else
    {
        top++;
        st[top] = x;
    }
}
template<class T>
T Stack<T>::Pop()
{
    T x = -1;
    if(isEmpty())
        cout<<"Stack Underflow"<<endl;
    else
    {
        x = st[top];
        top--;
    }
    return x;
}

template<class T>
int Stack<T>::isFull()
{
    return top==size-1;
}

template<class T>
int Stack<T>::isEmpty()
{
    return top==-1;
}

template <class T>
int Stack<T>::isBalanced(char *exp)
{
    int i;
    for(i=0; exp[i]!='\0'; i++)
    {
        if(exp[i]=='(' || exp[i]=='[' || exp[i]=='{')
            Push(exp[i]);
        else if(exp[i]==')' || exp[i]==']' || exp[i]=='}')
        {
            if(top==-1)
                return 0;
            T x = Pop();
            if((x=='('&&exp[i]==')') || (x=='{'&&exp[i]=='}') || (x=='['&&exp[i]==']'))
               continue;
            else
                return 0;
        }
    }
    if(top==-1)
        return 1;
    else
        return 0;
}
int main()
{
    char *exp="((a+b)*(c-d))";
    Stack<char> stk(exp);
    if(stk.isBalanced(exp)==0)
        cout<<"Expression Parenthesis Not Matching"<<endl;
    else
        cout<<"Expression Parenthesis Matching"<<endl;

    char *exp2="{([a+b]*[c-d])}";
    Stack<char> stk2(exp2);
    if(stk2.isBalanced(exp2)==0)
        cout<<"Expression Parenthesis Not Matching"<<endl;
    else
        cout<<"Expression Parenthesis Matching"<<endl;
    return 0;
}
