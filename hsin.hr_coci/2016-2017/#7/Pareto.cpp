#include<iostream>
#include<algorithm>
#include<functional>
#include<vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> accounts(n);

    double allsum = 0;
    for(auto & i : accounts)
    {
        cin >> i;
        allsum += i;
    }

    pair<double, double> ans = {0,0};

    double sum = 0;

    sort(accounts.begin(), accounts.end(), greater<int>());

    for(int i = 0; i<n; i++)
    {
        sum+=accounts[i];
        double accPercent = double(i+1)/n,
               moneyPercent = sum/allsum;

        if(moneyPercent-accPercent>ans.second - ans.first)
        ans = {accPercent, moneyPercent};
    }

    cout << ans.first*100  << ' ' << ans.second*100;




    return 0;
}
