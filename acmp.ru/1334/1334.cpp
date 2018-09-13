#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int oo = 2*1000*1000*1000;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> cards(n);
    vector<vector<int> >    dp(n, vector<int>(n, 0));

    for(auto & i : cards)
        cin >> i;

    for(int r = 2; r<n; r++)
    {
        for(int l = r-2; l>=0; l--)
        {
            dp[l][r] = +oo;
            for(int mid = l+1; mid<r; mid++)
                dp[l][r] = min(dp[l][r], dp[l][mid] + dp[mid][r] + cards[l]*cards[mid]*cards[r]);
        }
    }

    cout << dp[0][n-1];

    return 0;
}
