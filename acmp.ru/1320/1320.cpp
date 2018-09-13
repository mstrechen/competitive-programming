#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int findCount(const string & findIn, const string & findWhat)
{
    unsigned int pos = 0;
    int ans = 0;
    while((pos = findIn.find(findWhat, pos))!=string::npos)
    {
        pos++;
        ans++;
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int nFib;
    string sIn;

    cin >> nFib >> sIn;

    vector<long long> dp(nFib+2, 0);

    string sPrev = "B", sPPrev = "A", tmp;


    int positionOfFirst;


    for(positionOfFirst = 2; sIn.size()>sPPrev.size(); positionOfFirst++)
    {
        tmp = sPrev + sPPrev;
        sPPrev = sPrev;
        sPrev = tmp;
    }


    dp[positionOfFirst] = findCount(sPrev, sIn);
    dp[positionOfFirst-1] = findCount(sPPrev, sIn);


    long long count12 = findCount(sPrev+sPPrev,sIn) - dp[positionOfFirst] - dp[positionOfFirst-1];
    long long count21 = findCount(sPPrev+sPrev,sIn) - dp[positionOfFirst] - dp[positionOfFirst-1];

    for(int i = positionOfFirst+1; i<=nFib; i++)
    {

        dp[i] = dp[i-1] + dp[i-2];
        dp[i]+=count12;
        swap(count12,count21);
    }

    cout << dp[nFib] << endl;

    return 0;
}
