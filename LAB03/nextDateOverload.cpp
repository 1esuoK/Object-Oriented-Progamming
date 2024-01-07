#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Date {
private:
    int d, m, y, lastday = 0;
public:
    Date();
    friend istream& operator>>(istream& is, Date& x);
    friend ostream& operator<<(ostream& os, Date x);
    int nhuan();
    void Standardize();
    void AddXday();
    void MinusXday();
    int CheckDayOfMonth();
    int Daysfrom0();
    void Command();
};
int main()
{
    Date d;
    cin >> d;
    d.Standardize();
    d.Command();
    return 0;
}
int Date::Daysfrom0()
{

    /*double days = y* (365 + 1 / 4 - 1 / 100 + 1 / 400) + d;*/
    int nhuan = 0;
    int days = 0;
    for (int i = 0; i < y; i++)
    {
        if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0) nhuan++;
    }
    days = d + nhuan + y * 365;
    for (int i = 1; i < m; ++i)
    {
        switch (i)
        {
        case 1: case 3:case 5:case 7:case 8:case 10:case 12:
            days += 31; break;
        case 4:case 6:case 9:case 11:
            days += 30; break;
        case 2:
            if (y % 400 == 0 || (y % 100 != 0 && y % 4 == 0)) days += 29;
            else days += 28;
        }
    }
    return days;
}
void Date::Command()
{
    Date a;
    int n;
    do
    {
        cin >> n;
        switch (n)
        {
        case 1:
            AddXday();
            break;
        case 2:
            MinusXday();
            break;
        case 3:
            cin >> a;
            cout << abs(Daysfrom0() - a.Daysfrom0());
        }
    } while (n != 3);
}
Date::Date()
{
    d = 0;
    m = 0;
    y = 0;
}
istream& operator>>(istream& is, Date& x)
{
    is >> x.d >> x.m >> x.y;
    return is;
}
ostream& operator<<(ostream& os, Date x)
{
    os << x.d << "/" << x.m << "/" << x.y << endl;
    return os;
}
void Date::AddXday()
{
    int x;
    cin >> x;
    CheckDayOfMonth();
    if (d + x < lastday) d += x;
    else
    {
        while (x > lastday)
        {
            x = x - (lastday - d + 1);
            d = 1;
            m++;
            if (m > 12)
            {
                y += m / 12;
                m = m % 12;
            }
            CheckDayOfMonth();
        }
        d += x;
    }
}
void Date::MinusXday()
{
    int x;
    cin >> x;
    CheckDayOfMonth();
    if (d - x > 0) d -= x;
    else
    {
        while (d - x < 0)
        {
            x = x - abs(d - x);
            m--;
            CheckDayOfMonth();
            d = lastday;
            if (m <= 0)
            {
                y--;
                y -= abs(m) / 12;
                m = 12 - m;
            }
            CheckDayOfMonth();
        }
        d -= x;
    }

}
int Date::nhuan()
{
    return ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0);
}
void Date::Standardize()
{
    d = abs(d);
    m = abs(m);
    y = abs(y);
    this->m = (this->m) % 12; if (this->m == 0) this->m = 12;
    if (this->d > CheckDayOfMonth())
    {
        this->d = 1;
    }
    /*CheckDayOfMonth();
    if (m == 0) m = 12;
    while (d > lastday)
    {
        d = d - lastday;
        m++;
        if (m > 12)
        {
            y += m / 12;
            m = m % 12;
        }
        CheckDayOfMonth();
    }*/
}
//void Date::DayOfMonth()
//{
//    switch (m)
//    {
//    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
//        lastday = 31;
//        break;
//    case 4: case 6: case 9: case 11:
//        lastday = 30;
//        break;
//    case 2:
//        if (nhuan()) lastday = 29;
//        else lastday = 28;
//        break;
//    default:
//        break;
//    }
//}
int Date::CheckDayOfMonth()
{
    switch (m)
    {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        lastday = 31;
        break;
    case 4: case 6: case 9: case 11:
        lastday = 30;
        break;
    case 2:
        if (nhuan()) lastday = 29;
        else lastday = 28;
        break;
    default:
        break;
    }
    return lastday;
}

