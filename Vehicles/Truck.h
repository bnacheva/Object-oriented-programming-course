#ifndef TRUCK_H_INCLUDED
#define TRUCK_H_INCLUDED

#include <iostream>
#include <cstring>
#include <iomanip>
#include <cstdlib>
#include "Vehicle.h"

#pragma once

using namespace std;

class Truck : public Vehicle
{
public:
    Truck(char* = "", char* = "", char* = "", int = 0, int = 0, int = 0);
    ~Truck();
    Truck(const Truck&);
    Truck& operator=(const Truck&);
    void details() const;
    void read();
    void print() const;
    int getSizeTruck() const;
    void setSizeTruck(int);
private:
    int sizeTruck;
};

#endif // TRUCK_H_INCLUDED
