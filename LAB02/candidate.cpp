#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
class HocSinh {
private:
    string mssv;
    string name;
    string birth;
    int toan, van, anh;
public:
    void Nhap();
    void Xuat();
    int Tong();
};
class DSHocSinh{
private:
    HocSinh mangHocSinh[100];
    int stt[100];
    int n;
public:
    void Nhap();
    void Xuat();
};
int main()
{
    DSHocSinh a;
    a.Nhap();
    a.Xuat();
    return 0;
}
void HocSinh::Nhap()
{
        
    cin >> mssv;
    cin.ignore();
    getline(cin,name);
    cin >> birth;
    do {
        cin >> toan >> van >> anh;
    } while (toan < 0 ||toan >10 ||van < 0 ||van >10 || anh < 0 || anh >10);
}
int HocSinh::Tong()
{
    int kq;
    kq = toan + van + anh;
    return kq;
}
void HocSinh::Xuat()
{
    cout << "Thong tin hoc sinh:" << endl;
    cout << "Ma: " << this->mssv << endl;
    cout << "Ho ten: " << this->name << endl;
    cout << "Ngay sinh: " << this->birth << endl;
    cout << "Diem toan: " << this->toan << endl;
    cout << "Diem van: " << this->van << endl;
    cout << "Diem anh: " << this->anh << endl;
}
void DSHocSinh::Xuat()
{
    int count = 0;
    for(int i=0;i<n;i++)
        if (mangHocSinh[i].Tong() > 15)
        {
            cout << "-" << endl;
            cout << "STT " << stt[i] << ":" << endl;
            mangHocSinh[i].Xuat();
            count++;
        }
    if(count==0) cout << "Khong co thi sinh co tong diem lon hon 15" << endl;

}
void DSHocSinh::Nhap()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        mangHocSinh[i].Nhap();
        stt[i] = i + 1;
    }
}