#include <iostream>
using namespace std;
#define Ghe 1
#define Thuong 2
#define Lon 3
class Boat
{
protected:
    string SoHieu;
    int slthuyenvien;
    int type;
public:
    virtual void Nhap() = 0;
    virtual void Xuat() = 0;
    virtual int gettype() = 0;
};
class Small :public Boat
{
    int DongCo;
public:
    Small()
    {
        type = Ghe;
    }
    int gettype()
    {
        return type;
    }
    void Nhap();
    void Xuat();
};
class Normal :public Boat
{
    string Label;
public:
    Normal()
    {
        type = Thuong;
    }
    int gettype()
    {
        return type;
    }
    void Nhap();
    void Xuat();
};
class Large :public Boat
{
    string Label;
    float SailingRange;
public:
    Large()
    {
        type = Lon;
    }
    int gettype()
    {
        return type;
    }
    void Nhap();
    void Xuat();
};
int main()
{
    Boat* a[100];
    int n, type;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> type;
        if (type == Ghe) a[i] = new Small;
        if (type == Thuong) a[i] = new Normal;
        if (type == Lon) a[i] = new Large;
        a[i]->Nhap();
    }
    for (int i = 0; i < n; i++)
    {
        a[i]->Xuat();
        cout << endl;
    }
    return 0;
}
void Small::Nhap()
{
    cin >> SoHieu >> slthuyenvien >> DongCo;
}
void Normal::Nhap()
{
    cin >> SoHieu >> slthuyenvien >> Label;
}
void Large::Nhap()
{
    cin >> SoHieu >> slthuyenvien >> Label >> SailingRange;
}
void Small::Xuat()
{
    cout << SoHieu << " - " << "Ghe" << " - " << slthuyenvien << " thuyen vien";
    if (DongCo) cout << " - " << "Co Dong Co";
}
void Normal ::Xuat()
{
    cout << SoHieu << " - " << "Thuyen thuong" << " - " << slthuyenvien << " thuyen vien" << " - " << Label;
}
void Large::Xuat()
{
    cout << SoHieu << " - " << "Thuyen lon" << " - " << slthuyenvien << " thuyen vien" << " - " << Label << " - " << SailingRange << "m";
}