#include<iostream>
#include<cmath>

using namespace std;

int a[1000*1000];

void make(int n)
{
    for(int i = 2; i*i<n; i++)
        if(!a[i])
            for(int j = 2; j*i<n; j++)
                a[i*j] = 1;
}





int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long l, r;
    cin >> l >> r;

    make(cbrt(r) + 100);

    int ans = 0;
    for(long long i = 2; i*i*i<=r; i++)
        if(i*i*i >= l)
        {
            ans += 1 - a[i];
        }
    cout << ans;

    return 0;
}
