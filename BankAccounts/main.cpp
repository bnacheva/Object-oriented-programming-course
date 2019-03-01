#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include "Bank.h"
using namespace std;

int main()
{
    int symbol;
    Bank bank;
    do
    {
        cout<<"\n\n\t\tMENU:";
        cout<<"\n\n\t\t 1 \t List customers";
        cout<<"\n\n\t\t 2 \t Add new customer";
        cout<<"\n\n\t\t 3 \t Delete customer";
        cout<<"\n\n\t\t 4 \t List all accounts";
        cout<<"\n\n\t\t 5 \t List customer accounts";
        cout<<"\n\n\t\t 6 \t Add new account";
        cout<<"\n\n\t\t 7 \t Delete account";
        cout<<"\n\n\t\t 8 \t Withdraw from account";
        cout<<"\n\n\t\t 9 \t Deposit to account";
        cout<<"\n\n\t\t 10 \t Transfer";
        cout<<"\n\n\t\t 11 \t Display info for the bank";
        cout<<"\n\n\t\t 12 \t Quit";
        cout<<"\n\n\t\t Your choice is: ";
        cin>>symbol;
        system("cls");
        switch (symbol)
        {
            case 1:
                {
                    bank.listCustomers();
                }
                break;

            case 2:
                {
                    Customer customer;
                    customer.read();
                    bank.addCustomer(customer.getId(), customer.getName(), customer.getAddress());
                }
                break;

            case 3:
                {
                    cout<<"Type the id of the customer you want to delete from the bank: ";
                    int id;
                    cin>>id;
                    bank.deleteCustomer(id);
                }
                break;

            case 4:
                {
                    bank.listAccounts();
                }
                break;
            case 5:
                {
                    int id;
                    cout<<"Type the id of the customer you want to check: ";
                    cin>>id;
                    bank.listCustomerAccount(id);
                }
                break;
            case 6:
                {
                    string type;
                    cout<<"What type of account you want to add? \nYou can choose from current, savings and privilege: ";
                    cin>>type;
                    string iban;
                    cout<<"Type the iban: ";
                    cin>>iban;
                    long ownerId;
                    cout<<"Type the owner id: ";
                    cin>>ownerId;
                    double balance;
                    cout<<"Type the balance: ";
                    cin>>balance;
                    bank.addAccount(type, iban, ownerId, balance);
                }
                break;
            case 7:
                {
                    cout<<"Type the iban of the account you want to delete from the bank: ";
                    string iban;
                    cin>>iban;
                    bank.deleteAccount(iban);
                }
                break;
            case 8:
                {
                    string iban;
                    cout<<"Type the iban of the account you want to withdraw money from: ";
                    cin>>iban;
                    double sum;
                    cout<<"Type the amount of money you want to withdraw: ";
                    cin>>sum;
                    bank.withdraw(iban, sum);
                }
                break;
            case 9:
                {
                    string iban;
                    cout<<"Type the iban of the account you want to deposit money in: ";
                    cin>>iban;
                    double sum;
                    cout<<"Type the amount of money you want to deposit: ";
                    cin>>sum;
                    bank.deposit(iban, sum);
                }
                break;
            case 10:
                {
                    string ibanf;
                    cout<<"Type the iban of the account you want to withdraw money from: ";
                    cin>>ibanf;
                    string ibant;
                    cout<<"Type the iban of the account you want to deposit money in: ";
                    cin>>ibant;
                    double sum;
                    cout<<"Type the amount of money you want to deposit: ";
                    cin>>sum;
                    bank.transfer(ibanf, ibant, sum);
                }
                break;
            case 11:
                {
                    string name;
                    cout<<"Type the name of the bank: ";
                    cin>>name;
                    string address;
                    cout<<"Type the address of the bank: ";
                    cin>>address;
                    bank.setNameBank(name);
                    bank.setAddressBank(address);
                    bank.display();
                }
                break;
        }
        system("pause");
        system("cls");
    }
    while (symbol != 12);
    return 0;
}
