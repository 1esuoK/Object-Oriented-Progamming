#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class DaThuc {
private:
    int heso[100];
    int bac;
public:
    friend istream& operator>>(istream& is, DaThuc& a);
    friend ostream& operator<<(ostream& os, DaThuc a);
    DaThuc operator+(DaThuc a);
    DaThuc operator-(DaThuc a);
    DaThuc operator*(DaThuc a);
};
int main()
{
    DaThuc a, b;
    cin >> a >> b;
    int n;
    cin >> n;
    switch (n)
    {
    case 1:
        cout << a + b;
        break;
    case 2:
        cout << a - b;
        break;
    case 3:
        cout << a * b;
        break;
    default:
        break;
    }
}
istream& operator>>(istream& is, DaThuc& a)
{
    do {
        is >> a.bac;
    } while (a.bac < 0);
    /*a.heso = new int[a.bac];*/
    for (int i = 0; i <= a.bac; i++)
        is >> a.heso[i];
    return is;
}
ostream& operator<<(ostream& os, DaThuc a)
{
    int k = 0;
    for (; k <= a.bac; k++)
    {
        if (a.heso[k] != 0)
        {
            os << a.heso[k] << "x^" << 0;
            break;
        }
    }
    for (int i = k + 1; i <= a.bac; i++)
    {
        if (a.heso[i] == 0) continue;
        else if (a.heso[i] > 0) os << "+" << a.heso[i] << "x^" << i;
        else os << a.heso[i] << "x^" << i;
    }
    return os;
}
DaThuc DaThuc::operator+(DaThuc a)
{
    DaThuc kq;
    kq.bac = max(bac, a.bac);
    /* kq.heso = new int[bac];*/
     /*for (int i = 0; i <= bac; i++)
         kq.heso[i] = 0;*/
    if (bac == a.bac) {
        for (int i = bac; i >= 0; i--)
            kq.heso[i] = heso[i] + a.heso[i];
    }
    if (bac > a.bac) {
        for (int i = bac; i > a.bac; i--)
            kq.heso[i] = heso[i];
        for (int i = a.bac; i >= 0; i--)
            kq.heso[i] = heso[i] + a.heso[i];
    }
    if (bac < a.bac) {
        for (int i = a.bac; i > bac; i--)
            kq.heso[i] = a.heso[i];
        for (int i = bac; i >= 0; i--)
            kq.heso[i] = heso[i] + a.heso[i];
    }
    return kq;
}
DaThuc DaThuc::operator-(DaThuc a)
{
    DaThuc kq;
    kq.bac = max(bac, a.bac);
    /*kq.heso = new int[bac];*/
    /*for (int i = 0; i <= bac; i++)
        kq.heso[i] = 0;*/
    /*for (int i = 0; i <= bac; i++)
        kq.heso[i] += heso[i];
    for (int i = 0; i <= bac; i++)
        kq.heso[i] -= a.heso[i];*/
    if (bac == a.bac) {
        for (int i = bac; i >= 0; i--)
            kq.heso[i] = heso[i]-a.heso[i];
    }
    if (bac > a.bac) {
        for (int i = bac; i > a.bac; i--)
            kq.heso[i] = heso[i];
        for (int i = a.bac; i >= 0; i--)
            kq.heso[i] = heso[i] - a.heso[i];
    }
    if (bac < a.bac) {
        for (int i = a.bac; i > bac; i--)
            kq.heso[i] = -a.heso[i];
        for (int i = bac; i >= 0; i--)
            kq.heso[i] = heso[i] - a.heso[i];
    }
    return kq;
}
DaThuc DaThuc::operator*(DaThuc a)
{
    DaThuc kq;
    kq.bac = bac + a.bac;
    /*kq.heso = new int[kq.bac];*/
    for (int i = 0; i <= kq.bac; i++)
        kq.heso[i] = 0;
    for (int i = 0; i <= bac; i++)
        for (int j = 0; j <= a.bac; j++)
            kq.heso[i + j] += heso[i] * a.heso[j];
    return kq;
}