#include<bits/stdc++.h>
using namespace std;

class BankAccount
{
private:
    int accnumber;
    string accusername;
    string acctype;
    double currbalance;
    double minbalance;

public:
    static int count;
    BankAccount()
    {
        cout<<"Holder: ";
        cin>>accusername;
        cout<<"Account Type:";
        cin>>acctype;
        cout<<"Balance:";
        cin>>currbalance;
        cout<<"Min Balance:";
        cin>>minbalance;
        accnumber=count++;

    }
    void deposit(double i)
    {
        currbalance=currbalance+i;
    }
    void withdraww(double _j)
    {
        if (_j <= 0)
        {
             cout << "Cannot be negative" << endl;
        }
        else if ((currbalance - _j) < minbalance)
        {
            cout << "Must keep a minimum balance" << endl;
        }
        else
        {
            currbalance -= _j;
        }

    }
    double showBalance()
    {
        cout<<currbalance<<endl;
    }
    double giveInterest(double rate=2.5)
    {
        double interest = currbalance*rate/100.0;
        deposit(interest*0.9);
    }
    ~BankAccount()
    {
         cout << "Account of " << accusername << " with account no " << accnumber << " is destroyed with a balance BDT " << currbalance << endl;
    }
};

int BankAccount::count=1;

int main()
{
    BankAccount a;
    a.showBalance();
    a.deposit(-10.0);
    a.deposit(10.0);
    a.showBalance();
    a.withdraww(-20);
    a.withdraww(20);
    a.withdraww(30);
    a.showBalance();
    a.giveInterest();
    a.showBalance();
    return 0;
}
