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
    Stack()
    {
        a = 0;
    }
    void push(Type n)
    {
        if(a >= MAX)
        {
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
            cout<<"No Elements"<<endl;
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
            cout<<"No Elements"<<endl;
        }
    }
};

int main()
{
    Stack<float> s1;
    s1.push(1111.1);
    s1.push(2222.2);
    s1.push(3333.3);
    cout<<"Peek: "<<s1.peek()<<endl;
    cout << "1:"<< s1.pop() << endl;
    cout << "2:"<< s1.pop() << endl;
    cout << "3:"<< s1.pop() << endl;
    Stack<long> s2;
    s2.push(123123123);
    s2.push(234234234);
    s2.push(345345345);
    cout<<"Peek: "<<s2.peek()<<endl;
    cout << "1:"<< s2.pop() << endl;
    cout << "2:"<< s2.pop() << endl;
    cout << "3:"<< s2.pop() << endl;
    return 0;
}
