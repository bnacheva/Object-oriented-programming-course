#ifndef PRIVILEGEACCOUNT_H_INCLUDED
#define PRIVILEGEACCOUNT_H_INCLUDED

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <vector>
#include "Account.h"

#pragma once

using namespace std;

class PrivilegeAccount : public Account
{
public:
    PrivilegeAccount(string _iban, int _ownerId, double _amount, double _overdraft);
    double getOverdraft() const;
    void setOverdraft(double);
    void deposit(double);
    bool withdraw(double);
    void display() const;
    const string typeAccount = "privilege account";
	Account* clone() const;
private:
    double overdraft;
};

#endif // PRIVILEGEACCOUNT_H_INCLUDED
