#include <bits/stdc++.h>
using namespace std;
class Product
{
private:
    double discountPercent, unitPrice;
    char name[100];

public:
    Product() : unitPrice(10), discountPercent(.5) {}
    void assignName(char nameInsert[])
    {
        strcpy(name, nameInsert);
    }
    void setPrice(double price)
    {
        unitPrice = price;
    }
    void setDiscPercent(double percent)
    {
        if(percent<=10 && percent>=0)
        {
            discountPercent = percent;
        }
        else
        {
            cout<<"DiscountPercent needs to be within 0-10%"<<endl;
        }
    }
    double getSellingPrice(int nos)
    {
        double n;
        n= (1 - discountPercent / 100) * nos;
        return (unitPrice * n);
    }
    void display()
    {
        cout << name << " has a unit price BDT " << unitPrice << ". Current discount " << discountPercent << "%." << endl;
    }
};

int main()
{
    char name[] = "Star Ship";
    Product starShip;
    starShip.assignName(name);
    starShip.setPrice(30);
    starShip.setDiscPercent(15);
    starShip.setDiscPercent(5);
    cout << "Price:" << starShip.getSellingPrice(12) << endl;
    starShip.display();
}
