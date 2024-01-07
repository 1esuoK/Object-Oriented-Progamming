#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class List {
private:
    double* arr;
    unsigned int size;
public:
    void Add();
    void DeleteFirst();
    void DeleteX();
    void Command();
    void Print();
    void Replace();
    void Init();
};
int main()
{
    List a;
    a.Init();
    a.Command();
    return 0;
}
void List::Init()
{
    arr = new double[100];
    size = 0;
}
void List::Add()
{
    /*size = 0;
    arr = new double[100];*/
    double x;
    cin >> x;
    arr[size++] = x;
}
void List::DeleteFirst()
{
    double x;
    cin >> x;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == x)
        {
            for (int j = i; j < size - 1; j++)
            {
                arr[j] = arr[j + 1];
            }
            size--;
            break;
        }
    }
}
void List::DeleteX()
{
    double x;
    cin >> x;
    for(int i=0;i<size;i++)
    {
        if (arr[i] == x)
        {
            for(int j=i;j<size-1;j++)
            {
            arr[j] = arr[j + 1];
            }   
            size--;
        }
    }
}
void List::Replace()
{
    int x;
    double y;
    cin >> x >> y;
    if(x>=0 && x<size) arr[x] = y;
}
void List::Print()
{
    cout << "[";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i];
        if (i != size - 1) cout << ",";
    }
    cout << "]";
}
void List::Command()
{
    int n;
    do {
        cin >> n;
        switch (n) {
        case -1:
            Print();
            break;
        case 0:
            Add();
            break;
        case 1:
            DeleteFirst();
            break;
        case 2:
            DeleteX();
            break;
        case 3:
            Replace();
            break;
        default:
            break;
        }
    } while (n != -1);
}