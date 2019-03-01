#ifndef SAVINGSACCOUNT_H_INCLUDED
#define SAVINGSACCOUNT_H_INCLUDED

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <vector>
#include "Account.h"

#pragma once

using namespace std;

class SavingsAccount : public Account
{
public:
    SavingsAccount(string _iban, int _ownerId, double _amount, double _interestRate);
    double getInterestRate() const;
    void setInterestRate(double);
    void deposit(double);
    bool withdraw(double);
    void display() const;
    const string typeAccount = "savings account";
	Account* clone() const;
private:
    double interestRate;
};

#endif // SAVINGSACCOUNT_H_INCLUDED
