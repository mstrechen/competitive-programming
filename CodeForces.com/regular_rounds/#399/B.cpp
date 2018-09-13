#include<iostream>

using namespace std;

long long get(long long n)
{
    while(n&(n-1))
        n&=(n-1);
    return 2*n - 1;
}

long long rec(unsigned long long n, long long r)
{
    if(r<0)
        return 0;
    if(n<2)
        return n;

    long long mid = get(n/2);

    if(r<mid)
        return rec(n/2, r);
    if(r == mid)
        return n/2 + n%2;

    return n/2 + n%2 + rec(n/2, r-mid-1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, l, r;

    cin >> n >> l >> r;
    cout << rec(n,r-1) - rec(n, l-2);

    return 0;
}
