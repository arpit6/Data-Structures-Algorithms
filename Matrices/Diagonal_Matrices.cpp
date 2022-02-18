#include <iostream>

using namespace std;

class Diagonal
{
private:
    int n;
    int *A;

public:
    Diagonal()
    {
        n = 2;
        A = new int[n];
    }
    Diagonal(int n)
    {
        this->n=n;
        A=new int[n];
    }
    void set(int i, int j, int x);
    int get(int i, int j);
    void Display();
    ~Diagonal(){delete []A;}
};

void Diagonal::set(int i, int j, int x)
{
    if(i==j)
        A[i-1] = x;
}

int Diagonal::get(int i, int j)
{
    if(i==j)
        return A[i-1];
    else
        return 0;
}

void Diagonal::Display()
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i==j)
                cout<<A[i-1]<<" ";
            else
                cout<<"0 ";
        }
        cout<<endl;
    }
}
int main()
{
    int d;
    cout<<"Enter Dimensional: ";
    cin>>d;

    Diagonal dm(d);

    int x;
    cout<<"Enter All Elements ";
    for(int i=0; i<d; i++)
    {
        for(int j=0; j<d; j++)
        {
            cin>>x;
            dm.set(i, j, x);
        }
    }
    dm.Display();
    return 0;
}
