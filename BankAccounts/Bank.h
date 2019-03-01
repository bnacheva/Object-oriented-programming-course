#ifndef BANK_H_INCLUDED
#define BANK_H_INCLUDED

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include <string>
#include "Customer.h"
#include "CurrentAccount.h"
#include "SavingsAccount.h"
#include "PrivilegeAccount.h"

#pragma once

using namespace std;

class Bank
{
public:
    Bank();
    Bank(string _nameBank, string _addressBank, vector<Customer> _customers, vector<Account*> _accounts);
    ~Bank();
    Bank(const Bank&);
    Bank& operator=(const Bank&);
    string getNameBank() const;
    string getAddressBank() const;
    void setNameBank(string);
    void setAddressBank(string);
    void addCustomer(int customerId, string name, string address);
    void listCustomers() const;
    void deleteCustomer(int customerId);
    void addAccount(const string accountType, string iban, int ownerId, double amount);
    void listAccounts() const;
    void deleteAccount(string iban);
    void listCustomerAccount(int customerId) const;
    void transfer(string fromIBAN, string toIBAN, double amount);
    void display() const;
    int getNumberOfCustomers() const;
    int getNumberOfAccounts() const;
    void withdraw(string iban, double sum);
    void deposit(string iban, double sum);
private:
    string nameBank;
    string addressBank;
    vector<Customer> customers;
    vector<Account*> accounts;
};

#endif // BANK_H_INCLUDED
