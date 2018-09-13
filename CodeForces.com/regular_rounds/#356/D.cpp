#include<iostream>
#include<fstream>
#include<cmath>
#include<algorithm>

using namespace std;


long long get(long long _a)
{
    if(_a==0)
        return 0;
    long long  a = cbrt(_a+1e-10);
    return 1+get(_a-a*a*a);
}
int main()
{
    ios::sync_with_stdio(false);
    ofstream cout("out.txt");
    int n = 100000;
    int _m=1, last= 1,tmp;

    for(int i = 1; i<n; i++)
    {
        tmp = get(i);
        if(tmp>_m)
        {
            _m = tmp;
            last = i;
        }
        if(tmp==_m)
            cout << i-last << ',';
    }

    return 0;
}

