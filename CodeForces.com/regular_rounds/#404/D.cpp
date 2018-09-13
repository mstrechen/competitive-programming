#include<iostream>
#include<vector>
#include<numeric>

using namespace std;

const int MOD = 1000*1000*1000 + 7;
const int SIZE = 200*1000;

long long sqr(long long a)
{
    return (a*a)%MOD;
}

long long binpow(long long x, long long a)
{
    if(a == 0)
        return 1;
    if(a&1)
        return (x*sqr(binpow(x,a/2)))%MOD;
    return sqr(binpow(x, a/2));
}

int main()
{
    string s;
    cin >> s;

    vector<long long> factUp(s.size()+1), factDown(s.size()+1);

    factUp[0] = 1;
    factDown[0] = 1;

    for(int i = 1; i<=(int)s.size(); i++)
    {
        factUp[i] = factUp[i-1]*i;
        factDown[i] = factDown[i-1]*binpow(i, MOD-2);
        factUp[i]%=MOD;
        factDown[i]%=MOD;
    }

    int open = 0, close = accumulate(s.begin(), s.end(), 0, [](int a, char c){return a + (c==')');});

    long long ans = 0;
    for(int i = 0; i<(int)s.size(); i++)
    if(s[i] == '(')
    {
        open++;
        if(open>0 && close>0)
        {
            ans+=(((factUp[open+close-1]*factDown[open])%MOD)*factDown[close-1]);
        }
        ans%=MOD;
    }
    else
    {
        close--;
    }

    cout << ans;
    return 0;
}
