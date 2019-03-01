#include <iostream>
#include <cstring>
#include <iomanip>
#include <cstdlib>
#include "ElectricDevice.h"

using namespace std;

ElectricDevice::ElectricDevice(char* _name, int _power)
{
    name = new char[strlen(_name) + 1];
    if(!name)
    {
        cerr<<"Error!"<<endl;
        exit(1);
    }
    strcpy(name, _name);
    power = _power;
}
ElectricDevice::~ElectricDevice()
{
    delete []name;
}
ElectricDevice::ElectricDevice(const ElectricDevice& ed)
{
    name = new char[strlen(ed.name) + 1];
    if(!name)
    {
        cerr<<"Error!"<<endl;
        exit(1);
    }
    strcpy(name, ed.name);
    power = ed.power;
}
ElectricDevice& ElectricDevice::operator=(const ElectricDevice& other)
{
    if(this != &other)
    {
        delete []name;
        name = new char[strlen(other.name) + 1];
        if(!name)
        {
            cerr<<"Error!"<<endl;
            exit(1);
        }
        strcpy(name, other.name);
        power = other.power;
    }
    return *this;
}
char* ElectricDevice::getName() const
{
    return name;
}
int ElectricDevice::getPower() const
{
    return power;
}
void ElectricDevice::setName(char* _name)
{
    delete [] name;
    name = new char[strlen(_name) + 1];
    if(!name)
    {
        cerr<<"Error!"<<endl;
        exit(1);
    }
    strcpy(name, _name);
}
void ElectricDevice::setPower(int _power)
{
    power = _power;
}
void ElectricDevice::read()
{
    cout<<"Create electric device: "<<endl;
    name = new char[MAX];
    cout<<"Type the name of the electric device: ";
    cin.getline(name, MAX);
    cout<<"Type the power of the electric device: ";
    cin>>power;
}
void ElectricDevice::print() const
{
    cout<<"The print method: "<<endl;
    cout<<"The name of the electric device: "<<name<<endl;
    cout<<"The power of the electric device: "<<power<<endl;
}
