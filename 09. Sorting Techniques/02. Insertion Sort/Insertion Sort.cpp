#include <iostream>

using namespace std;

class Sort
{
public:
    void Insertion_Sort(int *A, int n);
};

void Sort::Insertion_Sort(int *A, int n)
{
    int i, j, temp;
    for(i=1; i<n; i++)
    {
        j = i-1;
        temp = A[i];
        while(j>-1 && A[j]>temp)
        {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = temp;
    }
}
int main()
{
    Sort S;
    int A[] = {8,5,7,3,2};
    S.Insertion_Sort(A, 5);

    for(int i=0; i<5; i++)
        cout<<A[i]<<" ";
    return 0;
}
