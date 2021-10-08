#include<iostream>
#include<typeinfo>
#include<process.h>
#include<fstream>

using namespace std;

const int MAX=99;

enum footballer_type { egoalkeeper, estriker} ;

class footballer
{
private:
    int jersey_code;
    string name;
    static int n;
    static footballer* arrst[];
public:
    virtual void set_info()
    {
        cout<<"Enter Jersey Code: ";
        cin>>jersey_code;
        cout<<"Enter Name: ";
        cin>>name;
    }
    virtual void get_info()
    {
        cout<<"Name: "<<name<<endl;
        cout<<"Code: "<<jersey_code<<endl;
    }
    virtual footballer_type get_type();
    static void add();
    static void display();
    static void read();
    static void write();
};

int footballer::n;
footballer* footballer::arrst[MAX];

class Goalkeeper:public footballer
{
private:
    string haircolor;
    string jerseysize;
public:
    void set_info()
    {
        footballer::set_info();
        cout<<"Enter Hair Color: ";
        cin>>haircolor;
        cout<<"Enter Jersey Size: ";
        cin>>jerseysize;
    }
    void get_info()
    {
        footballer::get_info();
        cout<<"Hair Color: "<<haircolor<<endl;
        cout<<"Jersey Size: "<<jerseysize<<endl;
    }
};

class Striker:public footballer
{
private:
    string Goals;
public:
    void set_info()
    {
        footballer::set_info();
        cout<<"Enter Goal number: ";
        cin>>Goals;
    }
    void get_info()
    {
        footballer::get_info();
        cout<<"Grade: "<<Goals<<endl;
    }

};

void footballer::add()
{
    int i;
    cout<<"1: Add a Striker"<<endl;
    cout<<"2: Add a Goalkeeper"<<endl;
    cout<<"Enter Choice: ";
    cin>>i;
    switch(i)
    {
    case 1:
        arrst[n]=new Striker;
        break;
    case 2:
        arrst[n]=new Goalkeeper;
        break;
    default:
        cout<<"Error in Input"<<endl;
    }
    arrst[n++]->set_info();
}

void footballer::display()
{
    for(int j=0; j<n; j++)
    {
        cout<<"Footballer No: "<<(j+1)<<endl;
        switch(arrst[j]->get_type())
        {
        case estriker:
            cout<<"footballer Type : Striker"<<endl;
            break;
        case egoalkeeper:
            cout<<"footballer Type : Goalkeeper"<<endl;
            break;
        default:
            cout<<"Error Occurred"<<endl;
        }
        arrst[j]->get_info();
    }
}

footballer_type footballer::get_type()
{
    if(typeid(*this)==typeid(Goalkeeper))
    {
        return egoalkeeper;
    }
    else if(typeid(*this)==typeid(Striker))
    {
        return estriker;
    }
    else
    {
        cerr<<"\nWrong footballer Type"<<endl;
        exit(1);
    }
    return egoalkeeper;
}

void footballer::write()
{
    int sizee;
    cout << "Writing " << n << " footballers"<<endl;
    ofstream ouf; //open ofstream in binary
    footballer_type stype; //type of each footballer object
    ouf.open("footballer.DAT", ios::trunc | ios::binary );
    if(!ouf)
    {
        cout<<"\nCan't open file"<<endl;
        return;
    }
    for(int j=0; j<n; j++) //for every footballer object
    {
        //get its type
        stype = arrst[j]->get_type();
        //write type to file
        ouf.write( (char*)&stype, sizeof(stype) );
        switch(stype) //find its size
        {
        case egoalkeeper:
            sizee=sizeof(Goalkeeper);
            break;
        case estriker:
            sizee=sizeof(Striker);
            break;
        } //write footballer object to file
        ouf.write( (char*)(arrst[j]), sizee );
        if(!ouf)
        {
            cout << "\nCan't write to file"<<endl;
            return;
        }
    }
}

//read data for all footballers from file into memory
void footballer::read()
{
    int sizee; //size of footballer object
    footballer_type stype; //type of footballer
    ifstream inf; //open ifstream in binary
    inf.open("footballer.DAT", ios::binary);
    if(!inf)
    {
        cout << "\nCan't open file"<<endl;
        return;
    }
    n = 0; //no footballers in memory yet
    while(1)
    {
        //read type of next footballer
        inf.read( (char*)&stype, sizeof(stype) );
        if( inf.eof() ) //quit loop on eof
            break;
        if(!inf) //error reading type
        {
            cout << "\nCan't read type from file"<<endl;
            return;
        }
        switch(stype)
        {
        //make new footballer
        case egoalkeeper: //of correct type
            arrst[n] = new Goalkeeper;
            sizee=sizeof(Goalkeeper);
            break;
        case estriker:
            arrst[n] = new Striker;
            sizee=sizeof(Striker);
            break;
        default:
            cout << "\nUnknown type in file"<<endl;
            return;
        } //read data from file into it
        inf.read( (char*)arrst[n], sizee );
        if(!inf) //error but not eof
        {
            cout << "\nCan't read data from file"<<endl;
            return;
        }
        n++; //count footballer
    } //end while
    cout << "Reading " << n << " footballers"<<endl;
}

int main()
{
    int input;
    while(1)
    {
        cout <<"\nPress 1 to add data for an footballer"<<endl;
        cout<<"Press 2 to display data for all footballers"<<endl;
        cout<<"Press 3 write all footballer data to file"<<endl;
        cout<<"Press 4 read all footballer data from file"<<endl;
        cout<<"Press 5 to exit"<<endl;
        cout<<"\nEnter selection: ";

        cin >> input;
        switch(input)
        {
        case 1: //add an footballer to list
            footballer::add();
            break;
        case 2: //display all employees
            footballer::display();
            break;
        case 3: //write employees to file
            footballer::write();
            break;
        case 4: //read all employees from file
            footballer::read();
            break;
        case 5:
            exit(0); //exit program
        default:
            cout << "\nUnknown command";
        } //end switch
    } //end while
    return 0;


}
