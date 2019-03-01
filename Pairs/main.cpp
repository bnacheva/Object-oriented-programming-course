#include <iostream>
#include <cstring>
#include <iomanip>
#include <cstdlib>
#include "Pair.h"
#include "Pair.cpp"
#include "Settings.h"
#include "Settings.cpp"

using namespace std;

int main()
{
    Pair<int> p;
    p.read();
    cout<<endl;
    p.print();
    cout<<endl;
    Pair<double> pd;
    pd.setKey("new");
    pd.setValue(12.5);
    pd.print();
    cout<<endl;
    Pair<int> pi;
    pi = p;
    pi.print();
    cout<<endl;
    Settings<int> s(3);
    cout<<"The capacity of the container is: "<<s.getCapacity()<<endl;
    cout<<"The current count of pairs in the container is: "<<s.getCount()<<endl;
    s.setKV("key1", 10);
    s.setKV("key2", 20);
    s.display();
    cout<<endl;
    cout<<"The current count of pairs in the container is: "<<s.getCount()<<endl;
    s.setKV("key2", 30);
    s.display();
    cout<<endl;
    int value = 0;
    //int value1 = s.getValueByKey("key1");
    if(s.get("key1", value) == true)
    {
        cout<<"The key has been found!"<<endl;
    }
    else
    {
        cout<<"The key has not been found!"<<endl;
    }
    cout<<endl;
    if(s.get("key3", value) == true)
    {
        cout<<"The key has been found!"<<endl;
    }
    else
    {
        cout<<"The key has not been found!"<<endl;
    }
    return 0;
}
