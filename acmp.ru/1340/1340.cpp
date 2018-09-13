#include<iostream>
#include<string>
#include<vector>
#include<cassert>

using namespace std;

const int oo = 1000*1000*1000;

char getClose(char c)
{
    if(c=='(')
        return ')';
    else
    if(c=='[')
        return ']';

    return c;
}
char getOpen(char c)
{
    if(c==')')
        return '(';
    else
    if(c==']')
        return '[';

    return c;
}

struct dpInside
{
    int cost;
    string s;
    dpInside(int cost = 0, string s = "") : cost(cost), s(s){}

    dpInside(char c) : cost(1), s("")
    {
        if(c==getOpen(c))
        {
            s += c;
            s += getClose(c);
        }
        else
        {
            s += getOpen(c);
            s += c;
        }
    }
};

dpInside operator + (const dpInside & l, const dpInside & r)
{
    return dpInside(l.cost+r.cost, l.s+r.s);
}

bool operator < (const dpInside & l, const dpInside & r)
{
    return l.cost < r.cost;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    getline(cin, s);

    if(s.size()==0)
    {
        cout << "";
        return 0;
    }





    vector<vector<dpInside> > dp(s.size(), vector<dpInside>(s.size()));

    for(int i = 0; i<(int)s.size(); i++)
        dp[i][i] = dpInside(s[i]);

    for(int r = 1; r<(int)s.size(); r++)
    {
        for(int l = r-1; l>=0; l--)
        {
            dp[l][r] = {+oo, ""};
            if(getClose(s[l])==s[r]&&s[l]!=getClose(s[l]))
            {
                dp[l][r] = dp[l+1][r-1];
                dp[l][r].s = s[l] + dp[l][r].s;
                dp[l][r].s+=s[r];

            }
            for(int mid = l; mid<r; mid++)
                dp[l][r] = min(dp[l][mid]+dp[mid+1][r], dp[l][r]);

        }
    }
    cout << dp[0][(int)s.size()-1].s << '\n';

    return 0;
}
