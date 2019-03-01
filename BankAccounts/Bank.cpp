#include <iostream>
#include <cstring>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <vector>
#include "Bank.h"

using namespace std;

Bank::Bank()
{
    nameBank = "";
    addressBank = "";
}
Bank::Bank(string _nameBank, string _addressBank, vector<Customer> _customers, vector<Account*> _accounts) : customers(_customers)
{
    nameBank = _nameBank;
    addressBank = _addressBank;
	for (auto element : _accounts)
	{
		accounts.push_back(element->clone());
	}
}
Bank::~Bank()
{
	for (auto element : accounts)
	{
		delete element;
	}
}
Bank::Bank(const Bank& b)
{
    nameBank = b.nameBank;
    addressBank = b.addressBank;
	customers = b.customers;
	for (auto element : b.accounts)
	{
		accounts.push_back(element->clone());
	}
}
Bank& Bank::operator=(const Bank& other)
{
    if(this != &other)
    {
        nameBank = other.nameBank;
        addressBank = other.addressBank;
		customers = other.customers;

		for (auto element : other.accounts)
		{
			delete element;
		}
        accounts.clear();
		for (auto element : other.accounts)
		{
			accounts.push_back(element->clone());
		}
    }
    return *this;
}
string Bank::getNameBank() const
{
    return nameBank;
}
string Bank::getAddressBank() const
{
    return addressBank;
}
void Bank::setNameBank(string _nameBank)
{
    nameBank = _nameBank;
}
void Bank::setAddressBank(string _addressBank)
{
    addressBank = _addressBank;
}
void Bank::addCustomer(int customerId, string name, string address)
{
    bool flag = 1;
    for(int i = 0; i < customers.size(); i++)
    {
        if(customers[i].getId() == customerId)
        {
            flag = 0;
            break;
        }
    }
    if(flag == 1)
    {
        customers.push_back(Customer(customerId, name, address));
        cout<<"The customer has been successfully added!"<<endl;
    }
    else
    {
        cout<<"A customer with this id already exists!"<<endl;
    }
}
void Bank::listCustomers() const
{
    cout<<"All customers in the bank: "<<endl;
    if(customers.size() <= 0)
    {
        cout<<"There are no customers in the bank!"<<endl;
    }
    for(int i = 0; i < customers.size(); i++)
    {
        customers[i].display();
    }
    cout<<endl;
}
void Bank::deleteCustomer(int customerId)
{
    int currentSize = customers.size();
    int currentSizeAcc = accounts.size();
    if(customers.size() < 0)
    {
        cout<<"There are no customers left in the bank!"<<endl;
        exit(1);
    }
    if(accounts.size() < 0)
    {
        cout<<"There are no accounts left in the bank!"<<endl;
        exit(1);
    }
    int i = 0;
    int j = 0;
    int ownerId = 0;
    while (i < customers.size())
    {
        if(customers[i].getId() == customerId)
        {
            ownerId = customers[i].getId();
            for (int j = i + 1; i < customers.size(); i++)
            {
                customers[j - 1] = customers[j];
            }
            currentSize--;
        }
        else
            i++;
    }
    if(i == customers.size())
    {
        cout<<"The customer has been removed!"<<endl;
        exit(1);
    }
    while(j < accounts.size())
    {
        if(accounts[j]->getOwnerId() == ownerId)
        {
			delete accounts[j];
            for (int z = j + 1; z < accounts.size(); z++)
            {
                accounts[z - 1] = accounts[z];
            }
            currentSizeAcc--;
        }
        else
            j++;
    }
    if(j == accounts.size())
    {
        cout<<"The customer's accounts have been removed!"<<endl;
    }
}
void Bank::addAccount(string accountType, string iban, int ownerId, double amount)
{
    if(accountType.compare("current") == 0)
    {
        bool flag1 = 1;
        bool flag2 = 0;
        for(int i = 0; i < accounts.size(); i++)
        {
            if(accounts[i]->getIban().compare(iban) == 0)
            {
                flag1 = 0;
                break;
            }
        }
        for(int i = 0; i < customers.size(); i++)
        {
            if(customers[i].getId() == ownerId)
            {
                flag2 = 1;
                break;
            }
        }
        if(flag1 == 1 && flag2 == 1)
        {
            accounts.push_back(new CurrentAccount(iban, ownerId, amount));
            cout<<"The current account has been successfully added!"<<endl;
        }
        else if(flag1 == 0)
        {
            cout<<"An account with this iban already exists in the bank!"<<endl;
        }
        else if(flag2 == 0)
        {
            cout<<"There is not a customer with this id in the bank!"<<endl;
        }
    }
    else if(accountType.compare("savings") == 0)
    {
        bool flag1 = 1;
        bool flag2 = 0;
        for(int i = 0; i < accounts.size(); i++)
        {
            if(accounts[i]->getIban().compare(iban) == 0)
            {
                flag1 = 0;
                break;
            }
        }
        for(int i = 0; i < customers.size(); i++)
        {
            if(customers[i].getId() == ownerId)
            {
                flag2 = 1;
                break;
            }
        }
        if(flag1 == 1 && flag2 == 1)
        {
            double intRate;
            cout<<"Type the interest rate: ";
            cin>>intRate;
            accounts.push_back(new SavingsAccount(iban, ownerId, amount, intRate));
            cout<<"The savings account has been successfully added!"<<endl;
        }
        else if(flag1 == 0)
        {
            cout<<"An account with this iban already exists in the bank!"<<endl;
        }
        else if(flag2 == 0)
        {
            cout<<"There is not a customer with this id in the bank!"<<endl;
        }
    }
    else if(accountType.compare("privilege") == 0)
    {
        bool flag1 = 1;
        bool flag2 = 0;
        for(int i = 0; i < accounts.size(); i++)
        {
            if(accounts[i]->getIban().compare(iban) == 0)
            {
                flag1 = 0;
                break;
            }
        }
        for(int i = 0; i < customers.size(); i++)
        {
            if(customers[i].getId() == ownerId)
            {
                flag2 = 1;
                break;
            }
        }
        if(flag1 == 1 && flag2 == 1)
        {
            double overdr;
            cout<<"Type the overdraft: ";
            cin>>overdr;
            accounts.push_back(new PrivilegeAccount(iban, ownerId, amount, overdr));
            cout<<"The privilege account has been successfully added!"<<endl;
        }
        else if(flag1 == 0)
        {
            cout<<"An account with this iban already exists in the bank!"<<endl;
        }
        else if(flag2 == 0)
        {
            cout<<"There is not a customer with this id in the bank!"<<endl;
        }
    }
    else
    {
        cout<<"There is not such type of account in the bank!"<<endl;
    }
}
void Bank::deleteAccount(string iban)
{
    int currentSize = accounts.size();
    if(currentSize < 0)
    {
        cout<<"There are no accounts left in the bank!"<<endl;
        exit(1);
    }
    int i = 0;
    while (i < currentSize)
    {
        if(accounts[i]->getIban().compare(iban) == 0)
        {
			delete accounts[i];
            for (int j = i + 1; i < accounts.size(); i++)
            {
                accounts[j - 1] = accounts[j];
            }
            currentSize--;
        }
        else
            i++;
    }
    if(i == accounts.size())
    {
        cout<<"The account has been removed!"<<endl;
    }
}
void Bank::listAccounts() const
{
    cout<<"All accounts in the bank: "<<endl;
    if(accounts.size() <= 0)
    {
        cout<<"There are no accounts in the bank!"<<endl;
    }
    for(int i = 0; i < accounts.size(); i++)
    {
        accounts[i]->display();
    }
    cout<<endl;
}
void Bank::listCustomerAccount(int customerId) const
{
    bool flag = 0;
    if(customers.size() <= 0)
    {
        cout<<"There are no customers in the bank!"<<endl;
        exit(1);
    }
    for(int i = 0; i < customers.size(); i++)
    {
        if(customers[i].getId() == customerId)
        {
            customers[i].display();
            if(accounts.size() <= 0)
            {
                cout<<"There are no accounts in the bank!"<<endl;
                exit(1);
            }
            cout<<"The customer's accounts: "<<endl;
            for(int i = 0; i < accounts.size(); i++)
            {
                if(accounts[i]->getOwnerId() == customerId)
                {
                    accounts[i]->display();
                }
            }
            flag = 1;
            break;
        }
    }
    if(flag == 0)
    {
        cout<<"There is not such customer in the bank!"<<endl;
    }
}
int Bank::getNumberOfCustomers() const
{
    int counter = 0;
    for(int i = 0; i < customers.size(); i++)
    {
        counter++;
    }
    return counter;
}
int Bank::getNumberOfAccounts() const
{
    int counter = 0;
    for(int i = 0; i < accounts.size(); i++)
    {
        counter++;
    }
    return counter;
}
void Bank::display() const
{
    cout<<"The name of the bank: "<<nameBank<<endl;
    cout<<"The address of the bank: "<<addressBank<<endl;
    cout<<endl;
    cout<<"The number of customers in the bank: "<<getNumberOfCustomers()<<endl;
    listCustomers();
    cout<<"The number of accounts in the bank: "<<getNumberOfAccounts()<<endl;
    listAccounts();
}
void Bank::withdraw(string iban, double sum)
{
    for(int i = 0; i < accounts.size(); i++)
    {
        if(accounts[i]->getIban().compare(iban) == 0)
        {
            if(accounts[i]->withdraw(sum) == true)
            {
                cout<<"The amount of money has been withdrawn from the account!"<<endl;
            }
            else
            {
                cout<<"You cannot withdraw so much money! See the limit in your account first!"<<endl;
            }
            break;
        }
    }
}
void Bank::deposit(string iban, double sum)
{
    for(int i = 0; i < accounts.size(); i++)
    {
        if(accounts[i]->getIban().compare(iban) == 0)
        {
            accounts[i]->deposit(sum);
            cout<<"You make the deposit!"<<endl;
            break;
        }
        else
        {
            cout<<"There is not such account in the bank!"<<endl;
            break;
        }
    }
}
void Bank::transfer(string fromIBAN, string toIBAN, double amount)
{
    for(int i = 0; i < accounts.size(); i++)
    {
        if(accounts[i]->getIban().compare(fromIBAN) == 0)
        {
            if(accounts[i]->withdraw(amount) == true)
            {
                cout<<"The amount of money has been withdrawn from the account!"<<endl;
            }
            else
            {
                cout<<"You cannot withdraw so much money! See the limit in your account first!"<<endl;
                exit(1);
            }
            break;
        }
        else
        {
            cout<<"There is not such account in the bank!"<<endl;
            break;
        }
    }
    for(int i = 0; i < accounts.size(); i++)
    {
        if(accounts[i]->getIban().compare(toIBAN) == 0)
        {
            accounts[i]->deposit(amount);
            cout<<"You make the transfer!"<<endl;
            break;
        }
        else
        {
            cout<<"There is not such account in the bank!"<<endl;
            exit(1);
        }
    }
}
