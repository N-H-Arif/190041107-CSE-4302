#include<iostream>
using namespace std;
class RationalNumber
{
private:
    int numerator;
    int denominator;
public:
    RationalNumber():numerator(0),denominator(1)
    {
    }
    void assign(int up,int down)
    {
        if(down==0)
        {
            cout<<"Invalid"<<endl;
            return;
        }
        numerator=up;
        denominator=down;
    }
    double convert()
    {
        return (double)numerator/(double)denominator;
    }
    void invert()
    {
        if(numerator==0)
        {
            cout<<"Invalid Denominator Cannot be Zero"<<endl;
            return;
        }
        swap(numerator,denominator);
    }
    void print()
    {
        cout<<"The Rational Number is ";
        if(numerator==0)
        {
            cout<<"0"<<endl;
        }
        else
        {
            cout<<numerator<<"/"<<denominator<<endl;
        }
    }
};
int main()
{
    RationalNumber num;
    num.assign(3,2);
    num.print();
    num.invert();
    num.print();
    cout<<num.convert()<<endl;
    num.invert();
    cout<<num.convert()<<endl;
    num.assign(0,5);
    cout<<num.convert()<<endl;
    num.invert();
    num.print();
}
