#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;

class Lab
{
private:
    string labName;
    int capacity;
public:
    Lab() : labName(""), capacity(0){}
    Lab(string labName, int capacity) : labName(labName), capacity(capacity){}
    string getLabName() const{return labName;}
    int getCapacity() const{return capacity;}
    void setLabName(string _labName){labName = _labName;}
    void setCapacity(int _capacity){capacity = _capacity;}
    void display() const{cout << "Lab " << labName << " " << capacity << " Capacity\n";}
};

class Lecturer_Room
{
private:
    string roomName;
    int roomNo;
    int capacity;
public:
    Lecturer_Room() : roomName(""), roomNo(0), capacity(0){}
    Lecturer_Room(string roomName, int roomNo, int capacity) : roomName(roomName), roomNo(roomNo), capacity(capacity){}
    string getRoomName() const{return roomName;}
    int getRoomNo() const{return roomNo;}
    int getCapacity() const{return capacity;}
    void setRoomName(string _roomName){roomName = _roomName;}
    void setCapacity(int _capacity){capacity = _capacity;}
    void setRoomNo(int _roomNo){roomNo = _roomNo;}
    void display() const{cout << roomName << " " << roomNo << " " << capacity << " Capacity\n";}
};

class N28Building
{
private:
    vector<Lab> Labs;
    vector<Lecturer_Room> Lecturer_Rooms;
public:
    N28Building()
    {
        cout<<"Welcome to N28 Building"<<endl;
    }
    void showAllLabs() const
    {
        cout<<"Show all labs:"<<endl;
        for(int i=0;i<Labs.size();i++)
        {
            Labs[i].display();
        }
        cout<<""<<endl;
    }
    void showAllLecturerRooms() const
    {
        cout<<"Show all lecturer rooms:"<<endl;
        for(int i=0;i<Lecturer_Rooms.size();i++)
        {
            Lecturer_Rooms[i].display();
        }
        cout<<""<<endl;
    }
    void addLab(string labName, int capacity)
    {
        Labs.push_back(Lab(labName, capacity));
    }
    void addLecturerRoom(string roomName, int roomNo, int capacity)
    {
        Lecturer_Rooms.push_back(Lecturer_Room(roomName, roomNo, capacity));
    }
};

int main()
{
    N28Building building;
    building.addLab("Chem", 100);
    building.addLab("Phy", 150);
    building.addLab("Comp", 100);
    building.addLecturerRoom("a", 101, 150);
    building.addLecturerRoom("b", 102, 150);
    building.addLecturerRoom("c", 103, 150);
    building.showAllLabs();
    building.showAllLecturerRooms();
}
