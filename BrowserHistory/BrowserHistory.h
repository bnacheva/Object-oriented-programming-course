#ifndef ZAD2_H_INCLUDED
#define ZAD2_H_INCLUDED

#include <iostream>
#include <cstring>
#include <iomanip>
#include <cstdlib>

using namespace std;

const int MAX = 100;

struct HistoryEntry
{
    int month;
    char* s;

    void create_site()
    {
        cout<<"Create site: "<<endl;
        cout<<"The month: ";
        cin>>month;
        if(month < 1 || month > 12)
        {
            cerr<<"Invalid month!"<<endl;
            exit(1);
        }
        s = new char[MAX];
        cout<<"The URL is: ";
        cin.ignore();
        cin.getline(s, MAX);
    }
    void print_site()
    {
        cout<<"The print method: "<<endl;
        cout<<"The month: "<<month<<endl;
        cout<<"The URL is: "<<s<<endl;
    }
    friend ostream& operator<<(ostream& os, HistoryEntry& he)
    {
        os<<he.s;
        return os;
    }
};
class BrowserHistory
{
    public:
        BrowserHistory();
        BrowserHistory(int _capacity);
        BrowserHistory(const BrowserHistory&);
        BrowserHistory& operator=(const BrowserHistory&);
        ~BrowserHistory();
        int getCapacity();
        int getCurrent();
        HistoryEntry* getHistory();
        void addSite();
        void addSite(const HistoryEntry&);
        void display()const;
        int findM(int m);
        int findMax();
        void removeSite();
        friend BrowserHistory concat(const BrowserHistory& bw1, const BrowserHistory& bw2)
        {
            int capacityForTwo = bw1.capacity + bw2.capacity;
            BrowserHistory result(capacityForTwo);
            for (int i = 0; i < capacityForTwo; i++)
            {
                if(i < bw1.capacity)
                {
                    result.addSite(bw1.historyEntry[i]);
                }
                else
                {
                    result.addSite(bw2.historyEntry[i - bw1.capacity]);
                }
            }
            return result;
        }
        friend ostream& operator<<(ostream& os, const BrowserHistory& other) // just for the concat method
        {
            for (int i = 0; i <= other.current - 1; i++)
            {
                os<<other.historyEntry[i];
            }
            return os;
        }
    private:
        HistoryEntry* historyEntry;
        int capacity;
        int current;
};
BrowserHistory::BrowserHistory()
{
    historyEntry = new HistoryEntry[10];
    current = 0;
    capacity = 10;
}
BrowserHistory::BrowserHistory(int _capacity)
{
    current = 0;
    capacity = _capacity;
    historyEntry = new HistoryEntry[_capacity];
}
BrowserHistory::BrowserHistory(const BrowserHistory& br)
{
    current = br.current;
    capacity = br.capacity;
    historyEntry = new HistoryEntry[capacity];
    for(int i = 0; i <= capacity - 1; i++)
        historyEntry[i] = br.historyEntry[i];
}
BrowserHistory& BrowserHistory::operator=(const BrowserHistory& other)
{
    if(this!=&other)
		{
			delete [] historyEntry;
			current = other.current;
			capacity = other.capacity;
			historyEntry = new HistoryEntry[capacity];
			for(int i = 0; i <= capacity - 1; i++)
                historyEntry[i] = other.historyEntry[i];
		}
		return *this;
}
BrowserHistory::~BrowserHistory()
{
    delete []historyEntry;
}
int BrowserHistory::getCapacity()
{
    return capacity;
}
int BrowserHistory::getCurrent()
{
    return current;
}
HistoryEntry* BrowserHistory::getHistory()
{
    return historyEntry;
}
void BrowserHistory::addSite()
{
    cout<<"Add site to the history: "<<endl;
    HistoryEntry newOne;
    newOne.create_site();
    if(current == capacity)
    {
        cerr<<"Not enough space!";
        exit(1);
    }
    historyEntry[current] = newOne;
    current++;
    cout<<"The site has been successfully added!"<<endl;
}
void BrowserHistory::addSite(const HistoryEntry& other)
{
    if(current == capacity)
    {
        cerr << "Not enough space!";
        exit(1);
    }
    historyEntry[current] = other;
    current++;
    cout<<"The site has been successfully added!"<<endl;
}
void BrowserHistory::display()const
{
    cout<<"The print method for the browser history: "<<endl;
    for(int i = 0; i <= current - 1; i++)
    {
        historyEntry[i].print_site();
    }
}
int BrowserHistory::findM(int m)
{
    int counter = 0;
    for (int i = 0; i <= current - 1; i++)
    {
        if(historyEntry[i].month == m)
        {
            counter++;
        }
    }
    return counter;
}
int BrowserHistory::findMax()
{
    int month = 1;
    for(int i = 1; i <= 12; i++)
    {
        int counter = findM(i);
        if(counter > month)
        {
            month = i;
        }
    }
    return month;
}
void BrowserHistory::removeSite()
{
    if(current == 0)
    {
        cout<<"There are no sites in the browser history!"<<endl;
    }
    else
    {
        current--;
        cout<<"The last added site has been successfully removed!"<<endl;
    }
}
#endif // ZAD2_H_INCLUDED
