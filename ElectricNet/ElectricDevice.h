#ifndef ELECTRICDEVICE_H_INCLUDED
#define ELECTRICDEVICE_H_INCLUDED

#include <iostream>
#include <cstring>
#include <iomanip>
#include <cstdlib>

#pragma once

using namespace std;

const int MAX = 100;

class ElectricDevice
{
public:
    ElectricDevice(char* = "", int = 0);
    ~ElectricDevice();
    ElectricDevice(const ElectricDevice&);
    ElectricDevice& operator=(const ElectricDevice&);
    char* getName() const;
    int getPower() const;
    void setName(char*);
    void setPower(int);
    void read();
    void print() const;
private:
    char* name;
    int power;
};


#endif // ELECTRICDEVICE_H_INCLUDED
