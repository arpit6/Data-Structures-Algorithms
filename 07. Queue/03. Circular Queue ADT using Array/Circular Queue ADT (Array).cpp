#include <iostream>

using namespace std;

template <class T>
class Queue
{
private:
    int size;
    int rear;
    int front;
    T *Q;
public:
    Queue(){size=10; rear=front=0; Q = new T[size];}
    Queue(int size){front=rear=0; this->size = size; Q = new T[this->size];}
    void Enqueue(T x);
    T Dequeue();
    void Display();
};

template <class T>
void Queue<T>::Enqueue(T x)
{
    if((rear+1)%size == front)
        cout<<"Queue is Full"<<endl;
    else
    {
        rear = (rear+1)%size;
        Q[rear] = x;
    }
}

template <class T>
T Queue<T>::Dequeue()
{
    T x=-1;
    if(front==rear)
        cout<<"Queue is Empty"<<endl;
    else
    {
        front = (front+1)%size;
        x = Q[front];
    }
    return x;
}

template <class T>
void Queue<T>::Display()
{
    int i = front+1;
    cout<<"Queue is: ";
    do
    {
        cout<<Q[i]<<" ";
        i = (i+1)%size;
    }while(i!=(rear+1)%size);
    cout<<endl;
}
int main()
{
    int n;
    cout<<"Enter size of Queue: ";
    cin>>n;
    Queue<char> *que = new Queue<char>(n);
    que->Enqueue('a');
    que->Enqueue('b');
    que->Display();
    cout<<"Removed: "<<que->Dequeue()<<endl;
    que->Enqueue('c');
    que->Display();
    cout<<"Removed: "<<que->Dequeue()<<endl;
    que->Display();
    return 0;
}
