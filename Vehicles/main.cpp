#include <iostream>
#include <cstring>
#include <iomanip>
#include <cstdlib>
#include "Car.h"
#include "Truck.h"
#include "Motorcycle.h"

using namespace std;

int main()
{
    Vehicle v;
    v.read();
    cout<<endl;
    v.print();
    cout<<endl;
    Vehicle vehicleForCheck;
    vehicleForCheck.setMake("bmw");
    vehicleForCheck.setModel("x6");
    vehicleForCheck.setColor("black");
    vehicleForCheck.setYear(2010);
    vehicleForCheck.setMileage(200000);
    vehicleForCheck.print();
    cout<<endl;
    Car c;
    c.read();
    cout<<endl;
    //c.print();
    c.details();
    cout<<endl;
    Truck t;
    t.read();
    cout<<endl;
    //t.print();
    t.details();
    cout<<endl;
    Motorcycle m;
    m.read();
    cout<<endl;
    //m.print();
    m.details();
    return 0;
}
