#include <iostream>
#include <cstring>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <vector>
#include "SavingsAccount.h"

using namespace std;

SavingsAccount::SavingsAccount(string _iban, int _ownerId, double _amount, double _interestRate) : Account(_iban, _ownerId, _amount)
{
    interestRate = _interestRate;
}
double SavingsAccount::getInterestRate() const
{
    return interestRate;
}
void SavingsAccount::setInterestRate(double _interestRate)
{
    interestRate = _interestRate;
}
void SavingsAccount::deposit(double sum)
{
    double amnt = getBalance();
    amnt += sum;
    setAmount(amnt);
}
bool SavingsAccount::withdraw(double sum)
{
    double amnt = getBalance();
    if(amnt < sum)
    {
        return false;
    }
    else
    {
        amnt -= sum;
        setAmount(amnt);
        return true;
    }
}
void SavingsAccount::display() const
{
    cout<<"The type of the account: "<<typeAccount<<endl;
    cout<<"The IBAN: "<<iban<<endl;
    cout<<"The owner id: "<<ownerId<<endl;
    cout<<"The interest rate: "<<interestRate<<endl;
    cout<<"The balance: "<<amount<<endl;
}

Account* SavingsAccount::clone() const
{
	Account* result = new SavingsAccount(*this);
	return result;
}
