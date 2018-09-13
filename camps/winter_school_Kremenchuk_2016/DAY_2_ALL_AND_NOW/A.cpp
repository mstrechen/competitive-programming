#include<iostream>
#include<vector>

using namespace std;


const int oo = 2*1000*1000*1000 + 1000;

int dp[1001][200][200];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int l, q;

    cin >> l >> q;

    vector<vector<int> > cost(l, vector<int>(l));
    for(auto & i : cost)
        for(auto & j : i)
            cin >> j;

    for(int i = 0; i<200; i++)
        for(int j = 0; j<200; j++)
            dp[0][i][j] = +oo;

    dp[0][1][2] = 0;

    int xprev = 0;
    for(int _i = 1; _i<=n; _i++)
    {
        int x;
        cin >> x;
        x--;
        for(int i = 0; i<l; i++)
            for(int j = 0; j<l; j++)
            {
                dp[_i][i][j] = inf;
            }
        for(int i = 0; i<l; i++)
            for(int j = 0; j<l; j++)
            {
                dp[_i][i][j] = [xprev]
            }

        xprev = x;
    }
    return 0;
}

