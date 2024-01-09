#include <iostream>
using namespace std;

class CPU
{
protected:
    string maCPU;
    int CPUType;
    string CPUBrand;
    int Cores;
    double Turbo;
    double CPUPrice;
public:
    void Nhap();
    virtual void Xuat() = 0;
    double getPrice()
    {
        return CPUPrice;
    }
};
class Alpha :public CPU
{
public:
    Alpha()
    {
        CPUType = 1;
        CPUPrice = 200;
        Cores = 2;
        Turbo = 1.8;
        CPUBrand = "Black";
    }
    void Xuat();
};
class Beta :public CPU
{
public:
    Beta()
    {
        CPUType = 2;
        CPUPrice = 400;
        Cores = 4;
        Turbo = 2.46;
        CPUBrand = "Black";
    }
    void Xuat();
};
class Gamma :public CPU
{
public:
    Gamma()
    {
        CPUType = 3;
        CPUPrice = 600;
        Cores = 4;
        Turbo = 2.6;
        CPUBrand = "White";
    }
    void Xuat();
};
class Case
{
protected:
    string maCase;
    int CaseType;
    string CaseBrand;
    double CasePrice;
    int Color;
public:
    virtual void Nhap() = 0;
    virtual void Xuat() = 0;
    double getPrice()
    {
        return CasePrice;
    }
};
class Al :public Case
{
public:
    Al()
    {
        CaseType = 1;
        CasePrice = 400;
        CaseBrand = "Black";
    }
    void Nhap();
    void Xuat();
};
class Plastic :public Case
{
public:
    Plastic()
    {
        CaseType = 2;
        CasePrice = 200;
        CaseBrand = "White";
    }
    void Nhap();
    void Xuat();
};
class Screen
{
protected:
    string maScreen;
    string ScreenBrand;
    int resolution;
    double ScreenPrice;
public:
    virtual void Nhap(string, string, int) = 0;
    virtual void Xuat() = 0;
    double getPrice()
    {
        return ScreenPrice;
    }
};
class HD :public Screen
{
public:
    HD()
    {
        ScreenPrice = 200;
        resolution = 1;
    }
    void Nhap(string, string, int);
    void Xuat();
};
class FullHD :public Screen
{
protected:
    int Chong_Loa;
public:
    void Nhap(string, string, int);
    void Xuat();
    FullHD()
    {
        if (Chong_Loa) ScreenPrice = 500;
        else ScreenPrice = 300;
        resolution = 2;
    }
};
class Smartphone
{
protected:
    string ma;
    int series;
    double price;
    CPU* processor;
    Screen* ManHinh;
    Case* Vo;
public:
    void setScreen(Screen* screen) {
        this->ManHinh = screen;
    }
    void Nhap();
    void Xuat();
};
class Venus :public Smartphone
{
public:
    Venus()
    {
        series = 1;
    }
};
class Mars :public Smartphone
{
public:
    Mars()
    {
        series = 2;
    }
};
class Jupiter : public Smartphone
{
public:
    Jupiter()
    {
        series = 3;
    }
};
int main()
{
    Smartphone* dssp[100];
    int n, type;
    /*cout << "Nhap so luong smartphone: ";*/
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        /*cout << "Dong smartphone (1 -  Venus, 2 - Mars , 3 - Jupiter): ";*/
        cin >> type;
        if (type == 1) dssp[i] = new Venus;
        if (type == 2) dssp[i] = new Mars;
        if (type == 3) dssp[i] = new Jupiter;
        dssp[i]->Nhap();
    }
    for (int i = 0; i < n; i++)
    {
        dssp[i]->Xuat();
    }
    return 0;
}
void Smartphone::Nhap()
{
    int loai;
    /*cout << "Nhap ma so: ";*/
    cin >> ma;
    /*cout << "Loai CPU (1 - Alpha, 2 - Beta, 3 - Gamma): ";*/
    cin >> loai;
    if (loai == 1) processor = new Alpha;
    if (loai == 2) processor = new Beta;
    if (loai == 3) processor = new Gamma;
    processor->Nhap();
    /*cout << "Man Hinh:" << endl;*/
    string tmp_ma, tmp_brand;
    int tmp_resolution;
    /*cout << "Nhap ma man hinh: ";*/
    cin >> tmp_ma;
    /*cout << "Hang san xuat: ";*/
    cin >> tmp_brand;
    /*cout << "Do phan giai (1 - HD, 2 - FullHD): ";*/
    cin >> tmp_resolution;
    if (tmp_resolution == 1) ManHinh = new HD;
    else if (tmp_resolution == 2) ManHinh = new FullHD;
    ManHinh->Nhap(tmp_ma, tmp_brand, tmp_resolution);
    /*cout << "Loai vo smartphone (1 - nhom, 2 - nhua: ";*/
    cin >> loai;
    if (loai == 1) Vo = new Al;
    if (loai == 2) Vo = new Plastic;
    Vo->Nhap();
}
void Smartphone::Xuat()
{
    cout << "Smartphone: " << ma << "\t";
    if (series == 1) cout << "Venus" << "\t" << (processor->getPrice() + ManHinh->getPrice() + Vo->getPrice()) * 1.3 << endl;
    if (series == 2) cout << "Mars" << "\t" << (processor->getPrice() + ManHinh->getPrice() + Vo->getPrice()) * 1.5 << endl;
    if (series == 3) cout << "Jupiter" << "\t" << (processor->getPrice() + ManHinh->getPrice() + Vo->getPrice()) * 1.8 << endl;
    processor->Xuat();
    ManHinh->Xuat();
    Vo->Xuat();
}
void CPU::Nhap()
{
    /*cout << "Nhap ma CPU: ";*/
    cin >> maCPU;
}
void Alpha::Xuat()
{
    cout << "CPU: " << maCPU << "\t" << "Alpha" << "\t" << "Black" << "\t" << Cores << "\t" << Turbo << "\t" << CPUPrice << endl;
}
void Beta::Xuat()
{
    cout << "CPU: " << maCPU << "\t" << "Beta" << "\t" << "Black" << "\t" << Cores << "\t" << Turbo << "\t" << CPUPrice << endl;
}
void Gamma::Xuat()
{
    cout << "CPU: " << maCPU << "\t" << "Gamma" << "\t" << "White" << "\t" << Cores << "\t" << Turbo << "\t" << CPUPrice << endl;
}
void Al::Nhap()
{
    /*cout << "Nhap ma vo: ";*/
    cin >> maCase;
    /*cout << "Mau vo (1 - Do, 2 - Den): ";*/
    cin >> Color;
}
void Plastic::Nhap()
{
    /*cout << "Nhap ma vo: ";*/
    cin >> maCase;
    /*cout << "Mau vo (1 - Do, 2 - Den, 3 - Xanh): ";*/
    cin >> Color;
}
void Al::Xuat()
{
    cout << "Vo smartphone: " << maCase << "\t" << "Nhom" << "\t" << "Black";
    if (Color == 1) cout << "\t" << "Do" << "\t";
    if (Color == 2) cout << "\t" << "Den" << "\t";
    cout << CasePrice << endl;
}
void Plastic::Xuat()
{
    cout << "Vo smartphone: " << maCase << "\t" << "Nhua" << "\t" << "White";
    if (Color == 1) cout << "\t" << "Do" << "\t";
    if (Color == 2) cout << "\t" << "Den" << "\t";
    if (Color == 3) cout << "\t" << "Xanh" << "\t";
    cout << CasePrice << endl;
}
void HD::Nhap(string maScreen, string ScreenBrand, int resolution)
{
    this->maScreen = maScreen;
    this->ScreenBrand = ScreenBrand;
    this->resolution = resolution;
}
void FullHD::Nhap(string maScreen, string ScreenBrand, int resolution)
{
    this->maScreen = maScreen;
    this->ScreenBrand = ScreenBrand;
    this->resolution = resolution;
    cin >> Chong_Loa;
}
void HD::Xuat()
{
    cout << "Man hinh: " << maScreen << "\t" << ScreenBrand << "\t" << "HD" << "\t" << ScreenPrice << endl;
}
void FullHD::Xuat()
{
    cout << "Man hinh: " << maScreen << "\t" << ScreenBrand << "\t" << "HD" << "\t" << ScreenPrice;
    if (Chong_Loa) cout << "Chong loa" << endl;
    else cout << endl;
}
