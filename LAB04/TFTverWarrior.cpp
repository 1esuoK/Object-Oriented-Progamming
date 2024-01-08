#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
class Legends
{
public:
    string ten;
    string tentoc;
    float phongthu;
    int loai;
    string skill;
    void Nhap();
    void Xuat(int);
    int Skill(int);
};
int main()
{
    Legends* a;
    int n, m;
    cin >> n;
    a = new Legends[n];
    for (int i = 0; i < n; i++) a[i].Nhap();
    cin >> m;
    for (int i = 0; i < n; i++) a[i].Xuat(m);
    
}
void Legends::Nhap()
{
    cin >> loai;
    cin >> phongthu;
}
void Legends::Xuat(int m)
{
    if (loai == 1) cout << "Malphite - Sat thuong duoc giam: " << Skill(m) << endl;
    if (loai == 2) cout << "Cho'Gath - Sat thuong duoc giam: " << Skill(m) << endl;
}
int Legends::Skill(int m)
{
    int def = 0;
    if (loai == 1)
    {
        def = phongthu + 10;
        def *= 2;
        phongthu = def;
        for (int i = 0; i < m-1; i++)
            def += phongthu;
    }
    else if (loai == 2)
    {
        phongthu += 10;
        for (int i = 0; i < m; i++)
        {
            def += phongthu;
            phongthu += 5;
        }
    }
    return def;
}

