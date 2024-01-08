#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Quaternion
{
private:
    int i, j, k, l;
public:
    Quaternion();
    friend istream& operator>>(istream& is, Quaternion &a);
    friend ostream& operator<<(ostream& os, Quaternion a);
    Quaternion operator+(Quaternion a);
    Quaternion operator-(Quaternion a);
};

int main() {
    Quaternion a, b;
    cin >> a >> b;
    cout << a + b;
    cout << endl;
    cout << a - b;
    system("pause");
    return 0;
}
Quaternion::Quaternion()
{
    i = 0, j = 0, k = 0, l = 0;
}
istream& operator>>(istream& is, Quaternion &a)
{
    is >> a.i >> a.j >> a.k >> a.l;
    return is;
}
ostream& operator<<(ostream& os, Quaternion a)
{
    os << "(" << a.i << "," << a.j << "," << a.k << "," << a.l << ")";
    return os;
}
Quaternion Quaternion::operator+(Quaternion a)
{
    Quaternion kq;
    kq.i = i + a.i;
    kq.j = j + a.j;
    kq.k = k + a.k;
    kq.l = l + a.l;
    return kq;
}
Quaternion Quaternion::operator-(Quaternion a)
{
    Quaternion kq;
    kq.i = i - a.i;
    kq.j = j - a.j;
    kq.k = k - a.k;
    kq.l = l - a.l;
    return kq;
}
