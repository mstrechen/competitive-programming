#include<iostream>
#include<string>
#include<vector>

using namespace std;

const int oo = 2*1000*1000*1000;

char getClose(char c)
{
    if(c=='(')
        return ')';
    else
    if(c=='{')
        return '}';
    else
    if(c=='[')
        return ']';

    return '?';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;


    vector<vector<int> > dp(s.size(), vector<int>(s.size(), +oo));

    for(int i = 0; i<(int)s.size(); i++)
        dp[i][i] = 1;

    for(int i = 1; i<(int)s.size(); i++)
    if(getClose(s[i-1])==s[i])
    {
        dp[i-1][i] = 0;
    }
    else
    {
        dp[i-1][i] = 2;
    }

    for(int r = 1; r<(int)s.size(); r++)
    {
        for(int l = r-2; l>=0; l--)
        {
            if(getClose(s[l])==s[r])
            {
                dp[l][r] = dp[l+1][r-1];
            }
            for(int mid = l; mid<r; mid++)
                dp[l][r] = min(dp[l][mid]+dp[mid+1][r], dp[l][r]);

        }
    }

    cout << dp[0][(int)s.size()-1];

    return 0;
}
