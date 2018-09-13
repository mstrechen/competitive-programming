#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int oo = 2*1000*1000*1000;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<pair<int,int> > pieces(n);

    for(auto & i : pieces)
        cin >> i.first >> i.second;

    vector<vector<int> > dp(n, vector<int>(n, 0) );

    for(int i = n-2; i>=0; i--)
    {
        for(int j = i+1; j<n; j++)
        {
            int tmp = +oo;
            for(int k = i; k<j; k++)
            {
                tmp = min(tmp, dp[i][k]+dp[k+1][j]);
            }
            tmp+=pieces[i].first*pieces[j].second;
            dp[i][j] = tmp;
        }
    }

    cout << dp[0][n-1];


    return 0;
}
