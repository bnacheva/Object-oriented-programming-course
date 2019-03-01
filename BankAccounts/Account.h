#ifndef ACCOUNT_H_INCLUDED
#define ACCOUNT_H_INCLUDED

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <vector>

#pragma once

using namespace std;

class Account
{
public:
    Account(string = "", int = 0, double = 0.0);
    virtual ~Account();
    virtual void deposit(double) = 0;
    virtual bool withdraw(double) = 0;
    virtual void display() const = 0;
    string getIban() const;
    int getOwnerId() const;
    double getBalance() const;
    void setIban(string);
    void setOwnerId(int);
    void setAmount(double);
	virtual Account* clone() const = 0;
protected:
    string iban;
    int ownerId;
    double amount;
};

#endif // ACCOUNT_H_INCLUDED
