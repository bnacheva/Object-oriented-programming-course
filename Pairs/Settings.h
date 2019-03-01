#ifndef SETTINGS_H_INCLUDED
#define SETTINGS_H_INCLUDED

#include <iostream>
#include <cstring>
#include <iomanip>
#include <cstdlib>
#include "Pair.h"

#pragma once

using namespace std;

template <class T>
class Settings
{
public:
    Settings();
    Settings(int);
    ~Settings();
    Settings(const Settings<T>&);
    Settings<T>& operator=(const Settings<T>&);
    Pair<T>* getPairs() const;
    int getCount() const;
    int getCapacity() const;
    void setCount(int);
    void setCapacity(int);
    void display() const;
    T getValueByKey(char*) const;
    void setKV(char* _key, T _value);
    bool get(char* _key, T& _value);
private:
    Pair<T>* pairs;
    int counter;
    int capacity;
};

#endif // SETTINGS_H_INCLUDED
