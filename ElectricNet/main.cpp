#include <iostream>
#include <cstring>
#include <iomanip>
#include <cstdlib>
#include "ElectricNet.h"
using namespace std;

int main()
{
    ElectricDevice ed;
    ed.read();
    cout<<endl;
    ed.print();
    cout<<endl;
    ElectricDevice ed1;
    ed1.setName("new");
    ed1.setPower(1);
    ed1.print();
    cout<<endl;
    ElectricNet en(4);
    cout<<"The max power of the net is: "<<en.getMaxPower()<<endl;
    en.setCapacity(2);
    cout<<"The capacity of the net is: "<<en.getCapacity()<<endl;
    if(en.operator!() == true)
    {
        cout<<"There are some devices in the net!"<<endl;
    }
    else
    {
        cout<<"There are no devices in the net!"<<endl;
    }
    cout<<endl;
    en.operator+=(ed);
    en.operator+=(ed1);
    cout<<endl;
    if(en.operator!() == true)
    {
        cout<<"There are some devices in the net!"<<endl;
    }
    else
    {
        cout<<"There are no devices in the net!"<<endl;
    }
    cout<<endl;
    en.display();
    cout<<endl;
    en.operator-=(ed);
    cout<<endl;
    en.display();
    cout<<endl;
    en["new"];
    cout<<endl;
    ElectricNet elnet(2); // set max power of the net
    cout<<"The max power of the net is: "<<elnet.getMaxPower()<<endl;
    elnet.setCapacity(2);
    cout<<"The capacity of the net is: ";
    cout<<elnet.getCapacity();
    cout<<endl;
    ElectricDevice ed2, ed3;
    ed2.setName("newdev1");
    ed2.setPower(1);
    ed3.setName("newdev2");
    ed3.setPower(1);
    elnet.operator+=(ed2);
    cout<<"The current power in the net is: "<<elnet.getCurrentPower()<<endl;
    elnet.operator+=(ed3);
    cout<<"The current power in the net is: "<<elnet.getCurrentPower()<<endl;
    cout<<"The current number of electric devices in the net is: ";
    cout<<elnet.getCurrent()<<endl;
    cout<<endl;
    elnet.display();
    cout<<endl;
    cout<<"The current power in the net is: ";
    cout<<elnet.getCurrentPower()<<endl;
    elnet.operator++();
    cout<<"The max power of the net is: ";
    cout<<elnet.getMaxPower();
    cout<<endl;
    elnet.operator--();
    cout<<"The max power of the net is: ";
    cout<<elnet.getMaxPower();
    cout<<endl;
    elnet.operator--();
    cout<<"The max power of the net is: ";
    cout<<elnet.getMaxPower()<<endl;
    cout<<endl;
    elnet.operator-=(ed2);
    elnet.display();
    cout<<endl;
    cout<<"The current power in the net is: "<<elnet.getCurrentPower()<<endl;
    cout<<"The current number of electric devices in the net is: ";
    cout<<elnet.getCurrent()<<endl;
    return 0;
}
