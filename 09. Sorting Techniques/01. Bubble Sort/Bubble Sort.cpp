#include <iostream>

using namespace std;

class Sort
{
public:
    void Bubble_Sort(int *A, int n);
};

void Sort::Bubble_Sort(int *A, int n)
{
    int flag, i, j, temp;
    for(i=0; i<n-1; i++)
    {
        flag = 0;
        for(j=0; j<n-1-i; j++)
        {
            if(A[j]>A[j+1])
            {
                temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
                flag = 1;
            }
        }
        if(flag==0) break;
    }
}
int main()
{
    Sort S;
    int A[] = {8,5,7,3,2};
    S.Bubble_Sort(A, 5);

    for(int i=0; i<5; i++)
        cout<<A[i]<<" ";
    return 0;
}
