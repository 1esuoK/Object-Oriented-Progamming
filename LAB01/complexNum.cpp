#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
class SoPhuc
{
private:
    float thuc, ao;
public:
    void Nhap();
    void Xuat();
    int modulo();
    SoPhuc Tong(SoPhuc);
    SoPhuc Hieu(SoPhuc);
    SoPhuc Tich(SoPhuc);
    SoPhuc Thuong(SoPhuc);
    SoPhuc Nhan(int);
};
int main()
{
    SoPhuc c1, c2, A, A1, A2, A3, A4;
    c1.Nhap();
    c2.Nhap();
    if (c1.modulo() == 0 || c2.modulo() == 0) cout << "ERROR";
    else
    {
        A1 = c1.Tong(c2);
        A2 = c2.Hieu(c1.Nhan(2));
        A3 = A1.Tich(A2);
        A4 = c1.Hieu(c2.Nhan(4));
        A = A3.Thuong(A4);
    }
    A.Xuat();
    return 0;
}
void SoPhuc::Nhap()
{
    cin >> thuc >> ao;
}
int SoPhuc::modulo()
{
    int a = sqrt(thuc * thuc + ao * ao);
    return a;
}
void SoPhuc::Xuat()
{
    if (thuc == 0) cout << ao << "i";
    else if (ao > 0) cout << thuc << " + " << ao << "i";
    else if (ao < 0) cout << thuc << " - " << ao*-1 << "i";
    else cout << thuc;
}
SoPhuc SoPhuc::Tong(SoPhuc a)
{
    SoPhuc kq;
    kq.thuc = thuc + a.thuc;
    kq.ao = ao + a.ao;
    return kq;
}
SoPhuc SoPhuc::Hieu(SoPhuc a)
{
    SoPhuc kq;
    kq.thuc = thuc - a.thuc;
    kq.ao = ao - a.ao;
    return kq;
}
SoPhuc SoPhuc::Tich(SoPhuc a)
{
    SoPhuc kq;
    kq.thuc = thuc * a.thuc - ao * a.ao;
    kq.ao = thuc * a.ao + ao * a.thuc;
    return kq;
}
SoPhuc SoPhuc::Thuong(SoPhuc a)
{
    SoPhuc kq;
    kq.thuc = ((thuc * a.thuc + ao * a.ao) / (a.thuc * a.thuc + a.ao * a.ao));
    kq.ao = ((a.thuc * ao - thuc * a.ao) / (a.thuc * a.thuc + a.ao * a.ao));
    return kq;
}
SoPhuc SoPhuc::Nhan(int k)
{
    SoPhuc kq;
    kq.thuc = k * thuc;
    kq.ao = k * ao;
    return kq;
}


