#ifndef MOTORCYCLE_H_INCLUDED
#define MOTORCYCLE_H_INCLUDED

#include <iostream>
#include <cstring>
#include <iomanip>
#include <cstdlib>
#include "Vehicle.h"

#pragma once

using namespace std;

class Motorcycle : public Vehicle
{
public:
    Motorcycle(char* = "", char* = "", char* = "", int = 0, int = 0, char* = "");
    ~Motorcycle();
    Motorcycle(const Motorcycle&);
    Motorcycle& operator=(const Motorcycle&);
    void details() const;
    void read();
    void print() const;
    char* getType() const;
    void setType(char*);
private:
    char* type;
};

#endif // MOTORCYCLE_H_INCLUDED
