#include <iostream>
#include <cstring>
#include <iomanip>
#include <cstdlib>
#include "Truck.h"

using namespace std;

Truck::Truck(char* _make, char* _model, char* _color, int _year, int _mileage, int _sizeTruck) : Vehicle(_make, _model, _color, _year, _mileage)
{
    sizeTruck = _sizeTruck;
}
Truck::~Truck()
{

}
Truck::Truck(const Truck& t) : Vehicle(t)
{
    sizeTruck = t.sizeTruck;
}
Truck& Truck::operator=(const Truck& other)
{
    if(this != &other)
    {
        Vehicle::operator=(other);
        sizeTruck = other.sizeTruck;
    }
    return *this;
}
int Truck::getSizeTruck() const
{
    return sizeTruck;
}
void Truck::setSizeTruck(int _sizeTruck)
{
    sizeTruck = _sizeTruck;
}
void Truck::read()
{
    cin.ignore();
    Vehicle::read();
    cout<<"Type the size of the truck: ";
    cin>>sizeTruck;
}
void Truck::print() const
{
    Vehicle::print();
    cout<<"The size of the truck: "<<sizeTruck<<endl;
}
void Truck::details() const
{
    Vehicle::details();
    cout<<"The make of the truck: "<<getMake()<<endl;
    cout<<"The model of the truck: "<<getModel()<<endl;
    cout<<"The color of the truck: "<<getColor()<<endl;
    cout<<"The year of the truck: "<<getYear()<<endl;
    cout<<"The mileage of the truck: "<<getMileage()<<endl;
    cout<<"The size of the truck: "<<sizeTruck<<endl;
}
