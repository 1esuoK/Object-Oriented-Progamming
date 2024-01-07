#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


class Clock {
private:
    int hour, min, sec;
public:
    Clock();
    friend istream& operator>>(istream& is, Clock& time);
    friend ostream& operator<<(ostream& is, Clock time);
    Clock operator+(int);
    Clock operator-(int);
    Clock& operator++();
    Clock& operator--();
    void Standardize();
};
int main()
{
    Clock myClock;
    cin >> myClock;
    int n, s;
    cin >> n;
    string *x;
    x = new string[n];
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
        if (x[i] == "++")
        {
            ++myClock;
            continue;
        }
        if (x[i] == "--")
        {
            --myClock;
            continue;
        }
        if (x[i] == "+")
        {
            cin >> s;
            myClock = myClock + s;
            continue;
        }
        if (x[i] == "-")
        {
            cin >> s;
            myClock = myClock - s;
            continue;
        }
    }
    cout << myClock;
    return 0;
}

Clock::Clock()
{
    hour = 0;
    min = 0;
    sec = 0;
}
istream& operator>>(istream& is, Clock& time)
{
    is >> time.hour >> time.min >> time.sec;
    return is;
}
ostream& operator<<(ostream& os, Clock time)
{
    os << time.hour << " " << time.min << " " << time.sec << " " << endl;
    return os;
}
void Clock::Standardize()
{
    hour = abs(hour);
    min = abs(min);
    sec = abs(sec);
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
Clock& Clock::operator++()
{
    sec++;
    Standardize();
    return *this;
}
Clock Clock::operator+(int x)
{
    sec += x;
    Standardize();
    return *this;
}
Clock& Clock::operator--()
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
    return *this;
}
Clock Clock::operator-(int x)
{
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
    return *this;
}