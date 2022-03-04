#include <iostream>

using namespace std;

int main()
{
    int arr[10] = {1,2,3,4,6,7,8,10,11,13};
    int diff = arr[0] - 0;
    for(int i=0; i<10; i++)
    {
        if(diff != arr[i] - i)
        {
            cout<<i+diff;
            diff++;
        }

    }
    return 0;
}
