#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;



int main(){
    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> dp(n + 1, 0);
    int sum = 0;
    for(auto & i : a)
        cin >> i;

    for(int i = n - 1; i >= 0; i--){
        dp[i] = max(dp[i + 1], sum - dp[i + 1] + a[i]);
        sum += a[i];
    }

    cout << sum - dp[0] << ' ' << dp[0];


    return 0;
}
