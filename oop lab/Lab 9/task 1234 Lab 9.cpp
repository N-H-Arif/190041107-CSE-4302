#include <iostream>
#include <string>
using namespace std;

enum class Material {Wood,Board,Steel,foam};
class Furniture
{
protected:
    double price;
    double discount;
    Material madeof;
public:
    Furniture()
    {
    }
    Furniture(double p,double d,Material m):price(0),discount(0),madeof(Material::Wood)
    {
        setPrice(p);
        setDiscount(d);
        setMadeof(m);
    }
    void setPrice(double val)
    {
        if(val>0)
            price=val;
    }
    void setDiscount(double val)
    {
        if(val<=price)
            discount=val;
    }
    void setMadeof(Material val)
    {
        madeof=val;
    }
    void getMadeof()
    {
        if(madeof==Material::Wood)
            cout<<"Wood";
        else if(madeof==Material::Board)
            cout<<"Board";
        else if(madeof==Material::Steel)
            cout<<"Steel";
        else
            cout<<"FOam";
    }
    void getData()
    {
        cout<<"Regular Price: "<<price<<endl;
        cout<<"Discounter Price: "<<(price-discount)<<endl;
        cout<<"Material: ";
        getMadeof();
        cout<<endl;
    }
    virtual void productDetails()=0;
    int getDiscountP()
    {
        return price - discount;
    }
    ~Furniture()
    {
    }
};



enum class BedSize {Single,SemiDouble,Double};

class Bed:public Furniture
{
private:
    BedSize bdsz;
public:
    Bed()
    {
    }
    Bed(double p=0.0,double d=0.0,Material m=Material::Wood,BedSize b=BedSize::Single)
    {
        setPrice(p);
        setDiscount(d);
        setMadeof(m);
        setBedSize(b);
    }
    void setBedSize(BedSize val)
    {
        bdsz=val;
    }
    void getBedSize()
    {
        cout<<"Bed Size: ";
        if(bdsz==BedSize::Single)
            cout<<"Single";
        else if(bdsz==BedSize::SemiDouble)
            cout<<"Semi Double";
        else if(bdsz==BedSize::Double)
            cout<<"Double";
    }
    void productDetails()
    {
        cout<<"Product Type: Bed"<<endl;
        Furniture::getData();
        getBedSize();
        cout<<endl<<endl;
    }
    ~Bed()
    {
    }
};

enum class SofaSize {One, Two, Three, Four, Five};
class Sofa:public Furniture
{
private:
    SofaSize seatNo;
public:
    Sofa()
    {
    }
    Sofa(double p=0.0,double d=0.0,Material m=Material::Wood,SofaSize sn=SofaSize::One)
    {
        setPrice(p);
        setDiscount(d);
        setMadeof(m);
        setSeatNumber(sn);
    }
    void setSeatNumber(SofaSize val)
    {
        seatNo=val;
    }
    void getSeatNumber()
    {
        cout<<"Seat Number: ";
        if(seatNo==SofaSize::One)
            cout<<"One";
        else if(seatNo==SofaSize::Two)
            cout<<"Two";
        else if(seatNo==SofaSize::Three)
            cout<<"Three";
        else if(seatNo==SofaSize::Four)
            cout<<"Four";
        else if(seatNo==SofaSize::Five)
            cout<<"Five";
    }
    void productDetails()
    {
        cout<<"Product Type: Sofa"<<endl;
        Furniture::getData();
        getSeatNumber();
        cout<<endl<<endl;
    }
    ~Sofa()
    {
    }
};

enum class AlmirahDoor {Two,Three,Four};
class Almirah:public Furniture
{
private:
    AlmirahDoor alsz;
public:
    Almirah()
    {
    }
    Almirah(double p=0.0,double d=0.0,Material m=Material::Wood,AlmirahDoor a=AlmirahDoor::Two)
    {
        setPrice(p);
        setDiscount(d);
        setMadeof(m);
        setAlmirahDoor(a);
    }
    void setAlmirahDoor(AlmirahDoor val)
    {
        alsz=val;
    }
    void getAlmirahDoor()
    {
        cout<<"Almirah Door: ";
        if(alsz==AlmirahDoor::Two)
            cout<<"Two";
        else if(alsz==AlmirahDoor::Three)
            cout<<"Three";
        else if(alsz==AlmirahDoor::Four)
            cout<<"Four";
    }
    void productDetails()
    {
        cout<<"Product Type: Almirah"<<endl;
        Furniture::getData();
        getAlmirahDoor();
        cout<<endl<<endl;
    }
    ~Almirah()
    {
    }
};

void sortorder(Furniture** f1, Furniture** f2)
{
    if((*f1)->getDiscountP() < (*f2)->getDiscountP())
    {
        Furniture* temp = *f1;
        *f1 = *f2;
        *f2 = temp;
    }
}

void sort_furniture_discount(Furniture** f, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            sortorder(f + i, f + j);
        }
    }
}


int main()
{
    Furniture* f_list[100];

    f_list[0] = new Bed(10000,123,Material::Wood,BedSize::Single);
    f_list[1] = new Sofa(11000,234,Material::Steel,SofaSize::Five);
    f_list[2] = new Almirah(13000,345,Material::Wood,AlmirahDoor::Two);
    f_list[3] = new Bed(10090,123,Material::Wood,BedSize::Single);

    f_list[2]->setDiscount(30);
    for(int i=0; i<4; i++)
    {
        f_list[i]->productDetails();
    }
    sort_furniture_discount(f_list, 4);
    cout << "SORTED: " << "\n";
    for (int i = 0; i < 4; ++i)
    {
        f_list[i]->productDetails();
        cout << "\n";
    }
}
