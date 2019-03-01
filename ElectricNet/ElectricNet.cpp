#include <iostream>
#include <cstring>
#include <iomanip>
#include <cstdlib>
#include "ElectricNet.h"

using namespace std;

ElectricNet::ElectricNet()
{
    electricDevice = new ElectricDevice[10];
    current = 0;
    capacity = 10;
    maxPower = 0;
}
ElectricNet::ElectricNet(int _maxPower)
{
    current = 0;
    capacity = 10;
    maxPower = _maxPower;
    electricDevice = new ElectricDevice[capacity];
}
ElectricNet::~ElectricNet()
{
    delete []electricDevice;
}
ElectricNet::ElectricNet(const ElectricNet& en)
{
    current = en.current;
    capacity = en.capacity;
    maxPower = en.maxPower;
    electricDevice = new ElectricDevice[capacity];
    for(int i = 0; i <= capacity - 1; i++)
        electricDevice[i] = en.electricDevice[i];
}
ElectricNet& ElectricNet::operator=(const ElectricNet& other)
{
    if(this != &other)
		{
			delete [] electricDevice;
			current = other.current;
			capacity = other.capacity;
			maxPower = other.maxPower;
			electricDevice = new ElectricDevice[capacity];
			for(int i = 0; i <= capacity - 1; i++)
                electricDevice[i] = other.electricDevice[i];
		}
		return *this;
}
int ElectricNet::getCurrent() const
{
    return current;
}
int ElectricNet::getCapacity() const
{
    return capacity;
}
int ElectricNet::getMaxPower() const
{
    return maxPower;
}
int ElectricNet::getCurrentPower() const
{
    int currentPower = 0;
    for(int i = 0; i <= current - 1; i++)
    {
        currentPower += electricDevice[i].getPower();
    }
    return currentPower;
}

ElectricDevice* ElectricNet::getElectricDevice() const
{
    return electricDevice;
}
void ElectricNet::setCapacity(int _capacity)
{
    capacity = _capacity;
}
void ElectricNet::display()const
{
    cout<<"The print method for the electric net: "<<endl;
    for(int i = 0; i <= current - 1; i++)
    {
        electricDevice[i].print();
    }
}
ElectricNet ElectricNet::operator+(const ElectricDevice& other)
{
    ElectricNet result = *this;
    if(getCurrentPower() + other.getPower() < maxPower)
    {

        result.electricDevice[current] = other;
        result.current++;
    }
    return result;
}
ElectricNet& ElectricNet::operator+=(const ElectricDevice& other)
{
    if(current == capacity)
    {
        cerr << "Not enough space!";
        exit(1);
    }
    else if(getCurrentPower() + other.getPower() > maxPower)
    {
        cout << "Not enough space in the net!"<<endl;
        exit(1);
    }
    electricDevice[current] = other;
    current++;
    return *this;
}
ElectricNet ElectricNet::operator-(const ElectricDevice& other)
{
    ElectricNet result = *this;
    if(current < 0)
    {
        cout<<"There are no electric devices in the net!"<<endl;
        exit(1);
    }
    int i = 0;
    while(i < current)
    {
        if(strcmp(result.electricDevice[i].getName(), other.getName()) == 0)
        {
            for (int j = i + 1; i < current; i++)
            {
                result.electricDevice[j - 1] = result.electricDevice[j];
            }
            current--;
        }
        else
        {
            i++;
        }
    }
    if(i == current)
    {
        cout<<"The electric device has been removed!"<<endl;
    }
    return result;
}
ElectricNet& ElectricNet::operator-=(const ElectricDevice& other)
{
    if(current < 0)
    {
        cout<<"There are no electric devices in the net!"<<endl;
        exit(1);
    }
    int i = 0;
    while (i < current)
    {
        if(strcmp(electricDevice[i].getName(), other.getName()) == 0)
        {
            for (int j = i + 1; i < current; i++)
            {
                electricDevice[j - 1] = electricDevice[j];
            }
            current--;
        }
        else
            i++;
    }
    if(i == current)
    {
        cout<<"The electric device has been removed!"<<endl;
    }
    return *this;
}
void ElectricNet::operator[] (char* _name) const
{
    int i = 0;
    while (i < current)
    {
        if(strcmp(electricDevice[i].getName(), _name) == 0)
        {
            cout<<"The electric device is in the net!"<<endl;
            electricDevice[i].print();
            break;
        }
        else
            i++;
    }
    if(i == current)
    {
        cout<<"The electric device is not in the net!"<<endl;
    }
}
bool ElectricNet::operator!()
{
    if(current > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void ElectricNet::operator++()
{
    maxPower = maxPower * 2;
}
void ElectricNet::operator--()
{
    int currentPower = getCurrentPower();
    if(currentPower < maxPower)
    {
        maxPower = maxPower / 2;
    }
    else
    {
        cout<<"The capacity of the net cannot be decreased!"<<endl;
    }
}
