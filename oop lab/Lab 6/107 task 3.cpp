#include <bits/stdc++.h>
using namespace std;

class ZooAnimal
{
private:
    char nameOfAnimal[80];
    int birthyear;
    int cageNumber;
    float weightData;
    int height;

public:
    ZooAnimal() : birthyear(2021), cageNumber(0), weightData(0.0), height(0){strcpy(nameOfAnimal, "");}
    void set_name(char *nameee)
    {
        strcpy(nameOfAnimal,nameee);
    }
    void set_birth(int birth)
    {
        birthyear = birth;
    }
    void set_cageNum(int cageee)
    {
        cageNumber = cageee;
    }
    void set_weight(float w)
    {
        weightData = w;
    }
    void set_height(int h)
    {
        height = h;
    }
    char *get_name()
    {
        return nameOfAnimal;
    }
    int get_birthyear()
    {
        return birthyear;
    }
    int get_cagenumber()
    {
        return cageNumber;
    }
    float get_weight()
    {
        return weightData;
    }
    int get_height()
    {
        return height;
    }
    int get_age()
    {
        return 2021 - birthyear;
    }
    void getInformation()
    {

        cout << "Name: " << nameOfAnimal << endl;
        cout << "Birth year: " << birthyear << endl;
        cout << "Cage Number: " << cageNumber << endl;
        cout << "Weight: " << weightData << endl;
        cout << "Height: " << height << endl;
    }
    int operator==(int data)
    {
        if (weightData == data)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    void operator--(int n)
    {
        height -= n;
    }
};
int main()
{
    ZooAnimal a, b;
    a.getInformation();
    cout << a.get_age() << endl;
    b.set_birth(2040);
    b.set_cageNum(20);
    b.set_height(15);
    b.set_name("Tiger");
    b.set_weight(924);
    b.get_birthyear();
    b.get_cagenumber();
    b.get_height();
    b.get_name();
    b.get_weight();
    b.getInformation();
    b.operator--(2);
    b.getInformation();
    return 0;
}
