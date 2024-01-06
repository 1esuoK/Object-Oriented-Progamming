#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class PhanSo
{
private:
    int tu, mau;
public:
    void Nhap();
    int gcd(int, int);
    void Xuat();
    PhanSo Tong(PhanSo);
    PhanSo Hieu(PhanSo);
    PhanSo Tich(PhanSo);
    PhanSo Thuong(PhanSo);
};
int main()
{
    PhanSo ps1, ps2;
    ps1.Nhap();
    ps2.Nhap();
    ps1.Tong(ps2).Xuat();
    ps1.Hieu(ps2).Xuat();
    ps1.Tich(ps2).Xuat();
    ps1.Thuong(ps2).Xuat();
    return 0;
}
void PhanSo::Nhap()
{
    cin >> tu;
    do
    {
        cin >> mau;
    } while (!mau);
}
int PhanSo::gcd(int a, int b)
{
    if (b == 0) return a;
    return gcd(b, a % b);
}
void PhanSo::Xuat()
{
    int ucln = gcd(abs(tu), abs(mau));
    if (mau < 0) ucln = -ucln;
    tu /= ucln;
    mau /= ucln;
    cout << tu << "/" << mau << endl;
}
PhanSo PhanSo::Tong(PhanSo p)
{
    PhanSo tong;
    tong.tu = tu * p.mau + p.tu * mau;
    tong.mau = mau * p.mau;
    return tong;
}
PhanSo PhanSo::Hieu(PhanSo p)
{
    PhanSo hieu;
    hieu.tu = tu * p.mau - p.tu * mau;
    hieu.mau = mau * p.mau;
    return hieu;
}
PhanSo PhanSo::Tich(PhanSo p)
{
    PhanSo tich;
    tich.tu = tu * p.tu;
    tich.mau = mau * p.mau;
    return tich;
}
PhanSo PhanSo::Thuong(PhanSo p)
{
    PhanSo thuong;
    thuong.tu = tu * p.mau;
    thuong.mau = mau * p.tu;
    return thuong;
}






