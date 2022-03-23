#include <iostream>

using namespace std;

template <class T>
class Queue
{
private:
    int size;
    int front;
    int rear;
    T *Q;
public:
    Queue(){front=rear=-1; size=10; Q = new T[size];}
    Queue(int size)
    {
        this->size = size;
        front = rear = -1;
        Q = new T[this->size];
    }
    void Enqueue(T x);
    T Dequeue();
    void Display();
};

template <class T>
void Queue<T>::Enqueue(T x)
{
    if(rear==size-1)
        cout<<"Queue is full"<<endl;
    else
    {
        rear++;
        Q[rear] = x;
    }
}

template <class T>
T Queue<T>::Dequeue()
{
    T x = -1;
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
void Queue<T>::Display()
{
    int i;
    for(i=front+1; i<=rear; i++)
        cout<<Q[i]<<" ";
    cout<<endl;
}

int main()
{
    int n;
    cout<<"Enter size of Queue: ";
    cin>>n;
    Queue<int> *que = new Queue<int>(n);
    cout<<"Deleted Element :"<<que->Dequeue()<<endl;
    que->Enqueue(10);
    que->Enqueue(20);
    que->Enqueue(30);
    que->Enqueue(40);
    que->Enqueue(50);
    que->Enqueue(60);
    que->Enqueue(70);
    cout<<"Deleted Element :"<<que->Dequeue()<<endl;
    que->Display();
    return 0;
}
