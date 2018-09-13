#include<iostream>

using namespace std;

long long _gcd(long long a,long long b)
{
    if(a==0)
        return b;
    else
        return _gcd(b%a, a);
}

long long min(long long a, long long b)
{
    return a<b?a:b;
}
int main()
{
    long long n, a, b, p, q, ab;
    cin  >> n >> a >> b >> p >> q;
    ab = a*b/_gcd(a,b);
    cout << (n/a)*p+(n/b)*q-(n/ab)*min(p,q);

    return 0;
}
