#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>
#include "zad1.h"

using namespace std;

int main()
{
    char* s = new char[100];
    cout<<"Type the RPN: ";
    cin.getline(s, 100);
    if(strlen(s) > 100)
    {
        return 0;
    }
    cout<<"The result is: ";
    calculate(s);
    return 0;
}
