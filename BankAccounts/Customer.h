#ifndef CUSTOMER_H_INCLUDED
#define CUSTOMER_H_INCLUDED

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <vector>

#pragma once

using namespace std;

const int MAX = 256;

class Customer
{
public:
    Customer(int = 0, string = "", string = "");
    int getId() const;
    string getName() const;
    string getAddress() const;
    void setId(int);
    void setName(string);
    void setAddress(string);
    void read();
    void display() const;
private:
    int id;
    string name;
    string address;
};

#endif // CUSTOMER_H_INCLUDED
