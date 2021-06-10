#include<iostream>
using namespace std;
class Counter
{
private:
    int data;
    int step;
public:
    Counter():data(0),step(0)
    {
    }
    void setIncrementStep(int step_val)
    {
        step=step_val;
    }
    int getCount()
    {
        return data;
    }
    void increment()
    {
        data=data+step;
    }
    void resetCount()
    {
        data=0;
    }
};



int main()
{
    Counter n,m;
    n.setIncrementStep(3);
    n.increment();
    cout<<n.getCount()<<endl;
    n.resetCount();
    cout<<n.getCount()<<endl;
}
