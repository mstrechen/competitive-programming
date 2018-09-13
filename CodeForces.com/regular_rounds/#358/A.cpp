#include<iostream>

using namespace std;

long long min(long long a, long long b)
{
    return a>b?b:a;
}
int main()
{
    ios::sync_with_stdio(false);
    long long n, m;
    long long ans = 0;
    cin >> n >> m;
    if(n>m)
        swap(n,m);
    for(int i = 1; i<=min(5,n); i++)
    {
        ans+=((n-i)/5+1)*((m+i%5)/5);
    }
    cout << ans;
    return 0;
}
