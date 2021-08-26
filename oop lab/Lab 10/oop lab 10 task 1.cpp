#include<bits/stdc++.h>
using namespace std;
class Books
{
private:
    string name;
public:
//    virtual void getinfo(){               // virtual function
//    cout<<"I'm a Book item ."<<endl;
//    }
    virtual void getinfo()=0;    //pure virtual function
};

class Physics:public Books
{
private:
    string book_name;
public:
    void getinfo()
    {
        cout<<"I'm a Physics Book ."<<endl;
    }
};

class Chemistry:public Books
{
private:
    string book_name;
public:
    void getinfo()
    {
        cout<<"I'm a Chemistry Book ."<<endl;
    }
};

class Maths:public Books
{
private:
    string book_name;
public:
    void getinfo()
    {
        cout<<"I'm a Maths Book ."<<endl;
    }
};
int main()
{
    Books* e[4];

    for(int i=0; i<=3; i++)
    {
        e[i]=nullptr;
    }

    e[0]=new Physics;
    e[1]=new Chemistry;
    e[2]=new Maths;
  //e[3]=new electronics; // Error: because of virtual function . abstract base class .

    e[0]->getinfo();
    e[1]->getinfo();
    e[2]->getinfo();
  //e[3]->getinfo();

    for(int i=0; i<=3; i++)
    {
        delete e[i];
    }

}




