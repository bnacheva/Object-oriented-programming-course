#include <iostream>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <stdlib.h>
#include <cstring>
#include "zad3.h"
using namespace std;
bool isValid(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        if(arr[i] != arr[i+1])
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}
int main()
{
    Store store(2); // firstly, we add only two products
    char symbol;
    do
    {
        cout<<"\n\n\t\tMENU:";
        cout<<"\n\n\t\t A";
        cout<<"\n\n\t\t X";
        cout<<"\n\n\t\t C";
        cout<<"\n\n\t\t D";
        cout<<"\n\n\t\t Q";
        cout<<"\n\n\t\t Your choice is: ";
        cin>>symbol;
        system("cls");
        switch (symbol)
        {
            case 'A':
                {
                    Product product;
                    int skuForCheck[100];
                    for(int i = 1; i <= 2; i++)
                    {
                        cout<<"Create product and add it to the store: "<<endl;
                        cin>>product;
                        skuForCheck[i-1] = product.getSKU();
                        cout<<"Check what you have just created: "<<endl;
                        cout<<product;
                        store.addPr(product);
                    }
                    if(isValid(skuForCheck, 2) == false)
                    {
                        cout<<"Major error! You should type only unique SKU!"<<endl;
                        exit(1);
                    }
                }
                break;

            case'X':
                {
                    store.removePr();
                }
                break;

            case'C':
                {
                    store.changePr();
                }
                break;

            case'D':
                {
                    store.display();
                }
                break;
        }
        system("pause");
        system("cls");
    }
    while (symbol != 'Q');

    return 0;
}
