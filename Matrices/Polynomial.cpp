#include <iostream>

using namespace std;

class Element
{
public:
    int coeff;
    int exp;
};

class Polynomial
{
private:
    int n;
    Element *poly;
public:
    Polynomial(int n)
    {
        this->n = n;
        poly = new Element[this->n];
    }
    ~Polynomial()
    {
        delete []poly;
    }

    Polynomial operator+(Polynomial &p);
    friend istream &operator>>(istream &is, Polynomial &p);
    friend ostream &operator<<(ostream &os, Polynomial &p);
};

Polynomial Polynomial :: operator+(Polynomial &p)
{
    int i, j, k;
    Polynomial *sum = new Polynomial(n+p.n);

    i=j=k=0;
    while(i<n && j<p.n)
    {
        if(poly[i].exp>p.poly[j].exp)
        {
            sum->poly[k] = poly[i];
            k++;
            i++;
        }
        else if(poly[i].exp<p.poly[j].exp)
        {
            sum->poly[k] = p.poly[j];
            k++;
            j++;
        }
        else
        {
            sum->poly[k] = poly[i];
            sum->poly[k].coeff = poly[i].coeff + p.poly[j].coeff;
            k++;
            i++;
            j++;
        }
    }
    for(;i<n;i++) sum->poly[k++] = poly[i];
    for(;j<p.n;j++) sum->poly[k++] = poly[j];
    sum->n = k;
    return *sum;
}

istream &operator>>(istream &is, Polynomial &p)
{
    cout<<"\nEnter Polynomial: "<<endl;
    for(int i=0; i<p.n; i++)
    {
        cin>>p.poly[i].coeff>>p.poly[i].exp;
    }
    return is;
}

ostream &operator<<(ostream &os, Polynomial &p)
{
    for(int i=0; i<p.n; i++)
    {
        cout<<p.poly[i].coeff<<"x"<<p.poly[i].exp<<" + ";
    }
    return os;
}

int main()
{
    Polynomial P1(3);
    Polynomial P2(3);
    cin>>P1;
    cin>>P2;
    Polynomial sum = P1+P2;
    cout<<"\nPolynomial 1 is: "<<endl<<P1;
    cout<<"\nPolynomial 2 is: "<<endl<<P2;
    cout<<"\nSum is: " <<endl<<sum;
    return 0;
}
