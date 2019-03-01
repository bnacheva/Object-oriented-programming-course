#include <iostream>
#include <cstring>
#include <iomanip>
#include <cstdlib>
#include "Settings.h"

using namespace std;

template <class T>
Settings<T>::Settings()
{
    counter = 0;
    capacity = 1;
    pairs = new Pair<T>[1];
}
template <class T>
Settings<T>::Settings(int _capacity)
{
    counter = 0;
    capacity = _capacity;
    pairs = new Pair<T>[_capacity];
    if(!pairs)
    {
        cerr<<"Error!"<<endl;
        exit(1);
    }
}
template <class T>
Settings<T>::~Settings()
{
    delete [] pairs;
}
template <class T>
Settings<T>::Settings(const Settings<T>& s)
{
    counter = s.counter;
    capacity = s.capacity;
    pairs = new Pair<T>[capacity];
    if(!pairs)
    {
        cerr<<"Error!"<<endl;
        exit(1);
    }
    for(int i = 0; i <= capacity - 1; i++)
    {
        pairs[i] = s.pairs[i];
    }
}
template <class T>
Settings<T>& Settings<T>::operator=(const Settings<T>& other)
{
    if(this != &other)
    {
        delete [] pairs;
        counter = other.counter;
        capacity = other.capacity;
        pairs = new Pair<T>[capacity];
        if(!pairs)
        {
            cerr<<"Error!"<<endl;
            exit(1);
        }
        for(int i = 0; i <= capacity - 1; i++)
        {
            pairs[i] = other.pairs[i];
        }
    }
    return *this;
}
template <class T>
Pair<T>* Settings<T>::getPairs() const
{
    return pairs;
}
template <class T>
int Settings<T>::getCount() const
{
    return counter;
}
template <class T>
int Settings<T>::getCapacity() const
{
    return capacity;
}
template <class T>
void Settings<T>::setCount(int _counter)
{
    counter = _counter;
}
template <class T>
void Settings<T>::setCapacity(int _capacity)
{
    capacity = _capacity;
}
template <class T>
void Settings<T>::display() const
{
    cout<<"The print method for the settings: "<<endl;
    for(int i = 0; i <= counter - 1; i++)
    {
        pairs[i].print();
    }
}
template <class T>
T Settings<T>::getValueByKey(char* _key) const
{
    for(int i = 0; i < counter; i++)
    {
        if(strcmp(pairs[i].getKey(), _key) == 0)
        {
            return pairs[i].getValue();
            break;
        }
    }
}
template <class T>
void Settings<T>::setKV(char* _key, T _value)
{
    int flag = 0;
    for(int i = 0; i < counter; i++)
    {
        if(strcmp(pairs[i].getKey(), _key) == 0)
        {
            flag = 1;
            pairs[i].setValue(_value);
            break;
        }
    }
    if(counter == capacity)
    {
        cerr << "Not enough space!";
        exit(1);
    }
    else if(flag == 0)
    {
        pairs[counter].setKey(_key);
        pairs[counter].setValue(_value);
        counter++;
        //cout<<"The pair has been successfully added!"<<endl;
    }
}
template <class T>
bool Settings<T>::get(char* _key, T& _value)
{
    int flag = 0;
    for(int i = 0; i < counter; i++)
    {
        if(strcmp(pairs[i].getKey(), _key) == 0)
        {
            _value = pairs[i].getValue();
            cout<<"The value is: "<<_value<<endl;
            flag = 1;
            break;
        }
        else
        {
            flag = 0;
        }
    }
    if(flag == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
