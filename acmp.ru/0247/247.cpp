#include<iostream>
#include<vector>
#include<cassert>


using namespace std;

struct cost
{
    int value, used;
    cost(int value = 0, int used = 0):value(value), used(used){}
};

cost operator + (const cost & source, int additional)
{
    if(source.value==-1)
        return source;
    return cost(source.value+additional, source.used);
}

cost operator + (const cost & source, const pair<int,int> & additional)
{
    if(source.value==-1)
        return source;
    return cost(source.value + additional.first, source.used + additional.second);
}

cost min(const cost & a, const cost & b)
{
    if(a.value == -1)
        return b;
    if(b.value == -1)
        return a;
    if(a.value!=b.value)
        return (a.value < b.value) ? a : b;
    return a.used<b.used ? a:b;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    if(n==0)
    {
        cout << "0\n0 0";
        return 0;
    }

    vector<vector<cost> > dp(n+2, vector<cost>(n+2, cost(-1)));
    vector<int> days(n);
    dp[0][0] = cost(0,0);

    int currentCost;

    for(int i = 0; i<n; i++)
    {
        cin >> currentCost;

        dp[i+1][0] = min(dp[i][0]+currentCost, dp[i][1] + make_pair(0,1) );

        for(int j = 1; j<=n; j++)
        {
            if(currentCost>100)
                dp[i+1][j] = min(dp[i][j-1] + currentCost, dp[i][j+1] + make_pair(0,1));
            else
                dp[i+1][j] = min(dp[i][j] + currentCost, dp[i][j+1] + make_pair(0,1));
        }
    }


    int maxValue = n;

    for(int i = n-1; i>=0; i--)
    {
        if(dp[n][maxValue].value == -1 || dp[n][maxValue].value > dp[n][i].value)
        {
            maxValue = i;
        }
    }
    assert(dp[n][maxValue].value != -1);
    cout << dp[n][maxValue].value << '\n';
    cout << maxValue << ' ' << dp[n][maxValue].used;




    return 0;
}
