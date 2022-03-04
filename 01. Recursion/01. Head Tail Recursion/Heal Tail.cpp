#include <iostream>

using namespace std;

int fun(int n)
{
    if(n>0)
    {

        fun(n-1);
        cout<<n;
    }
}
int main()
{
    fun(3);
}
