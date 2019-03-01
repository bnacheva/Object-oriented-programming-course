#include <iostream>
#include <cstring>
#include <iomanip>
#include <cstdlib>
#include "Pair.h"

using namespace std;

template <class T>
Pair<T>::Pair(char* _key)
{
    key = new char[strlen(_key) + 1];
    if(!key)
    {
        cerr<<"Error!"<<endl;
        exit(1);
    }
    strcpy(key, _key);
}
template <class T>
Pair<T>::~Pair()
{
    delete [] key;
}
template <class T>
Pair<T>::Pair(const Pair<T>& p)
{
    key = new char[strlen(p.key) + 1];
    if(!key)
    {
        cerr<<"Error!"<<endl;
        exit(1);
    }
    strcpy(key, p.key);
    value = p.value;
}
template <class T>
Pair<T>& Pair<T>::operator=(const Pair<T>& other)
{
    if(this != &other)
    {
        delete []key;
        key = new char[strlen(other.key) + 1];
        if(!key)
        {
            cerr<<"Error!"<<endl;
            exit(1);
        }
        strcpy(key, other.key);
        value = other.value;
    }
    return *this;
}
template <class T>
char* Pair<T>::getKey() const
{
    return key;
}
template <class T>
T Pair<T>::getValue() const
{
    return value;
}
template <class T>
void Pair<T>::setKey(char* _key)
{
    delete [] key;
    key = new char[strlen(_key) + 1];
    if(!key)
    {
        cerr<<"Error!"<<endl;
        exit(1);
    }
    strcpy(key, _key);
}
template <class T>
void Pair<T>::setValue(T _value)
{
    value = _value;
}
template <class T>
void Pair<T>::read()
{
    cout<<"Create pair: "<<endl;
    key = new char[MAX_SIZE];
    cout<<"Type the key of the pair: ";
    cin.getline(key, MAX_SIZE);
    cout<<"Type the value of the pair: ";
    cin>>value;
}
template <class T>
void Pair<T>::print() const
{
    cout<<"The key of the pair: "<<key<<endl;
    cout<<"The value of the pair: "<<value<<endl;
}
