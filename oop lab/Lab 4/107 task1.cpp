#include<bits/stdc++.h>
using namespace std;

class Calculator
{
private:
    int val;
public:
    Calculator() : val(0)
    {
    }
    Calculator(int val):val(val)
    {
    }
    int getValue() const
    {
        return val;
    }
    void setValue(int _val)
    {
        val=_val;
    }
    void add(int v)
    {
        val=val+v;
    }
    void substract(int v)
    {
        val=val-v;
    }
    void multiply(int v)
    {
        val=val*v;
    }
    void divideBy(int v)
    {
        if(!v)
        {
            puts("Error : divide by 0 is undefined.");
        }
        else
        {
            val=val/v;
        }
    }
    void clearrr()
    {
        val=0;
    }
    void display() const
    {
        printf("Calculator display: %d\n",val);
    }
    ~Calculator()
    {
        puts("Calculator object is destroyed");
    }
};

int main()
{
    Calculator c(0);
    c.add(10);
    c.display();
    c.add(7);
    c.display();
    c.multiply(31);
    c.display();
    c.substract(42);
    c.display();
    c.divideBy(7);
    c.display();
    c.divideBy(0);
    c.display();
    c.add(3);
    c.display();
    c.substract(1);
    c.display();
    c.clearrr();
    c.display();
    return 0;
}
