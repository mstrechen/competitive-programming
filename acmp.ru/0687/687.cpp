#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin >> n >> m;

    vector<vector<long long> > dp(n+2, vector<long long>(m, (1LL<<36LL) -1 ));

    for(int i = 1; i<=n; i++)
        for(int j = 0; j<m; j++)
            cin >> dp[i][j];


    for(int j = 1; j<m; j++)
        for(int i = 1; i<=n; i++)
            dp[i][j]+=min(dp[i][j-1],min(dp[i-1][j-1], dp[i+1][j-1]));

    int maxI = 1;

    for(int i = 2; i<=n; i++)
        if(dp[i][m-1]<dp[maxI][m-1])
            maxI = i;

    vector<int> ans(1,maxI);

    for(int j = m-1; j>0; j--)
    {
        if(dp[maxI-1][j-1]<=dp[maxI ][j-1]&&
           dp[maxI-1][j-1]<=dp[maxI+1][j-1])
            maxI--;
        else
        if(dp[maxI][j-1]<=dp[maxI+1][j-1]&&
           dp[maxI][j-1]<=dp[maxI-1][j-1])
            maxI;
        else
            maxI++;

        ans.push_back(maxI);
    }

    reverse(ans.begin(), ans.end());

    for(auto i : ans)
        cout << i << ' ';

    cout << '\n' << dp[ans.back()][m-1];

    return 0;
}
