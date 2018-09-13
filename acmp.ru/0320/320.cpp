#include<iostream>
#include<vector>

using namespace std;

int main()
{

    int n, m;
    cin >> m >> n;
    vector<long long> dp(n+m+1, 0);
    dp[0] = 1;
    for(int i = 0; i<n; i++)
    {
        dp[i+1]+=dp[i];
        dp[i+m]+=dp[i];
    }
    cout << dp[n];

    return 0;
}
