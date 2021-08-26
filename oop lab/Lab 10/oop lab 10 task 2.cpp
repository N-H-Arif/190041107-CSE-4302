#include<bits/stdc++.h>
using namespace std;
class Biology
{
private:
    int data;
    //  Biology(Biologys&);  //  private restricts its access
    //  Biology& operator = (Biology&);

public:
    Biology()
    {
    }
    Biology(int a):data(a)
    {
    }
    Biology(Biology& m)
    {
        data=m.data;
        cout<<"Copy Constructor Called"<<endl;
    }
    void display()
    {
        cout<<data<<endl;
    }
    void operator = (Biology& m)
    {
        data=m.data;
        cout<<"Assignment Operator Called"<<endl;
    }
};
int main()
{
    Biology r;

    Biology m1(38);
    Biology m2(r);
    m2=m1;

    cout<<"Value of M2 : ";
    m2.display();
    cout<<endl;

    Biology m3(m1);
    cout<<"Value of M3 : ";
    m3.display();
    cout<<endl;

    Biology m4=m1;
    cout<<"Value of M4 : ";
    m4.display();
    cout<<endl;
}
