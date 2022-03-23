#include <iostream>

using namespace std;

template <class T>
class PriorityQueue
{
private:
    int size, rear;
    T *Q;
public:
    PriorityQueue(int size)
    {
        this->size = size;
        rear=-1;
        Q = new T[this->size];
    }
    void Enqueue(T x);
    T Dequeue();
    void Display();
};

template <class T>
void PriorityQueue<T>::Enqueue(T x)
{
    if(rear==size-1)
        cout<<"Queue is Full"<<endl;
    else
    {
        rear++;
        if(rear==0)
            Q[rear] = x;
        else
        {

            int pos=-1;
            for(int i=0; i<rear; i++)
            {
                if(x>=Q[i])
                {
                    pos = i;
                    break;
                }
            }
            if(pos==-1)
                Q[rear] = x;
            else
            {
                for(int i=rear; i>pos; i--)
                {
                    Q[i] = Q[i-1];
                }
                Q[pos] = x;
            }
        }
    }
}

template <class T>
T PriorityQueue<T>::Dequeue()
{
    T x = -1;
    if(rear==-1)
        cout<<"Queue is Empty"<<endl;
    else
    {
        x = Q[rear];
        rear--;
    }
    return x;
}

template <class T>
void PriorityQueue<T>::Display()
{
    cout<<"Queue is: ";
    if(rear==-1)
        cout<<"Empty";
    else
    {
         for(int i=0; i<=rear; i++)
        {
            cout<<Q[i]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    PriorityQueue<int> *Q = new PriorityQueue<int>(10);
    Q->Enqueue(6);
    Q->Enqueue(8);
    Q->Enqueue(3);
    Q->Enqueue(10);
    Q->Enqueue(15);
    Q->Enqueue(2);
    Q->Enqueue(9);
    Q->Enqueue(17);
    Q->Enqueue(5);
    Q->Enqueue(8);
    Q->Display();
    cout<<"Deleted: "<<Q->Dequeue()<<endl;
    cout<<"Deleted: "<<Q->Dequeue()<<endl;
    Q->Display();
    return 0;
}
