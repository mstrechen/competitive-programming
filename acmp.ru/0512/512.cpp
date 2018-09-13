#include<iostream>
#include<vector>

using namespace std;

struct DP
{
    vector<vector<long long> > dp;
    vector<vector<char> > e;
    int n, m, k;

    DP(istream & in)
    {
        in >> n >> m >> k;

        dp.assign(1<<n, vector<long long>(1<<m, -1));
        e.assign(n,vector<char>(m,0));

        for(int i = 0; i<n; i++)
            for(int j = 0; j<m; j++)
            {
                in >> e[i][j];
                if(e[i][j] == 'Y')
                    e[i][j] = 1;
                else
                    e[i][j] = 0;
            }
    }

    long long getAns(int kLeft, int maskB = 0, int maskG = 0)
    {
        if(dp[maskB][maskG]!=-1)
            return dp[maskB][maskG];
        if(kLeft == 0)
            return dp[maskB][maskG] = 1;

        long long ans = 0;

        for(int b = 0; b<n; b++)
            if(((maskB>>b)&1) == 0)
                for(int g = 0; g<m; g++)
                    if(((maskG>>g)&1) == 0 && e[b][g])
                    {
                        ans += getAns(kLeft-1, maskB | (1<<b), maskG | (1<<g));
                    }
        return dp[maskB][maskG] = ans;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    DP dp(cin);

    long long ans = dp.getAns(dp.k);

    for(int i = 2; i<=dp.k; i++)
        ans/=i;

    cout << ans;
    return 0;
}
