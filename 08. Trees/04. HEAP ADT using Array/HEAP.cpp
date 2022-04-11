#include <iostream>

using namespace std;
class Heap
{
    int *H;
    int size;
    int n;
public:
    Heap(int size)
    {
        n = 1;
        this->size = size;
        H = new int[size+1];
        H[0] = 0;
    }
    void Insert(int key);
    void Display();
    void Create(int A2[], int size);
    int Delete();

    void InsertHeapify(int *A, int sizeofarray);
};

void Heap::Insert(int key)
{
    int temp,i=n;
    temp = key;
    while(i>1 && temp>H[i/2])
    {
        H[i] = H[i/2];
        i = i/2;
    }
    H[i] = temp;
    n++;
}

void Heap::Create(int A2[], int size2)
{
    for(int i=0; i<size2; i++)
        Insert(A2[i]);
}

int Heap::Delete()
{
    if(n==1){return -1;}

    int i,j,x, temp;
    x = H[1];
    n--;
    H[1] = n;
    H[n] = x;
    i=1, j=2*i;
    while(j<n-1)
    {
        if(H[j+1]>H[j])
            j = j+1;
        if(H[i]<H[j])
        {
            temp = H[i];
            H[i] = H[j];
            H[j] = temp;
            i=j;
            j = 2*j;
        }
        else
            break;
    }
    return x;
}
void Heap::Display()
{
    for(int i=0;i<n; i++)
        cout<<H[i]<<" ";
    cout<<endl;
}

void Heap::InsertHeapify(int *A, int sizeofarray)
{
    cout<<"\nInsertion using Heapify Method:";
    int i;
    for(i=0; i<sizeofarray; i++)
    {
        H[i+1] = A[i];
    }
    cout<<endl;
    for(i=sizeofarray; i>0; i--)
    {
        if((i*2)>sizeofarray)
        {}
        else
        {
            int temp = H[i];
            int j = i;
            while(j*2<=sizeofarray && temp<H[j*2])
            {
                int k = H[j];
                if(H[j*2]>H[j*2+1])
                {
                    H[j] = H[j*2];
                    H[j*2] = k;
                    j = j*2;
                }
                else
                {
                    H[j] = H[j*2+1];
                    H[j*2+1] = k;
                    j = j*2+1;
                }
            }
        }
    }
    for(i=1; i<=sizeofarray; i++)
    {
        cout<<H[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int A[] = {5,10,30,20,35,40,15};
    int size = sizeof(A)/sizeof(A[0]);
    Heap heap(size);
    for(int i=0; i<size; i++)
        heap.Insert(A[i]);

    int A2[] = {5,35,40,20,10,30,15};
    int size2 = sizeof(A2)/sizeof(A2[0]);
    Heap heap2(size2);
    heap2.Create(A2, size2);

    heap.Display();
    heap2.Display();

    // Delete
    cout<<"Deleted: "<<heap2.Delete()<<endl;
    heap2.Display();
    heap2.Insert(50);
    heap2.Display();

    // Insert using Heapify
    Heap Heap3(size);
    Heap3.InsertHeapify(A, size);
    return 0;
}
