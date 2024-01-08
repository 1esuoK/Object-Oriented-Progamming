#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Farm
{
private:
    int slBo, slCuu, slDe, luot;
    int mBo, mCuu, mDe;
public:
    void Nhap();
    void Milk();
    void Xuat();
};

int main()
{
    Farm a;
    a.Nhap();
    a.Milk();
    a.Xuat();
    return 0;
}
void Farm::Nhap()
{
    cin >> slBo >> slCuu >> slDe >> luot;
}
void Farm::Milk()
{
    mBo = slBo * luot * 10;
    mCuu = slCuu * luot * 5;
    mDe = slDe * luot * 8;
}
void Farm::Xuat()
{
    for (int i = 0; i < slBo; i++) cout << "Booo,";
    for (int i = 0; i < slCuu; i++) cout << "Beee,";
    for (int i = 0; i < slDe-1; i++) cout << "Eeee,";
    cout << "Eeee" << endl;
    cout << "Bo: " << mBo << endl;
    cout << "Cuu: " << mCuu << endl;
    cout << "De: " << mDe << endl;
}

