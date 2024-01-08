#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Farm
{
private:
    int a[4];
    int slBo, slCuu, slDe, slTho, luot;
    int BoCon[100], CuuCon[100], DeCon[100], ThoCon[100];
    int mBo=0, mCuu=0, mDe=0, mTho = 0;
public:
    void Nhap();
    void Milk();
    void Xuat();
};

int main()
{
    Farm a;
    a.Nhap();
    a.Milk();
    a.Xuat();
    return 0;
}
void Farm::Nhap()
{
    cin >> slBo >> slCuu >> slDe >> slTho >> luot;
    a[0] = slBo;
    a[1] = slCuu;
    a[2] = slDe;
    a[3] = slTho;
}
void Farm::Milk()
{
    for (int i = 0; i < luot; i++)
    {
        BoCon[i] = slBo / 2;
        if (i % 4 == 0&&i!=0)
        {
            slBo += BoCon[i];
            for (int j = 0; j < i; j++)
                BoCon[i + 1] = BoCon[i];
            BoCon[0] = slBo / 2;
        }
        CuuCon[i] = slCuu / 2;
        if (i % 4 == 0 && i != 0)
        {
            slCuu += CuuCon[i];
            for (int j = 0; j < i; j++)
                CuuCon[i + 1] = CuuCon[i];
            CuuCon[0] = slCuu / 2;
        }
        DeCon[i] = slDe / 2;
        if (i % 4 == 0 && i != 0)
        {
            slDe += DeCon[i];
            for (int j = 0; j < i; j++)
                DeCon[i + 1] = DeCon[i];
            DeCon[0] = slDe / 2;
        }
        ThoCon[i] = slTho / 2;
        if (i % 2 == 0 && i != 0)
        {
            slTho += ThoCon[i];
            for (int j = 0; j < i; j++)
                ThoCon[i + 1] = ThoCon[i];
            ThoCon[0] = slTho / 2;
        }
        mBo += slBo * 10;
        mCuu += slCuu * 5;
        mDe += slDe * 8;
    }
    for(int i=0;i<4;i++)
    {
        slBo += BoCon[i];
        slCuu += CuuCon[i];
        slDe += DeCon[i];
        slTho += ThoCon[i];
    }
}
void Farm::Xuat()
{
    for (int i = 0; i < a[0]; i++) cout << "Booo,";
    for (int i = 0; i < a[1]; i++) cout << "Beee,";
    for (int i = 0; i < a[2]; i++) cout << "Eeee,";
    for (int i = 0; i < a[3]-1; i++) cout << ",";
    cout << endl;
    cout << "Bo: " << slBo << "," << mBo << endl;
    cout << "Cuu: " << slCuu << "," << mCuu << endl;
    cout << "De: " << slDe << "," << mDe << endl;
    cout << "Tho: " << slTho << "," << mTho << endl;
}

