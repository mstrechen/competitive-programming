
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(n);
    for(auto & i : a)
        cin >> i;
    for(auto & i : b)
        cin >> i;
    if(find(a.begin(), a.end(), 1) != a.end() || 
       find(b.begin(), b.end(), 1) != b.end()){
           cout << "-1";
           return 0;
    }
    
    vector<double> dp(2 * n + 1);
    dp[2 * n] = m;
    
    for(int i = 2 * n - 1; i >= 0; i--){
        if(i % 2 == 1)
            dp[i] = dp[i + 1] + dp[i + 1]/(b[i / 2] - 1.0);
        else
            dp[i] = dp[i + 1] + dp[i + 1]/(a[i / 2] - 1.0);
    }

    cout.precision(10);
    cout << (fixed) << dp[0] - m;


    return 0;
}