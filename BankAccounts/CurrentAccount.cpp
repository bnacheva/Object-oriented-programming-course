#include <iostream>
#include <cstring>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <vector>
#include "CurrentAccount.h"

using namespace std;

CurrentAccount::CurrentAccount(string _iban, int _ownerId, double _amount) : Account(_iban, _ownerId, _amount)
{

}
void CurrentAccount::deposit(double sum)
{
    double amnt = getBalance();
    amnt += sum;
    setAmount(amnt);
}
bool CurrentAccount::withdraw(double sum)
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
void CurrentAccount::display() const
{
    cout<<"The type of the account: "<<typeAccount<<endl;
    cout<<"The IBAN: "<<iban<<endl;
    cout<<"The owner id: "<<ownerId<<endl;
    cout<<"The balance: "<<amount<<endl;
}

Account* CurrentAccount::clone() const
{
	Account* result = new CurrentAccount(*this);
	return result;
}
