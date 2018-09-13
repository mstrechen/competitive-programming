#include<iostream>
#include<vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    cin >> n;

    vector<vector<int> > field(n+1, vector<int>(n, 0) ),
                         dp(n+1, vector<int>(n+1, 0));

    for(int i = 1; i<=n; i++)
        for(int j = 0; j<n; j++)
            cin >> field[i][j];


    for(int l = 0; l<n; l++)
    {
        if(l!=0)
        {
            for(int curSum = 0; curSum<=n; curSum++)
            {
                for(int nextSum = curSum; nextSum<=n; nextSum++)
                    dp[l+1][nextSum] = max(dp[l+1][nextSum], dp[l][curSum] + field[nextSum-curSum][l]);
            }
        }
        else
        {
            int curSum = 0;
            for(int nextSum = curSum; nextSum<=n; nextSum++)
                    dp[l+1][nextSum] = max(dp[l+1][nextSum], dp[l][curSum] + field[nextSum-curSum][l]);
        }

    }

    cout << dp[n][n];



    return 0;
}
