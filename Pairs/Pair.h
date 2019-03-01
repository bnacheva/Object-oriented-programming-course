#ifndef PAIR_H_INCLUDED
#define PAIR_H_INCLUDED

#include <iostream>
#include <cstring>
#include <iomanip>
#include <cstdlib>

#pragma once

using namespace std;

const int MAX_SIZE = 300;

template <class T>
class Pair
{
public:
    Pair(char* = "");
    ~Pair();
    Pair(const Pair<T>&);
    Pair<T>& operator=(const Pair<T>&);
    char* getKey() const;
    T getValue() const;
    void setKey(char*);
    void setValue(T);
    void read();
    void print() const;
private:
    char* key;
    T value;
};

#endif // PAIR_H_INCLUDED
