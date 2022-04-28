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
    void BinSort(int *A, int n);
    int findMax(int *A, int n);
    Node* Insert(Node** k, int d);
    int Delete(Node** k);
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
void Sort::BinSort(int *A, int n)
{
    int Max, i, j;
    Max = findMax(A, n);

    Bins = new Node*[Max+1];

    for(i=0; i<Max+1; i++)
        Bins[i] = NULL;

    for(i=0; i<n; i++)
        Insert(&Bins[A[i]], A[i]);

    i=j=0;

    while(i<Max+1)
    {
        while(Bins[i]!=NULL)
        {
            A[j] = Delete(&Bins[i]);
            j++;
        }
        i++;
    }
}

int main()
{
    Sort S;
    int A[] = {6,3,9,10,15,6,8,12,3,6};

    S.BinSort(A, 10);

    cout<<"Sorted Array: ";
    for(int i=0; i<10; i++)
        cout<<A[i]<<" ";
    return 0;
}
