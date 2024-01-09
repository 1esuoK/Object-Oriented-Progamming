#include <iostream>
using namespace std;

class Gate
{
protected:
    int loai;
public:
    virtual void Nhap() = 0;
    virtual int getIndex() = 0;
    int getloai()
    {
        return loai;
    }
    virtual void setloai(int x) = 0;
};
class AcademicGate:public Gate
{
protected:
    int iq;
public:
    AcademicGate()
    {
        iq = 0;
    }
    void Nhap();
    int getIndex()
    {
        return iq;
    }
    void setloai(int x)
    {
        loai = x;
    }
};
class BussinessGate :public Gate
{
protected:
    int dongia, sohang;
public:
    BussinessGate()
    {
        dongia = 0;
        sohang = 0;
    }
    void Nhap();
    int getIndex()
    {
        return dongia * sohang;
    }
    void setloai(int x)
    {
        loai = x;
    }
};
class PowerGate :public Gate
{
protected:
    int strength;
public:
    PowerGate()
    {
        strength = 0;
    }
    void Nhap();
    int getIndex()
    {
        return strength;
    }
    void setloai(int x)
    {
        loai = x;
    }
};
int main()
{
    int n, type;
    Gate* gate[100];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> type;
        if (type == 1) gate[i] = new BussinessGate;
        if (type == 2) gate[i] = new AcademicGate;
        if (type == 3) gate[i] = new PowerGate;
        gate[i]->Nhap();
        gate[i]->setloai(type);
    }
    int Tien, SucManh, TriTue;
    cin >> Tien >> TriTue >> SucManh;
    int i = 0;
    while (Tien > 0 && TriTue > 0 && SucManh > 0 && i < n)
    {
        if (gate[i]->getloai() == 1)
        {
            Tien -= gate[i]->getIndex();
            if (Tien < 0)
            {
                cout << "-1";
                return 0;
            }
        }
        if (gate[i]->getloai() == 2)
        {
            if (TriTue < gate[i]->getIndex())
            {
                cout << "-1";
                return 0;
            }
        }
        if (gate[i]->getloai() == 3)
        {
            SucManh -= gate[i]->getIndex();
            if (SucManh < 0)
            {
                cout << "-1";
                return 0;
            }
        }
        i++;
    }
    cout << Tien << "\t" << TriTue << "\t" << SucManh;
    return 0;
}
void AcademicGate::Nhap()
{
    cin >> iq;
}
void BussinessGate::Nhap()
{
    cin >> dongia >> sohang;
}
void PowerGate::Nhap()
{
    cin >> strength;
}