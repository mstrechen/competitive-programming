#include<iostream>
#include<vector>

using namespace std;

const long long MOD = 1000*1000*1000 + 7;

long long sqr(long long x)
{
    return (x*x)%MOD;
}

long long binPow(long long x, long long a)
{
    if(a==0)
        return 1;
    if(a&1)
        return (sqr(binPow(x,a/2))*x)%MOD;
    return sqr(binPow(x,a/2));
}

struct BinomialGetter
{
    vector<long long> upFact, downFact;

    BinomialGetter(int n) : upFact(n+1), downFact(n+1)
    {
        upFact[0] = 1;
        downFact[0] = 1;

        for(int i = 1; i<=n; i++)
        {
            upFact[i] = (upFact[i-1]*i)%MOD;
            downFact[i] = (downFact[i-1]*binPow(i, MOD-2))%MOD;
        }
    }

    long long cnk(long long n, long long k)
    {
        if(k<0 || n<0 || k>n)
            return 0;
        return (((upFact[n]*downFact[k])%MOD)*downFact[n-k])%MOD;
    }
};


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    BinomialGetter BG(200000);

    int food, wine, h;
    cin >> food >> wine >> h;

    long long all = 0;
    long long good = 0;


    for(int foodCnt = 1; foodCnt<=food; foodCnt++)
        for(int wineCnt = foodCnt-1; wineCnt<=foodCnt+1; wineCnt++)
        {
            all+=(BG.cnk(food - 1, foodCnt - 1) * BG.cnk(wine - 1, wineCnt - 1) * (1+(wineCnt==foodCnt)))%MOD;
            good+=(BG.cnk(food - 1, foodCnt - 1) * BG.cnk(wine  - wineCnt*1LL*h - 1, wineCnt - 1) * (1+(wineCnt==foodCnt)))%MOD;
        }
    if(food == 0)
    {
        all = 1;
        good = (wine>h);
    }
    if(wine == 0)
    {
        all = 1;
        good = 1;
    }

    all%=MOD;
    good%=MOD;
    cout << (good*binPow(all, MOD-2))%MOD;


    return 0;
}
