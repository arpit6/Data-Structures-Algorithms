#include <iostream>
#define SIZE 10
using namespace std;


class LinearProbing
{
    int H[SIZE] = {0};
public:
    void Insert(int x);
    int Probe(int key);
    int Hash(int key);
    int Search(int x);
    void Display();
};

int LinearProbing::Hash(int key)
{
    return key%SIZE;
}

int LinearProbing::Probe(int key)
{
    int index = Hash(key);
    int i=0;
    while(H[(index+i)%SIZE]!=0)
        i++;
    return ((index+i)%SIZE);
}

void LinearProbing::Insert(int key)
{
    int index = Hash(key);

    if(H[index]!=0)
        index = Probe(key);
    H[index]=key;
}

int LinearProbing::Search(int key)
{
    int index = Hash(key);

    int i=0;
    while(H[(index+i)%SIZE]!=key)
    {
        i++;
        if(H[(index+i)%SIZE]==0)
            return -1;
    }
    return (index+i)%SIZE;
}
void LinearProbing::Display()
{
    for(int i=0; i<SIZE; i++)
        cout<<H[i]<<" ";
    cout<<endl;
}
int main()
{
    LinearProbing LP;
    LP.Insert(12);
    LP.Insert(25);
    LP.Insert(35);
    LP.Insert(36);
    LP.Display();

    cout<<"Key found at: "<<LP.Search(45);
    return 0;
}
