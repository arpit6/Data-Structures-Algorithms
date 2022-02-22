#include <iostream>

using namespace std;

int fun(int n)
{
    if(n>100)
        return (n-10);

    return fun(fun(n+11));
}
int main()
{
    int r = fun(9
                5);
    cout<<r;
}
