#ifndef ELECTRICNET_H_INCLUDED
#define ELECTRICNET_H_INCLUDED

#include <iostream>
#include <cstring>
#include <iomanip>
#include <cstdlib>
#include "ElectricDevice.h"

#pragma once

using namespace std;

class ElectricNet
{
public:
    ElectricNet();
    ElectricNet(int _maxPower);
    ~ElectricNet();
    ElectricNet(const ElectricNet&);
    ElectricNet& operator=(const ElectricNet&);
    int getCurrent() const;
    int getCapacity() const;
    int getMaxPower() const;
    int getCurrentPower() const;
    ElectricDevice* getElectricDevice() const;
    void setCapacity(int);
    void display() const;
    ElectricNet operator+(const ElectricDevice&); // done
    ElectricNet& operator+=(const ElectricDevice&);
    ElectricNet operator-(const ElectricDevice&); // done
    ElectricNet& operator-=(const ElectricDevice&);
    void operator[](char* _name) const; // done
    bool operator!(); // done
    void operator++(); // done
    void operator--(); // done
private:
    ElectricDevice* electricDevice;
    int current;
    int capacity;
    int maxPower;
};


#endif // ELECTRICNET_H_INCLUDED
