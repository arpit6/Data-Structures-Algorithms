#include <iostream>
#include<math.h>
#define SIZE 10
using namespace std;


class DoubleHashing
{
    int H[SIZE] = {0};
public:
    void Insert(int x);
    int Hash(int key);
    int Hash2(int key);
    int Probe(int key);
    int Search(int x);
    void Display();
};

int DoubleHashing::Hash(int key)
{
    return key%SIZE;
}

int DoubleHashing::Hash2(int key)
{
    return (7-(key%7));
}

int DoubleHashing::Probe(int key)
{
    int i=0;
    int index = Hash(key);
    while(H[(index+(i*Hash2(key)))%10]!=0)
        i++;
    return ((index+i*Hash2(key))%10);
}

void DoubleHashing::Insert(int key)
{
    int index = Hash(key);

    if(H[index]!=0)
        index = Probe(key);
    H[index]=key;
}

int DoubleHashing::Search(int key)
{
    int index = Hash(key);
    int i=0;
    while(H[(index+(i*Hash2(key)))%10]!=key)
        i++;

    return ((index+i*Hash2(key))%10);
}

void DoubleHashing::Display()
{
    for(int i=0; i<SIZE; i++)
        cout<<H[i]<<" ";
    cout<<endl;
}
int main()
{
    DoubleHashing DH;
    DH.Insert(5);
    DH.Insert(25);
    DH.Insert(15);
    DH.Insert(35);
    DH.Insert(95);
    DH.Display();

    cout<<"Key found at: "<<DH.Search(25);
    return 0;
}
