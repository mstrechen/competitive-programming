#include<iostream>
#include<vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<int> dp(26, 0); 
    for(auto & i : s)
        dp[i - 'a'] = 1;
    
    for(int i = 0; i < 26; i++)
        if(dp[i] == 1){
            for(int j = 0; j + 1 < i; j++)
                dp[i] = max(dp[j] + 1, dp[i]);
            
            if(dp[i] == m){
                int sum = 0;
                for(int j = i, cont = i, step = m; step > 0; j = cont, step--){
                    sum += j + 1;
                    for(int k = 0; k < j; k++)
                        if(dp[k] == dp[j] - 1){
                            cont = k;
                            break;
                        }
                }
                cout << sum;
                return 0;
            }
        }

    cout << -1;

    return 0;
}