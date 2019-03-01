#ifndef VEHICLE_H_INCLUDED
#define VEHICLE_H_INCLUDED

#include <iostream>
#include <cstring>
#include <iomanip>
#include <cstdlib>

#pragma once

using namespace std;

const int MAX_SIZE = 100;

class Vehicle
{
public:
    Vehicle(char* = "", char* = "", char* = "", int = 0, int = 0);
    ~Vehicle();
    Vehicle(const Vehicle&);
    Vehicle& operator=(const Vehicle&);
    char* getMake() const;
    char* getModel() const;
    char* getColor() const;
    int getYear() const;
    int getMileage() const;
    void setMake(char*);
    void setModel(char*);
    void setColor(char*);
    void setYear(int);
    void setMileage(int);
    void read();
    void print() const;
    virtual void details() const;
private:
    char* make;
    char* model;
    char* color;
    int year;
    int mileage;
};

#endif // VEHICLE_H_INCLUDED
