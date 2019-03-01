#include <iostream>
#include <cstring>
#include <iomanip>
#include <cstdlib>
#include "Car.h"

using namespace std;

Car::Car(char* _make, char* _model, char* _color, int _year, int _mileage) : Vehicle(_make, _model, _color, _year, _mileage)
{

}
Car::~Car()
{

}
Car::Car(const Car& c) : Vehicle(c)
{

}
Car& Car::operator=(const Car& other)
{
    if(this != &other)
    {
        Vehicle::operator=(other);
    }
    return *this;
}
void Car::read()
{
    cin.ignore();
    Vehicle::read();
}
void Car::print() const
{
    Vehicle::print();
}
void Car::details() const
{
    Vehicle::details();
    cout<<"The make of the car: "<<getMake()<<endl;
    cout<<"The model of the car: "<<getModel()<<endl;
    cout<<"The color of the car: "<<getColor()<<endl;
    cout<<"The year of the car: "<<getYear()<<endl;
    cout<<"The mileage of the car: "<<getMileage()<<endl;
}
