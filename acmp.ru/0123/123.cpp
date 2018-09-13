#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string source;

    cin >> source;

    vector<vector<int> > dp(source.size()+1, vector<int>(source.size()+1, 0));

    dp[0][0] = 1;

    for(int len = 1; len<=(int)source.size(); len++)
    {
        if(source[len-1] == '?')
        {
            for(int balance = 1; balance<(int)source.size(); balance++)
                dp[len][balance] = dp[len-1][balance-1] + dp[len-1][balance+1];
            dp[len][0] = dp[len-1][1];
        }
        else
        if(source[len-1] == '(')
        {
            for(int balance = 1; balance<(int)source.size(); balance++)
                dp[len][balance] = dp[len-1][balance-1];
        }
        else
        {
            for(int balance = 0; balance<(int)source.size(); balance++)
                dp[len][balance] = dp[len-1][balance+1];
        }

    }

    cout << dp[source.size()][0];

    return 0;
}
