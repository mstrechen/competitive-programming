#include<iostream>
#include<cmath>
#include<fstream>

using namespace std;

long long abs(long long a)
{
    return a>0?a:-a;
}
int main()
{
    long long n,k;
    long long  row,place;
    long long placeOf1st;
    cin >> n >> k;
    cin >> row >> place;
    placeOf1st = row*2+place-2;
    if(placeOf1st+k>n&&placeOf1st-k<1)
        cout << -1;
    else
    if(placeOf1st+k<=n&&placeOf1st-k>0)
    {
        if(abs(row-(placeOf1st-k+1)/2)<abs(row-(placeOf1st+k+1)/2))
            placeOf1st-=k;
        else
            placeOf1st+=k;
    }
    else
    if(placeOf1st+k>n)
    {
        placeOf1st-=k;
    }
    else
    {
        placeOf1st+=k;

    }
     cout << (placeOf1st+1)/2 << ' '  << (placeOf1st+1)%2 + 1;
    return 0;
}
