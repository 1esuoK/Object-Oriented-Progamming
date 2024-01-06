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
    void Xuat();
    PhanSo();
    double getThapPhan();
};
class MangPhanSo
{
private:
    int n;
    PhanSo mangPhanSo[100];
public:
    void Nhap();
    PhanSo PSMax();
    PhanSo PSMin();
};
int main()
{
    MangPhanSo a;
    PhanSo lon, be;
    a.Nhap();
    be = a.PSMin();
    be.Xuat();
    cout << endl;
    lon = a.PSMax();
    lon.Xuat();
    return 0;
}
void MangPhanSo::Nhap()
{
    cin >> n;
    for (int i = 0; i < n; i++) mangPhanSo[i].Nhap();
}
void PhanSo::Nhap()
{
    cin >> tu >> mau;
    if (!mau) {
        do
        {
            cin >> mau;
        } while (!mau);
    }
}
void PhanSo::Xuat()
{
    cout << tu << "/" << mau;
}
PhanSo::PhanSo()
{
    tu = 0;
    mau = 1;
}
PhanSo MangPhanSo::PSMax()
{
    PhanSo Max = mangPhanSo[0];
    for (int i = 0; i < n; i++)
    {
        if (Max.getThapPhan() < mangPhanSo[i].getThapPhan()) Max = mangPhanSo[i];
    }
    return Max;
}
PhanSo MangPhanSo::PSMin()
{
    PhanSo Min = mangPhanSo[0];
    for (int i = 0; i < n; i++)
    {
        if (Min.getThapPhan() > mangPhanSo[i].getThapPhan()) Min = mangPhanSo[i];
    }
    return Min;
}
double PhanSo::getThapPhan()
{
    return (double)tu / mau;
}

