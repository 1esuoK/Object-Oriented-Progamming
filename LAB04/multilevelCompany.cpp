#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

static int SSP = 0;
static int SNL = 0;
class NhanVien
{
public:
    int loai;
    string hoTen;
    virtual void Nhap() = 0;
    virtual void Xuat() = 0;
};
class NVSX :public
    NhanVien {
public:
    float BasicSalary;
    int Products;
    void Nhap();
    void Xuat();
    float FindSalary();
};
class NVVP :public
    NhanVien {
public:
    int WorkDays;
    void Nhap();
    void Xuat();
    float FindSalary();
};
class Sep :public
    NhanVien {
public:
    void Nhap();
    void Xuat();
    float FindSalary();
};
int main()
{
    NhanVien** a;
    int n, loai;
    cin >> n;
    a = new NhanVien*[n];
    for (int i = 0; i < n; i++)
    {
        cin >> loai;
        if (loai == 1) a[i] = new NVSX;
        else if (loai == 2) a[i] = new NVVP;
        else if (loai==3) a[i] = new Sep;
        a[i]->Nhap();
    }
    for (int i = 0; i < n; i++)
    {
        a[i]->Xuat();
        cout << endl;
    }
    return 0;
}
void NVSX::Nhap()
{
    cin >> hoTen;
    cin >> BasicSalary >> Products;
    SSP += Products;
    loai = 1;
}
void NVVP::Nhap()
{
    cin >> hoTen;
    cin >> WorkDays;
    SNL += WorkDays;
    loai = 2;
}
void Sep::Nhap()
{
    cin >> hoTen;
    loai = 3;
}
float NVSX::FindSalary()
{
    float sal;
    sal = BasicSalary + Products * 5;
    return sal;
}
float NVVP::FindSalary()
{
    float sal;
    sal = WorkDays * 100;
    return sal;
}
float Sep::FindSalary()
{
    float sal;
    sal = 100 + SSP * 2 + SNL * 40;
    return sal;
}
void NVSX::Xuat()
{
    cout << hoTen << ": " << FindSalary();
}
void NVVP::Xuat()
{
    cout << hoTen << ": " << FindSalary();
}
void Sep::Xuat()
{
    cout << hoTen << ": " << FindSalary();
}
