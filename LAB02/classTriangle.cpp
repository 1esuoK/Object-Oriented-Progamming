#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
#define PI 3.14
using namespace std;
class ToaDo {
private:
    float x, y;
    ToaDo* Triangle;
public:
    void Nhap();
    void Xuat();
    void TinhTienDiem(float,float);
};
int main()
{
    ToaDo a;
    float degree, d;
    a.Nhap();
    cin >> degree >> d;
    a.TinhTienDiem(degree,d);
    a.Xuat();
    return 0;
}
void ToaDo::Nhap()
{
    Triangle = new ToaDo[3];
    for (int i = 0; i < 3; i++)
        cin >> Triangle[i].x >> Triangle[i].y;
}
void ToaDo::Xuat()
{
    for (int i = 0; i < 3; i++)
        cout << "(" << Triangle[i].x << "," << Triangle[i].y << ")" << endl;
}
void ToaDo::TinhTienDiem(float degree, float d)
{
    float rad = (degree * PI) / 180;
    for (int i = 0; i < 3; i++)
    {
        Triangle[i].x += cos(rad) * d;
        Triangle[i].y += sin(rad) * d;
    }
}