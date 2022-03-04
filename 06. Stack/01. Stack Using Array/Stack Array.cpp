#include <iostream>

using namespace std;

template<class T>
class Stack
{
private:
    T*st;
    int size;
    int top;

public:
    Stack(){size = 10; top=-1; st = new T[size];}
    Stack(int size)
    {
        this->size = size;
        top = -1;
        st = new T[this->size];
    }

    void Push(T x);
    T Pop();
    T Peek(int index);
    int Stacktop();
    int isEmpty();
    int isFull();
    void Display();
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
T Stack<T>::Peek(int index)
{
    T x=-1;
    if(top-index+1<0)
        cout<<"Invalid Index"<<endl;
    else
        x = st[top-index+1];
    return x;
}

template<class T>
int Stack<T>::Stacktop()
{
    if(isEmpty())
        return -1;
    return top;
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

template<class T>
void Stack<T>::Display()
{
    int i;
    for(i=top; i>=0; i--)
        cout<<st[i]<<" ";
    cout<<endl;
}
int main()
{
    Stack<char> stk(5);
    stk.Push('a');
    stk.Push('b');
    stk.Push('c');
    stk.Push('d');
    stk.Push('e');
    stk.Push('f');
    stk.Display();
    stk.Pop();
    stk.Display();
    cout<<stk.Peek(2)<<endl;
    cout<<stk.Stacktop();

    return 0;
}
