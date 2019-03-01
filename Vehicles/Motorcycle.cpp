#include <iostream>
#include <cstring>
#include <iomanip>
#include <cstdlib>
#include "Motorcycle.h"

using namespace std;

Motorcycle::Motorcycle(char* _make, char* _model, char* _color, int _year, int _mileage, char* _type) : Vehicle(_make, _model, _color, _year, _mileage)
{
    type = new char[strlen(_type) + 1];
    if(!type)
    {
        cerr<<"Error!"<<endl;
        exit(1);
    }
    strcpy(type, _type);
}
Motorcycle::~Motorcycle()
{
    delete [] type;
}
Motorcycle::Motorcycle(const Motorcycle& m) : Vehicle(m)
{
    type = new char[strlen(m.type) + 1];
    if(!type)
    {
        cerr<<"Error!"<<endl;
        exit(1);
    }
    strcpy(type, m.type);
}
Motorcycle& Motorcycle::operator=(const Motorcycle& other)
{
    if(this != &other)
    {
        Vehicle::operator=(other);
        delete [] type;
        type = new char[strlen(other.type) + 1];
        if(!type)
        {
            cerr<<"Error!"<<endl;
            exit(1);
        }
        strcpy(type, other.type);
    }
    return *this;
}
char* Motorcycle::getType() const
{
    return type;
}
void Motorcycle::setType(char* _type)
{
    delete [] type;
    type = new char[strlen(_type) + 1];
    if(!type)
    {
        cerr<<"Error!"<<endl;
        exit(1);
    }
    strcpy(type, _type);
}
void Motorcycle::read()
{
    cin.ignore();
    Vehicle::read();
    cin.ignore();
    cout<<"Type the type of the motorcycle: ";
    type = new char[MAX_SIZE];
    cin.getline(type, MAX_SIZE);
}
void Motorcycle::print() const
{
    Vehicle::print();
    cout<<"The type of the motorcycle: "<<type<<endl;
}
void Motorcycle::details() const
{
    Vehicle::details();
    cout<<"The make of the motorcycle: "<<getMake()<<endl;
    cout<<"The model of the motorcycle: "<<getModel()<<endl;
    cout<<"The color of the motorcycle: "<<getColor()<<endl;
    cout<<"The year of the motorcycle: "<<getYear()<<endl;
    cout<<"The mileage of the motorcycle: "<<getMileage()<<endl;
    cout<<"The type of the motorcycle: "<<type<<endl;
}
