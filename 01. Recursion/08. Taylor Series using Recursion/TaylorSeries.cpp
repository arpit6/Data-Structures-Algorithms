#include <iostream>

using namespace std;

int e(int m, int n)
{
    static int s=1;
    if(n==0)
        return s;
    s = 1+ m/n *s;
    return e(m, n-1);
}

int main()
{
    cout<<e(2,4);
    return 0;
}
