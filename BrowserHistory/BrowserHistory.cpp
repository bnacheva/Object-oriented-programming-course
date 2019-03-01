#include <iostream>
#include <cstring>
#include <iomanip>
#include <cstdlib>
#include "zad2.h"

using namespace std;

int main()
{
    HistoryEntry he;
    he.create_site();
    he.print_site();
    BrowserHistory bwForSite(3);
    HistoryEntry he1, he2, he3, he4;
    he1.s = "site1";
    he1.month = 4;
    he2.s = "site2";
    he2.month = 4;
    he3.s = "site3";
    he3.month = 3;
    he4.s = "site4";
    he4.month = 2;
    he1.print_site();
    bwForSite.addSite(he1);
    he2.print_site();
    bwForSite.addSite(he2);
    he3.print_site();
    bwForSite.addSite(he3);
    he4.print_site();
    //bwForSite.addSite(he4); // this should display an error message
    bwForSite.display();
    bwForSite.removeSite();
    bwForSite.display();
    cout<<"Type the number of sites you want to add: ";
    int n;
    cin>>n;
    BrowserHistory bw;
    for(int i = 0; i < n; i++)
    {
        bw.addSite();
    }
    cout<<"Type the month you want to check for visited sites: ";
    int month;
    cin>>month;
    int counter = bwForSite.findM(month);
    cout<<"Count of sites visited this month: "<<counter<<endl;
    int counterMax = bwForSite.findMax();
    cout<<"The most visited month: "<<counterMax<<endl;
    BrowserHistory bw1(1);
    HistoryEntry he5;
    he5.month = 6;
    he5.s = "site";
    bw1.addSite(he5);
    BrowserHistory bw2(1);
    HistoryEntry he6;
    he6.month = 7;
    he6.s = "site";
    bw2.addSite(he6);
    BrowserHistory bwForConcat = concat(bw1, bw2);
    cout<<"The concatenated sites: "<<bwForConcat<<endl;
    return 0;
}
