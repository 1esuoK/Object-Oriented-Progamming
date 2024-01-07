#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class DaGiac {
private:
    float x, y;
    int n;
    DaGiac* a;
public:
    void Nhap();
    float DienTich();
};
int main()
{
    DaGiac a;
    a.Nhap();
    cout << a.DienTich();
    return 0;
}
void DaGiac::Nhap()
{
    cin >> n;
    a = new DaGiac[n];
    for (int i = 0; i < n; i++)
        cin >> a[i].x >> a[i].y;
}
float DaGiac::DienTich()
{
    float s = 0;
    int j = n - 1;
    for (int i = 0; i < n; i++)
    {
        s += (a[j].x + a[i].x )* (a[j].y - a[i].y);
        j = i;
    }
    return abs(s/ 2);
}