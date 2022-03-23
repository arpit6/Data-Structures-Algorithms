#include <iostream>

using namespace std;

template <class T>
class DEQueue
{
    int size, front, rear;
    T *Q;
public:
    DEQueue(int size)
    {
        this->size = size;
        front = -1;
        rear = -1;
        Q = new T[this->size];
    }
    void FEnqueue(T x);
    void REnqueue(T x);
    T FDequeue();
    T RDequeue();
    void Display();
};

template <class T>
void DEQueue<T>::FEnqueue(T x)
{
    if(rear==size-1)
        cout<<"Queue is Full"<<endl;
    else
    {
        rear++;
        for(int i=rear; i>front+1; i--)
        {
            Q[i] = Q[i-1];
        }
        Q[front+1] = x;
    }
}

template <class T>
void DEQueue<T>::REnqueue(T x)
{
    if(rear==size-1)
        cout<<"Queue is Full"<<endl;
    else
    {
        rear++;
        Q[rear] = x;
    }
}

template <class T>
T DEQueue<T>::FDequeue()
{
    T x=-1;
    if(front==rear)
        cout<<"Queue is Empty"<<endl;
    else
    {
        x = Q[front+1];
        front++;
    }
    return x;
}

template <class T>
T DEQueue<T>::RDequeue()
{
    T x = -1;
    if(front==rear)
        cout<<"Queue is Empty"<<endl;
    else
    {
        x = Q[rear];
        rear--;
    }
    return x;
}

template <class T>
void DEQueue<T>::Display()
{
    int i;
    cout<<"Queue is: ";
    for(i=front+1; i<=rear; i++)
        cout<<Q[i]<<" ";
    cout<<endl;
}
int main()
{
    int n;
    cout<<"Enter size of Queue: ";
    cin>>n;
    DEQueue<int> *Q = new DEQueue<int>(n);
    Q->FEnqueue(1);
    Q->REnqueue(2);
    Q->Display();
    Q->FDequeue();
    Q->Display();
    Q->FEnqueue(3);
    Q->RDequeue();
    Q->Display();
    return 0;
}
