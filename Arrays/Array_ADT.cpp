#include <iostream>
using namespace std;

struct Array
{
    int A[10];
    int size;
    int length;
};

void Display(struct Array arr)
{
    int i;
    cout<<"Elements are: "<<endl;
    for(i = 0; i<arr.length; i++)
        cout<<arr.A[i];
}

void Append(struct Array *arr, int x)
{
    if(arr->length < arr->size)
        arr->A[arr->length++] = x;
}

void Insert(struct Array *arr, int index, int x)
{
    int i;

    if(index>0 && index <= arr->length)
    {
        for(i=arr->length; i>index; i--)
            arr->A[i] = arr->A[i-1];
        arr->A[index]=x;
        arr->length++;
    }
}

int Delete(struct Array *arr, int index)
{
    int x = 0;
    int i;
    if(index>=0 && index<arr->length)
    {
        x = arr->A[index];
        for(i=index; i<arr->length-1; i++)
            arr->A[i]=arr->A[i+1];
        arr->length--;
        return x;
    }
    return 0;
}

void swap(int *x,int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}

int Linear_Search(struct Array *arr, int key)
{
    for(int i = 0; i<arr->length; i++)
    {
        if(key==arr->A[i])
        {
            swap(&arr->A[i], &arr->A[0]);
            return i;
        }
    }
    return -1;
}

int Binary_Search(struct Array arr, int key)
{
    int l=0;
    int h=arr.length-1;
    int mid, i;

    while (l<=h)
    {
        mid = (l+h)/2;
        if(key==arr.A[mid])
            return mid;
        else if(key<arr.A[mid])
            h = mid-1;
        else
            l = mid+1;
    }
    return -1;
}

int main()
{
    struct Array arr1 = {{2, 3, 4, 5, 6}, 10, 5};
    // Append(&arr1, 10);
    // Insert(&arr1, 0, 12);
    // cout<<Delete(&arr1, 4)<<endl;
    cout<<Binary_Search(arr1,5)<<endl;
    cout<<Linear_Search(&arr1,5)<<endl;
    Display(arr1);
    return 0;
}
