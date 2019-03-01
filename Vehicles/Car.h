#ifndef CAR_H_INCLUDED
#define CAR_H_INCLUDED

#include <iostream>
#include <cstring>
#include <iomanip>
#include <cstdlib>
#include "Vehicle.h"

#pragma once

using namespace std;

class Car : public Vehicle
{
public:
    Car(char* = "", char* = "", char* = "", int = 0, int = 0);
    ~Car();
    Car(const Car&);
    Car& operator=(const Car&);
    void details() const;
    void read();
    void print() const;
};

#endif // CAR_H_INCLUDED
