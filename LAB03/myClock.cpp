#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


class Clock {
private:
    int hour, min, sec;
public:
    friend istream& operator>>(istream& is, Clock &time);
    friend ostream& operator<<(ostream& is, Clock time);
    void Add1();
    void Minus1();
    void AddX();
    void MinusX();
    void Standardize();
    void Command();
};
int main()
{
    Clock myClock;
    cin >> myClock;
    myClock.Command();
    return 0;
}
void Clock::Command()
{
    Standardize();
    int n;
    do {
        cin >> n;
        switch (n)
        {
        case 1:
            Add1();
            break;
        case 2:
            Minus1();
            break;
        case 3:
            AddX();
            break;
        case 4:
            MinusX();
            break;
        case -1:
            cout << hour << "h " << min << "p " << sec << "s" << endl;
        }
    } while (n != -1);
}
istream& operator>>(istream& is, Clock& time)
{
    is >> time.hour >> time.min >> time.sec;
    return is;
}
//ostream& operator<<(ostream& os, Clock time)
//{
//    os << time.hour << "h " << time.min << "p " << time.sec << "s" << endl;
//    return os;
//}
void Clock::Standardize()
{
    hour = abs(hour);
    min = abs(min);
    sec= abs(sec);
    if (sec >= 60) {
        min += sec / 60;
        sec = sec % 60;
    }
    if (min >= 60)
    {
        hour += min / 60;
        min = min % 60;
    }
    if (hour >= 24) hour = hour % 24;
}
void Clock::Add1()
{
    sec++;
    Standardize();
}
void Clock::AddX()
{
    int x; 
    cin >> x;
    sec += x;
    Standardize();
}
void Clock::Minus1()
{
    if (hour == 0 && sec == 0 && min == 0)
    {
        hour = 23;
        min = 59;
        sec = 59;
    }
    else if (min == 0 && sec == 0) {
        hour--;
        min = 59;
        sec = 59;
    }
    else if (sec == 0) {
        min--;
        sec = 59;
    }
    else sec--;
}
void Clock::MinusX()
{
    int x;
    cin >> x;
    sec -= x;
    min += sec / 60;
    sec = sec % 60;
    if (min < 0)
    {
        hour += hour / 60;
        min = min % 60;
    }
    if (sec < 0)
    {
        sec = 60 + sec;
        min--;
    }
    if (min < 0)
    {
        min = 60 + min;
        hour--;
    }
}