#include <iostream>

using namespace std;

class Lower_Tri
{
private:
    int n;
    int *A;

public:
    Lower_Tri()
    {
        n = 2;
        A = new int[n*(n+1)/2];
    }
    Lower_Tri(int n)
    {
        this->n=n;
        A=new int[n*(n+1)/2];
    }

    void Set(int i, int j, int x);
    int Get(int i, int j);
    void Display();
    ~Lower_Tri(){delete []A;}
};

void Lower_Tri::Set(int i, int j, int x)
{
    if(i<=j)
        A[(i*(i-1)/2)+(j-1)] = x;
}

int Lower_Tri::Get(int i, int j)
{
    if(i<=j)
        return A[(i*(i-1)/2)+(j-1)];
    return 0;
}

void Lower_Tri::Display()
{
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(i<=j)
                cout<<A[(i*(i-1)/2)+(j-1)]<<" ";
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

    Lower_Tri lt(d);

    int x;
    cout<<"Enter All Elements ";
    for(int i=1; i<=d; i++)
    {
        for(int j=1; j<=d; j++)
        {
            cin>>x;
            lt.Set(i, j, x);
        }
    }
    lt.Display();
    return 0;
}
