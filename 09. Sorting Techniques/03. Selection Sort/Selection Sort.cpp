#include <iostream>

using namespace std;

class Sort
{
public:
    void Selection_Sort(int *A, int n);
};

void Sort::Selection_Sort(int *A, int n)
{
    int i, j, k, temp;
    for(i=0; i<n-1; i++)
    {
        for(j=k=i; j<n; j++)
        {
            if(A[j]<A[k])
                k = j;
        }
        temp = A[i];
        A[i] = A[k];
        A[k] = temp;
    }
}
int main()
{
    Sort S;
    int A[] = {8,6,3,2,5,4};
    S.Selection_Sort(A, 6);

    for(int i=0; i<6; i++)
        cout<<A[i]<<" ";
    return 0;
}
