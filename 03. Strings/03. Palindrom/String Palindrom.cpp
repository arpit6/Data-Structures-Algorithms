#include <iostream>

using namespace std;

int main()
{
    char A[] = "ma
    dam";
    int i, j, c = 0;

    for(j=0; A[j]!='\0'; j++)
    {
    }
    j = j-1;

    for(i=0; i<j; i++, j--)
    {
        if(A[i]!=A[j])
        {
            cout<<"Not Palindrom";
            c = c+1;
            break;
        }
    }

    if(c == 0)
        cout<<"Palindrom";
}
