#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class MYINT
{
private:
    int a;
public:
    MYINT(int);
    MYINT operator+(MYINT b);
    MYINT operator*(MYINT b);
    friend ostream& operator<<(ostream& os, MYINT a);
};
int main() {
    MYINT a(4), b(5);
    cout << (a + b) * a;
    cout << a * b;
    system("pause");
    return 0;
}
MYINT::MYINT(int a)
{
   this->a = a;
}
ostream& operator<<(ostream& os, MYINT b)
{
    os << b.a << endl;
    return os;
}
MYINT MYINT::operator+(MYINT b)
{
    return a - b.a;
}
MYINT MYINT::operator*(MYINT b)
{
    return a * b.a;
}