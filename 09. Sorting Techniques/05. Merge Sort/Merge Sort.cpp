#include <iostream>

using namespace std;

class Sort
{
public:
    void Merge(int *A, int l, int mid, int h);
    void IMergeSort(int *A, int n);
    void RMergeSort(int *A, int l, int h);
};

void Sort::Merge(int *A, int l, int mid, int h)
{
    int i,j, k;
    int B[100];
    i = l; j = mid +1; k=l;

    while(i<=mid && j<=h)
    {
        if(A[i]<A[j])
            B[k++] = A[i++];
        else
            B[k++] = A[j++];
    }

    for(; i<=mid; i++)
        B[k++] = A[i];
    for(; j<=h; j++)
        B[k++] = A[j];

    for(i=l; i<=h; i++)
        A[i] = B[i];
}

void Sort::IMergeSort(int *A, int n)
{
    int p, l, h, mid, i;

    for(p=2; p<=n; p=p*2)
    {
        for(i=0; i+p-1<n; i=i+p)
        {
            l = i;
            h = i+p-1;
            mid = (l+h)/2;
            Merge(A,l,mid,h);
        }
    }
    if(p/2<n)
    {
        Merge(A, p/2, (p/2+n)/2, n-1);
        Merge(A, 0, p/2-1, n-1);
    }
}

void Sort::RMergeSort(int *A, int l, int h)
{
    int mid;
    if(l<h)
    {
        mid = (l+h)/2;
        RMergeSort(A, l, mid);
        RMergeSort(A, mid+1, h);
        Merge(A, l, mid, h);
    }
}

int main()
{
    Sort S;
    int A[] = {1,6,7,5,9,10,8,11,4,2,3};

    // Iterative Merge Sort
    S.IMergeSort(A, 11);

    for(int i=0; i<11; i++)
        cout<<A[i]<<" ";
    cout<<endl;

    // Recursive Merge Sort
    int B[] = {11,13,7,12,16,9,24,5,10,3};
    S.RMergeSort(B, 0, 9);

    for(int i=0; i<10; i++)
        cout<<B[i]<<" ";
    cout<<endl;

    return 0;
}
