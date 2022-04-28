#include <iostream>

#define INT_MAX
using namespace std;

class Sort
{
public:
    int Partition(int *A, int l, int h);
    void Quick_Sort(int *A, int l, int h);
};

int Sort::Partition(int *A, int l, int h)
{
    int pivot = A[l];
    int i=l, j=h;
    int temp;

    do
    {
        do{i++;}while(A[i]<=pivot);
        do{j--;}while(A[j]>pivot);

        if(i<j)
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }while(i<j);
    temp = A[l];
    A[l] = A[j];
    A[j] = temp;
    return j;
}

void Sort::Quick_Sort(int *A, int l, int h)
{
    int j;
    if(l<h)
    {
        j = Partition(A, l, h);
        Quick_Sort(A, l, j);
        Quick_Sort(A, j+1, h);
    }
}
int main()
{
    Sort S;
    int A[] = {11,13,7,12,16,9,24,5,10,3,INT_MAX};
    S.Quick_Sort(A, 0, 10);

    for(int i=0; i<10; i++)
        cout<<A[i]<<" ";
    return 0;
}
