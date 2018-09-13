#include<iostream>
#include<sstream>
#include<string>
#include<vector>

using namespace std;

void makeMin(string & toChange, const string & toCheck)
{
    if(toChange.size() > toCheck.size())
        toChange = toCheck;
}

bool checkEq(int l, int r, int len, const string & s)
{
    if((r-l)%len != 0)
        return 0;

    while(l+len!=r)
    {
        for(int i = 0; i<len; i++)
            if(s[l+i]!=s[l+len+i])
                return 0;
        l+=len;
    }
    return 1;
}

string intToString(int toWrite)
{
    static ostringstream os;
    os.str("");
    os << toWrite;
    return os.str();
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    vector<vector<string> > dp(s.size(), vector<string>(s.size()));

    for(int i = 0; i<(int)s.size(); i++)
        dp[i][i]+=s[i];

    for(int r = 1; r<(int)s.size(); r++)
    {
        for(int l = r-1; l>=0; l--)
        {
            dp[l][r] = string(s.begin()+l, s.begin()+r+1);

            for(int d = 1; d<(r-l+1); d++)
                if(checkEq(l,r+1, d, s))
                {
                    makeMin(dp[l][r], intToString((r-l+1)/d) + "(" + dp[l][l+d-1] + ")");

                }

            for(int mid = l; mid<r; mid++)
                makeMin(dp[l][r], dp[l][mid]+dp[mid+1][r]);
        }
    }

    cout << dp[0][s.size()-1];

    return 0;
}
