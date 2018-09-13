#include<iostream>
#include<vector>

using namespace std;

long long MOD = 1000*1000*1000 + 7;

long long phi(long long n)
{
    if(n==1)
        return 1;

    long long ans = 1;
    for(long long i = 2; i*i<=n; i++)
    if(n%i == 0)
    {
        long long p = i;
        n/=i;

        while(n%i == 0)
        {
            p*=i;
            n/=i;
        }
        ans*=(p - p/i);
    }
    if(n!=1)
        ans*=(n-1);
    return ans;
}

long long g(long long n)
{
    long long ans = 0;
    for(long long i = 1; i*i<=n; i++)
    if(n%i == 0)
    {
        ans += phi(i);
        cout << i << ':' << phi(i) << '#';
        if(i*i!=n)
            ans+= phi(n/i);
        ans%=MOD;
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    long long n, k;

    cin >> n >> k;

    for(int i = 1; i<=k && n!=1; i+=2)
    {
        cout << n << endl;
    }

    cout << n%MOD;



    return 0;
}
