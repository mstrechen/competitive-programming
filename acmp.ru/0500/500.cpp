#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

const int oo = 1000000005;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<int,int> > agents(n);

    for(auto& i : agents)
        cin >> i.first >> i.second;

    sort(agents.begin(),agents.end());

    vector<int> dp(n+1,+oo);
    dp[0] = 0;

    int current;

    for(int i = 2; i<=n; i++)
    {
        current = 0;
        for(int j = 1; j<i; j++)
        {
            current+=agents[i-j].second;
            dp[i] = min(dp[i], current+dp[i-j-1]);
        }
    }
    cout << dp[n];





    return 0;
}
