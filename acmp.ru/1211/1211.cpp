#include<iostream>

using namespace std;

unsigned long long gcd(unsigned long long a,unsigned long long b)
{
    if(a&&b)
        return gcd(b,a%b);
    return a+b;
}

unsigned long long getLCM(unsigned long long a, unsigned long long b)
{
    int k = 0;
    a/=gcd(a,b);
    while(a>=10)
    {
        a/=10;
        k++;
    }
    while(b>=10)
    {
        b/=10;
        k++;
    }
    k+=(bool)((a*b)/10);
    if(k>18)
        return 1000000000000000005ULL;
    else
        return a*b;

}


unsigned long long getCountOfCuted(unsigned long long a, unsigned long long n,
                                   unsigned long long b, unsigned long long m,
                                   unsigned long long days)
{
    return days*(a+b) - (days/n)*a - (days/m)*b + (days/getLCM(n,m))*(a+b);
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    unsigned long long a,b,n,m,x;


    unsigned long long l = 1, r = 1000000000000000005ULL;

    cin >> a >> n >> b >> m >> x;
    while(l+1<r)
    {
        auto mid = (l+r-1)/2+1;

        if(getCountOfCuted(a,n,b,m,mid)<x)
            l = mid;
        else
            r = mid;
    }

    cout << r;

    return 0;
}
