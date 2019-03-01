#ifndef CURRENTACCOUNT_H_INCLUDED
#define CURRENTACCOUNT_H_INCLUDED

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <vector>
#include "Account.h"

#pragma once

using namespace std;

class CurrentAccount : public Account
{
public:
    CurrentAccount(string = "", int = 0, double = 0.0);
    void deposit(double);
    bool withdraw(double);
    void display() const;
    const string typeAccount = "current account";
	Account* clone() const;
};

#endif // CURRENTACCOUNT_H_INCLUDED
