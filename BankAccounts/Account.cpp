#include <iostream>
#include <cstring>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <vector>
#include "Account.h"

using namespace std;

Account::Account(string _iban, int _ownerId, double _amount)
{
    iban = _iban;
    ownerId = _ownerId;
    amount = _amount;
}
Account::~Account()
{

}
string Account::getIban() const
{
    return iban;
}
int Account::getOwnerId() const
{
    return ownerId;
}
double Account::getBalance() const
{
    return amount;
}
void Account::setIban(string _iban)
{
    iban = _iban;
}
void Account::setOwnerId(int _ownerId)
{
    ownerId = _ownerId;
}
void Account::setAmount(double _amount)
{
    amount = _amount;
}
