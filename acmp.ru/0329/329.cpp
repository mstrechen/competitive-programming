#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    vector<pair<int,int>> dp(n);
    
    cin >> dp[0].first;
    cin >> dp[1].first;
    
    dp[0].second = -1;
    
    dp[1] = max(make_pair(dp[1].first, -1), make_pair(dp[0].first+dp[1].first, 0));
    
    int tmp;
    for(int i = 2; i<n; i++)
    {
        cin >> tmp;
        dp[i] = max(make_pair(dp[i-1].first, i-1), make_pair(dp[i-2].first, i-2));
        dp[i].first+=tmp;
    }
    
    vector<int> ans;
    int current = n-1;
    while(current!=-1)
    {
        ans.push_back(current);
        current = dp[current].second;
    }
    
    cout << dp[n-1].first << '\n';
    for(auto it = ans.rbegin(); it!=ans.rend(); it++)
        cout << *it + 1 << ' ';
    
    
	
	return 0;
}