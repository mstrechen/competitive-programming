#include<iostream>
#include<string>
#include<cmath>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double ans = 0;
    for(int i = 1; i<=200000; i++)
         ans+= 200000.0/i;
    cout << (fixed) << ans;
    return 0;
}

