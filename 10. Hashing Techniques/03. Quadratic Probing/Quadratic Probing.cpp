#include <iostream>
#include<math.h>
#define SIZE 10
using namespace std;


class QuadraticProbing
{
    int H[SIZE] = {0};
public:
    void Insert(int x);
    int Probe(int key);
    int Hash(int key);
    int Search(int x);
    void Display();
};

int QuadraticProbing::Hash(int key)
{
    return key%SIZE;
}

int QuadraticProbing::Probe(int key)
{
    int index = Hash(key);
    int i=0;
    while(H[(index+i)%SIZE]!=0)
    {
        if(i==1)
        {
            i++;
            i = i*i;
        }
        else
        {
            i = sqrt(i);
            i++;
            i = i*i;
        }
    }
    return ((index+i)%SIZE);
}

void QuadraticProbing::Insert(int key)
{
    int index = Hash(key);

    if(H[index]!=0)
        index = Probe(key);
    H[index]=key;
}

int QuadraticProbing::Search(int key)
{
    int index = Hash(key);

    int i=0;
    while(H[(index+i)%SIZE]!=key)
        i++;

    return (index+i)%SIZE;
}

void QuadraticProbing::Display()
{
    for(int i=0; i<SIZE; i++)
        cout<<H[i]<<" ";
    cout<<endl;
}
int main()
{
    QuadraticProbing QP;
    QP.Insert(23);
    QP.Insert(43);
    QP.Insert(13);
    QP.Insert(53);
    QP.Insert(3);
    QP.Insert(27);
    QP.Display();

    cout<<"Key found at: "<<QP.Search(13);
    return 0;
}
