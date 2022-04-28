#include <iostream>

#define INT_MAX
using namespace std;

class Sort
{
public:
    int findMax(int *A, int n);
    void Count_Sort(int *A, int n);
};

int Sort::findMax(int *A, int n)
{
    int Max = 0;
    for(int i=0; i<n; i++)
    {
        if(Max < A[i])
            Max = A[i];
    }
    return Max;
}

void Sort::Count_Sort(int *A, int n)
{
    int Max, i, j;
    int *C;
    Max = findMax(A, n);
    C = new int[Max+1];

    for(i=0; i<Max+1; i++)
        C[i] = 0;

    for(i=0; i<n; i++)
        C[A[i]]++;

    i=j=0;
    while(i<Max+1)
    {
        if(C[i]>0)
        {
            A[j++] = i;
            C[i]--;
        }
        else
            i++;
    }
}
int main()
{
    Sort S;
    int A[] = {6,3,9,10,15,6,8,12,3,6};
    S.Count_Sort(A, 10);

    for(int i=0; i<10; i++)
        cout<<A[i]<<" ";
    return 0;
}
