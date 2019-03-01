#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include "Customer.h"

using namespace std;

Customer::Customer(int _id, string _name, string _address)
{
    id = _id;
    name = _name;
    address = _address;
}
int Customer::getId() const
{
    return id;
}
string Customer::getName() const
{
    return name;
}
string Customer::getAddress() const
{
    return address;
}
void Customer::setId(int _id)
{
    id = _id;
}
void Customer::setName(string _name)
{
    name = _name;
}
void Customer::setAddress(string _address)
{
    address = _address;
}
void Customer::read()
{
    cout<<"Type the id of the customer: ";
    cin>>id;
    cout<<"Type the name of the customer: ";
    cin>>name;
    cout<<"Type the address of the customer: ";
    cin>>address;
}
void Customer::display() const
{
    cout<<"The id of the customer: "<<id<<endl;
    cout<<"The name of the customer: "<<name<<endl;
    cout<<"The address of the customer: "<<address<<endl;
}
