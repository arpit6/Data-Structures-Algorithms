#include <iostream>

using namespace std;
class Node
{
public:
    int data;
    Node *next;
};

class Sort
{
    Node **Bins;
public:
    void RadixSort(int *A, int n);
    int findMaxDigits(int *A, int n);
    Node* Insert(Node** k, int d);
    int Delete(Node** k);
};

int Sort::findMaxDigits(int *A, int n)
{
    int Max = 0;
    for(int i=0; i<n; i++)
    {
        if(Max < A[i])
            Max = A[i];
    }

    int count = 0;
    while(Max!=0)
    {
        Max = Max/10;
        ++count;
    }
    return count;
}

Node* Sort::Insert(Node** k, int d)
{
    Node *t = new Node;
    t->data = d;
    t->next = NULL;

    if((*k) == NULL)
    {
        (*k) = t;
    }
    else
    {
        Node* p = *k;
        while(p->next!=NULL)
            p = p->next;
        p->next = t;
    }
    return (*k);
}

int Sort::Delete(Node** k)
{
    int x=-1;

    Node *t = *k;
    (*k) = (*k)->next;
    x = t->data;
    delete(t);
    return x;

}
void Sort::RadixSort(int *A, int n)
{
    int Max, i, j;
    Max = findMaxDigits(A, n);
    Bins = new Node*[n];

    int Divisor = 1;
    for(int k=0; k<Max; k++)
    {
        for(i=0; i<n; i++)
            Bins[i] = NULL;

        for(i=0; i<n; i++)
            Insert(&Bins[((A[i]/Divisor)%10)], A[i]);

        i=j=0;

        while(i<n)
        {
            while(Bins[i]!=NULL)
            {
                A[j] = Delete(&Bins[i]);
                j++;
            }
            i++;
        }
        Divisor = Divisor*10;
    }
}

int main()
{
    Sort S;
    int A[] = {237, 146, 259, 348, 152, 163, 235, 48, 36, 62};

    S.RadixSort(A, 10);

    cout<<"Sorted Array: ";
    for(int i=0; i<10; i++)
        cout<<A[i]<<" ";
    return 0;
}
