#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Diem {
private:
    float hoanh, tung;
    int o, d;
public:
    void Nhap();
    void Xuat();
    void NhanDoi();
    void GanGocToaDo();
    void TinhTien();
};
int main()
{
    int x, n;
    Diem a;
    a.Nhap();
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        if (x == 1) a.NhanDoi();
        if (x == 2) a.GanGocToaDo();
        if (x == 3) a.TinhTien();
    }
    a.Xuat();
}
void Diem::Nhap()
{
    cin >> hoanh >> tung;
}
void Diem::Xuat()
{
    cout << "(" << hoanh << "," << tung << ")" << endl;
}
void Diem::NhanDoi()
{
    hoanh = hoanh * 2;
    tung = tung * 2;
}
void Diem::GanGocToaDo()
{
    hoanh = 0;
    tung = 0;
}
void Diem::TinhTien()
{
    cin >> o >> d;
    if (o == 0) hoanh = hoanh + d;
    else tung = tung + d;
}
