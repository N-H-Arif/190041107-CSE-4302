#include<bits/stdc++.h>
using namespace std;

class FLOAT{
private:
   float x;
public:
   FLOAT(): x(0){}
   FLOAT(float xx): x(xx){}
   FLOAT operator +(FLOAT f1)
   {
       return FLOAT(x+f1.x);
   }
   FLOAT operator -(FLOAT f1)
   {
       return FLOAT(x-f1.x);
   }
   FLOAT operator *(FLOAT f1)
   {
       return FLOAT(x*f1.x);
   }
   FLOAT operator /(FLOAT f1)
   {
       if(f1.x==0)
       {
           cout<<"Cannot be Zero"<<endl;
           return FLOAT(x);
       }
       return FLOAT(x/f1.x);
   }
   operator int() const
   {
       return (int)x;
   }
   void display () const
   {
       cout<<x<<endl;
   }
   ~FLOAT(){}
};
int main()
{
    FLOAT f1(9.1), f2(5.3), f3(6.9), f4(8.3), f5(2.7), f6(7.6);
    f1.display();
    f4 = f1 + f2;
    f4.display();
    f4 = f1 - f3;
    f4.display();
    f4 = f1 * f2;
    f4.display();
    f4 = f2 / f3;
    f4.display();
    int i = f1;
    cout << i << endl;
    return 0;
}
