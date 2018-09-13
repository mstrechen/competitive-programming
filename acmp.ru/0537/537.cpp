#include<iostream>
#include<vector>
#include<algorithm>
#include<cassert>

using namespace std;

int gcd(int a, int b)
{
    if(a&&b)
        return gcd(b%a, a);
    return a+b;
}

void gcdMas(vector<int> & a, vector<vector<int> > & saved)
{
    for(int i = 0; i<(int)a.size(); i++)
        for(int j = 0; j<(int)a.size(); j++)
            saved[i][j] = gcd(a[i],a[j]);
}
int gcdMasGet(int i, int j, vector<vector<int> > & saved)
{
    return saved[i][j];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, minGcd;
    long long toFind;

    cin >> n >> toFind >> minGcd;

    vector<int> a(n);
    for(auto & i : a)
        cin >> i;

    if(n==1)
    {
        if(toFind == 1)
            cout << a[0];
        else
            cout << -1;
        return 0;
    }

    sort(a.begin(), a.end());
    a.push_back(0);

    vector<int> masks((1<<n) - 2);

    for(int i = 0; i<(int)masks.size(); i++)
        masks[i] = i+1;

    sort(masks.begin(), masks.end(), [](int a, int b){return __builtin_popcount(a) < __builtin_popcount(b);});


    vector<vector<long long> > dp(n, vector<long long>(1<<n, 0));
    vector<vector<int> > savedGcd(n+1, vector<int>(n+1));
    gcdMas(a,savedGcd);

    for(int i = 0; i<n; i++)
        dp[i][1<<i] = 1;

    for(auto & mask : masks)
        for(int i = 0; i<n; i++)
        if(mask & (1<<i))
        {
            for(int j = 0; j<n; j++)
                if( (mask & (1<<j)) == 0 && gcdMasGet(i, j, savedGcd)>= minGcd)
                {
                    dp[j][mask | (1<<j)]+=dp[i][mask];
                }
        }

    long long allCount = 0;
    for(int i = 0; i<n; i++)
        allCount+=dp[i][(1<<n) - 1];

    if(allCount < toFind)
        cout << -1;
    else
    {
        vector<int> ans(n);

        int mask = (1<<n) - 1;
        int last = n;
        for(int i = 0; i<n; i++)
        {
            int j = 0;
            bool flag = 1;

            while(flag)
            {
                if( ((mask>>j) & 1) && gcdMasGet(last, j,savedGcd) >= minGcd )
                {
                    if(dp[j][mask] >=toFind)
                        flag = 0;
                    else
                    {
                        toFind-=dp[j][mask];
                        j++;
                    }
                }
                else
                {
                    j++;
                }
            }
            last = j;
            ans[i] = j;
            mask -= (1<<j);
        }
        for(auto & i : ans)
            cout << a[i] << ' ';
    }

    return 0;
}
