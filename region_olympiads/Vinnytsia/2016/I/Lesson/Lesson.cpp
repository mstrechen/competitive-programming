#include<iostream>
#include<string>

using namespace std;

int mymin(int a, int b)
{
    return a<b?a:b;
}

int dp[255+2][255+2];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string _s, s;
    cin >> _s;
    
    char prev = 0;
    s.reserve(256);

    for(int i = 0; i<_s.size(); i++)
    {
        if(_s[i]!=prev)
            s.push_back(prev = _s[i]);
    }
    int n = s.size();

    for(int i = 1; i<=n; i++)
        dp[i][i] = 1;

    for(int i = 2; i<=n; i++)
        for(int j = i-1; j>=1; j--)
            if(s[i-1]==s[j-1])
            {
                dp[i][j] = mymin(mymin(dp[i][j+1], dp[i-1][j]), dp[i-1][j+1]) + 1;
                for(int k = j+1; k<i; k++)
                {
                    if(s[i-1]==s[k-1])
                    {
                        dp[i][j] = mymin(dp[i][j], dp[i][k]+dp[k][j]-1);
                        dp[i][j] = mymin(dp[i][j], dp[k-1][j+1]+dp[i-1][k+1] + 1);
                    }
                }
            }
            else
            {
                dp[i][j] = 100500;
                
                for(int k = j; k<i; k++)
                    dp[i][j] = min(dp[i][j], dp[k][j]+dp[i][k+1]);
            }
            
    cout << dp[n][1];



    return 0;
}
