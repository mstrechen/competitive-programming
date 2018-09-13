#include<iostream>
#include<vector>

using namespace std;

const int MOD = 1000000;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int height;
    cin >> height;

    vector<vector<int> > dp(height+1, vector<int>(3,0));

    if(height>=10)
        dp[height-10][0] = 2;

    for(int i = height-11; i>=0; i--)
    {
        dp[i][0] = (dp[i+10][0] + dp[i+10][1] + dp[i+10][2])%MOD;
        dp[i][1] = dp[i+1][0];
        dp[i][2] = dp[i+1][1];
    }


    cout << (dp[0][0] + dp[0][1] + dp[0][2])%MOD;
    return 0;
}
