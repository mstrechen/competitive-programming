#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int maxlen;

    cin >> maxlen;

    int maxsum = maxlen*9 + 1;

    if(maxlen == 1)
    {
        cout << 10 << ' ' << 0;
        return 0;
    }
    vector<vector<vector<long long> > > dp(maxlen, vector<vector<long long> >(maxsum, vector<long long>(maxsum, 0) ) );
    vector<vector<vector<string> > > dpAns(maxlen);

    dpAns[0] = vector<vector<string> >(maxsum, vector<string>(maxsum, ""));
    for(int i = 1; i<=9; i++)
    {
        dp[0][i][i] = 1;
        dpAns[0][i][i].assign(1, char('0'+i));
    }
    for(int len = 1; len<maxlen; len++)
    {
        dpAns[len] = vector<vector<string> >(maxsum, vector<string>(maxsum, "") );
        for(int digitsSum = 1; digitsSum<maxsum; digitsSum++)
            for(int digitsMul = 1; digitsMul<maxsum; digitsMul++)
                for(int i = 1; i<=9; i++)
                    if(digitsMul%i == 0 && digitsSum>i)
                    {
                        if(dp[len-1][digitsSum-i][digitsMul/i])
                        {
                            dp[len][digitsSum][digitsMul]+=dp[len-1][digitsSum-i][digitsMul/i];
                            if(dpAns[len][digitsSum][digitsMul] == "" || dpAns[len-1][digitsSum-i][digitsMul/i] + char('0'+i) < dpAns[len][digitsSum][digitsMul])
                                dpAns[len][digitsSum][digitsMul] = dpAns[len-1][digitsSum-i][digitsMul/i] + char('0'+i);
                        }
                    }

        dpAns[len-1].clear();
    }

    long long ans = 0;
    string minans = "99999999999999999999";

    for(int i = 1; i<maxsum; i++)
    if(dp[maxlen-1][i][i])
    {
        ans+=dp[maxlen-1][i][i];
        minans = min(dpAns[maxlen-1][i][i], minans);
    }

    cout << ans << ' ' <<  minans;





    return 0;
}
