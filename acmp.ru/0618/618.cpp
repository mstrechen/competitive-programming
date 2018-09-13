#include<iostream>
#include<algorithm>
#include<functional>

using namespace std;

struct DP
{
    int maxVal;
    vector<vector<vector<long long> > > dp; // dp[pos][len][val]

    DP(const vector<int> & a) :
       maxVal(a.back()),
       dp(a.size(),vector<vector<long long> > (a.size(),vector<long long>(maxVal+1, 0) ) )
    {
        for(int i = 1; i<=a[0]; i++)
        {
            dp[0][0][i] = 1;
        }
        for(int pos = 1; pos<(int)a.size(); pos++)
        {

            for(int val = 1; val<=a[pos]; val++)
                dp[pos][0][val] = 1;
            for(int len = 1; len<=pos; len++)
                for(int val = 1; val<=a[pos]; val++)
                {
                    long long tmp = 0;
                    for(int prevVal = 1; prevVal<=val; prevVal++)
                    {
                        tmp+=dp[pos-1][len-1][prevVal];
                    }
                    dp[pos][len][val] = tmp;
                }

        }
    }

    long long cnt()
    {
        long long ans = 0;
        for(int i = 0; i<(int)dp.size(); i++)
            for(int j = dp[0][0].size()-1; j>0; j--)
            {
                ans+=dp[dp.size()-1][i][j];
            }
        return ans;
    }



};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << DP({1,2,3,4,5+0,6+0,7+3}).cnt() << endl;

    int n = 1, sum;
    cin >> sum;

    while((n+1)*(n+2)/2 <=sum) n++;

    vector<int> setup;
    for(int i = 1; i<=n; i++)
        setup.push_back(i);

    setup.back()+=sum - n*(n+1)/2;



    cout << DP(setup).cnt() << '\n';

    for(int i = (int)setup.size() - 1; i>=0; i--)
        cout << setup[i] << ' ';

    return 0;
}
