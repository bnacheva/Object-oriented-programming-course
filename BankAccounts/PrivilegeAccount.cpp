#include <iostream>
#include <cstring>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <vector>
#include "PrivilegeAccount.h"

using namespace std;

PrivilegeAccount::PrivilegeAccount(string _iban, int _ownerId, double _amount, double _overdraft) : Account(_iban, _ownerId, _amount)
{
    overdraft = _overdraft;
}
double PrivilegeAccount::getOverdraft() const
{
    return overdraft;
}
void PrivilegeAccount::setOverdraft(double _overdraft)
{
    overdraft = _overdraft;
}
void PrivilegeAccount::deposit(double sum)
{
    double amnt = getBalance();
    amnt += sum;
    setAmount(amnt);
}
bool PrivilegeAccount::withdraw(double sum)
{
    double amnt = getBalance();
    if(amnt + overdraft < sum)
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
void PrivilegeAccount::display() const
{
    cout<<"The type of the account: "<<typeAccount<<endl;
    cout<<"The IBAN: "<<iban<<endl;
    cout<<"The owner id: "<<ownerId<<endl;
    cout<<"The overdraft: "<<overdraft<<endl;
    cout<<"The balance: "<<amount<<endl;
}
Account* PrivilegeAccount::clone() const
{
	Account* result = new PrivilegeAccount(*this);
	return result;
}
