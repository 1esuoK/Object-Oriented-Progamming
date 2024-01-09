#include <iostream>
using namespace std;

static float dientich = 0;
static float thetich = 0;

class Chai
{
public:
    virtual float TinhDienTich() = 0;
    virtual float TinhTheTich() = 0;
    virtual void Nhap() = 0;
};
class ChaiTru :public Chai
{
protected:
    float ChieuCao;
    float Rday;
public:
    ChaiTru()
    {
        ChieuCao = 0;
        Rday = 0;
    }
    float TinhDienTich();
    float TinhTheTich();
    void Nhap();
};
class ChaiHCN :public Chai
{
protected:
    float cao, dai, rong;
public:
    ChaiHCN()
    {
        cao = 0;
        dai = 0;
        rong = 0;
    }
    float TinhDienTich();
    float TinhTheTich();
    void Nhap();
};
class ChaiCube :public Chai
{
protected:
    float canh;
public:
    ChaiCube()
    {
        canh = 0;
    }
    float TinhDienTich();
    float TinhTheTich();
    void Nhap();
};
int main()
{
    int n, loai;
    Chai *dsChai[100];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> loai;
        if (loai == 1) dsChai[i] = new ChaiTru;
        if (loai == 2) dsChai[i] = new ChaiHCN;
        if (loai == 3) dsChai[i] = new ChaiCube;
        dsChai[i]->Nhap();
    }
    for (int i = 0; i < n; i++)
    {
        dsChai[i]->TinhDienTich();
        dsChai[i]->TinhTheTich();
    }
    cout << "Dien tich chai vo: " << dientich << endl;
    cout << "Luong nuoc tren mat dat: " << thetich / 10;
    return 0;
}
void ChaiTru::Nhap()
{
    cin >> ChieuCao >> Rday;
}
void ChaiHCN::Nhap()
{
    cin >> cao >> dai >> rong;
}
void ChaiCube::Nhap()
{
    cin >> canh;
}
float ChaiTru::TinhDienTich()
{
    float s = 0;
    s = 2 * 3.14 * Rday * ChieuCao;
    dientich += s;
    return s;
}
float ChaiTru::TinhTheTich()
{
    float v = 0;
    v = 3.14 * Rday * Rday * ChieuCao;  
    thetich += v;
    return v;
}
float ChaiHCN::TinhDienTich()
{
    float s = 0;
    s = (dai + rong) * 2 * cao + 2 * dai * rong;
    dientich += s;
    return s;
}
float ChaiHCN::TinhTheTich()
{
    float v = 0;
    v = cao * rong * dai;
    thetich += v;
    return v;
}
float ChaiCube::TinhDienTich()
{
    float s = 0;
    s = canh * canh * 6;
    dientich += s;
    return s;
}
float ChaiCube::TinhTheTich()
{
    float v = 0;
    v = canh * canh * canh;
    thetich += v;
    return v;
}