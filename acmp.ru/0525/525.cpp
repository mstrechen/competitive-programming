#include<iostream>
#include<vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, pow2;
    cin >> n;

    pow2 = 32 - __builtin_clz(n);

    vector<vector<int> > dp(pow2, vector<int>(n+1, 1) );

    for(int curPow2 = 1; curPow2 < pow2; curPow2++)
    {
        for(int i = 1; i<=n; i++)
        {
            dp[curPow2][i] = 0;
            for(int pp = 0; pp<=curPow2 && ((1<<pp)<=i ); pp++)
            {
                dp[curPow2][i]+=dp[pp][i-(1<<pp)];
            }
        }
    }

    cout << dp[pow2-1][n];


    return 0;
}
