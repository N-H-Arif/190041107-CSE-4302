#include <iostream>
using namespace std;
const int MAX = 99;
template <class Type>
class Stack
{
private:
    Type st[MAX];
    int a;
public:
    class Range
    {
    };
    /*class Max
    {

    };*/
    Stack()
    {
        a = 0;
    }
    void push(Type n)
    {
        if(a >= MAX)
        {
            //throw Max();
            cout<<"Maximum Limit Reached"<<endl;
        }
        else
        {
            st[a++] = n;
        }

    }
    Type pop()
    {
        if (a != 0)
        {
            return st[--a];
        }
        else
        {
            throw Range();
        }
    }
    Type peek()
    {
        if (a != 0)
        {
            return st[0];
        }
        else
        {
            //throw Range();
            cout<<"No Elements"<<endl;
        }
    }
};

int main()
{
    Stack<float> s1;
    Stack<long> s2;
    try
    {
        cout << s1.pop() << endl;
    }
    catch(Stack<float>::Range)
    {
        cout << "Exception: Float Stack Empty" << endl;
    }
    /*catch(Stack<float>::Max)
    {
        cout << "Exception: Float Stack Full" << endl;
    }*/
    try
    {
        cout << s2.pop() << endl;
    }
    catch(Stack<long>::Range)
    {
        cout << "Exception: Long Stack Empty" << endl;
    }
    /*catch(Stack<long>::Max)
    {
        cout << "Exception: Long Stack Full" << endl;
    }*/
    return 0;
}

