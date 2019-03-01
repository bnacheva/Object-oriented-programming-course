#include <iostream>
#include <cstring>
#include <iomanip>
#include <cstdlib>
#include "Vehicle.h"

using namespace std;

Vehicle::Vehicle(char* _make, char* _model, char* _color, int _year, int _mileage)
{
    make = new char[strlen(_make) + 1];
    if(!make)
    {
        cerr<<"Error!"<<endl;
        exit(1);
    }
    strcpy(make, _make);
    model = new char[strlen(_model) + 1];
    if(!model)
    {
        cerr<<"Error!"<<endl;
        exit(1);
    }
    strcpy(model, _model);
    color = new char[strlen(_color) + 1];
    if(!color)
    {
        cerr<<"Error!"<<endl;
        exit(1);
    }
    strcpy(color, _color);
    year = _year;
    mileage = _mileage;
}
Vehicle::~Vehicle()
{
    delete [] make;
    delete [] model;
    delete [] color;
}
Vehicle::Vehicle(const Vehicle& v)
{
    make = new char[strlen(v.make) + 1];
    if(!make)
    {
        cerr<<"Error!"<<endl;
        exit(1);
    }
    strcpy(make, v.make);
    model = new char[strlen(v.model) + 1];
    if(!model)
    {
        cerr<<"Error!"<<endl;
        exit(1);
    }
    strcpy(model, v.model);
    color = new char[strlen(v.color) + 1];
    if(!color)
    {
        cerr<<"Error!"<<endl;
        exit(1);
    }
    strcpy(color, v.color);
    year = v.year;
    mileage = v.mileage;
}
Vehicle& Vehicle::operator=(const Vehicle& other)
{
    if(this != &other)
    {
        delete [] make;
        delete [] model;
        delete [] color;
        make = new char[strlen(other.make) + 1];
        if(!make)
        {
            cerr<<"Error!"<<endl;
            exit(1);
        }
        strcpy(make, other.make);
        model = new char[strlen(other.model) + 1];
        if(!model)
        {
            cerr<<"Error!"<<endl;
            exit(1);
        }
        strcpy(model, other.model);
        color = new char[strlen(other.color) + 1];
        if(!color)
        {
            cerr<<"Error!"<<endl;
            exit(1);
        }
        strcpy(color, other.color);
        year = other.year;
        mileage = other.mileage;
    }
    return *this;
}
char* Vehicle::getMake() const
{
    return make;
}
char* Vehicle::getModel() const
{
    return model;
}
char* Vehicle::getColor() const
{
    return color;
}
int Vehicle::getYear() const
{
    return year;
}
int Vehicle::getMileage() const
{
    return mileage;
}
void Vehicle::setMake(char* _make)
{
    delete [] make;
    make = new char[strlen(_make) + 1];
    if(!make)
    {
        cerr<<"Error!"<<endl;
        exit(1);
    }
    strcpy(make, _make);
}
void Vehicle::setModel(char* _model)
{
    delete [] model;
    model = new char[strlen(_model) + 1];
    if(!model)
    {
        cerr<<"Error!"<<endl;
        exit(1);
    }
    strcpy(model, _model);
}
void Vehicle::setColor(char* _color)
{
    delete [] color;
    color = new char[strlen(_color) + 1];
    if(!color)
    {
        cerr<<"Error!"<<endl;
        exit(1);
    }
    strcpy(color, _color);
}
void Vehicle::setYear(int _year)
{
    year = _year;
}
void Vehicle::setMileage(int _mileage)
{
    mileage = _mileage;
}
void Vehicle::read()
{
    cout<<"Create vehicle: "<<endl;
    cout<<"Type the make of the vehicle: ";
    make = new char[MAX_SIZE];
    cin.getline(make, MAX_SIZE);
    cout<<"Type the model of the vehicle: ";
    model = new char[MAX_SIZE];
    cin.getline(model, MAX_SIZE);
    cout<<"Type the color of the vehicle: ";
    color = new char[MAX_SIZE];
    cin.getline(color, MAX_SIZE);
    cout<<"Type the year of the vehicle: ";
    cin>>year;
    cout<<"Type the mileage of the vehicle: ";
    cin>>mileage;
}
void Vehicle::print() const
{
    cout<<"The make of the vehicle: "<<make<<endl;
    cout<<"The model of the vehicle: "<<model<<endl;
    cout<<"The color of the vehicle: "<<color<<endl;
    cout<<"The year of the vehicle: "<<year<<endl;
    cout<<"The mileage of the vehicle: "<<mileage<<endl;
}
void Vehicle::details() const
{

}
