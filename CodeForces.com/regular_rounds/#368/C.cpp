#include<iostream>
#include<cmath>

using namespace std;


bool findUsingCathetus(long long a)
{
    a = a*a;
    if(a%2==0&&a%4==2)
    {
        return 0;
    }
    if(a%4==0)
    {
        cout << a/4 - 1 << ' ' << a/4 + 1;
        return 1;
    }
    else
    {
        cout << (a-1)/2 << ' '<<(a+1)/2;
        return 1;
    }
    return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    long long a;
    cin >> a;
    if(a<3)
        cout << -1;
    else
        findUsingCathetus(a);
    return 0;
}
