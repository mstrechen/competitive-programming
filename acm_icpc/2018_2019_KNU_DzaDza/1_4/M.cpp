#include<iostream>
#include<vector>
#include<algorithm>



using namespace std;

const long long INF = 1e18;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;

    cin >> n >> k;
    k++;
    vector<int> a(n);
    for(auto & i : a)
        cin >> i;

    vector<vector<long long> > dp(k + 1, vector<long long>(n + 1, INF));
    vector<vector<int> > dpPos(k + 1, vector<int>(n + 1, INF));

    vector<int> p(n + 1);
    p[0] = 0;
    for(int i = 0; i < n; i++)
        p[i + 1] = p[i] + a[i];

    dp[1][0] = INF;
    for(int i = 1; i <= n; i++){
        dp[1][i] = p[i] * 1LL * p[i];
    }

    for(int _L = 2; _L <= k; _L++){
        for(int i = _L; i <= n; i++){
            if(i == _L){
                dp[_L][i] = a[i - 1] * 1LL * a[i - 1] + dp[_L - 1][i - 1];
                dpPos[_L][i] = i - 1;
                continue;
            }


            int l = _L - 1, r = i;
            while(l + 3 < r){
                int mid1 = (l * 2 + r) / 3;
                int mid2 = (l + r * 2) / 3;

                long long s1 = p[i] - p[mid1];
                long long ans1 = dp[_L - 1][mid1] + s1 * s1;
                long long s2 = p[i] - p[mid2];
                long long ans2 = dp[_L - 1][mid2] + s2 * s2;
                if(ans2 > ans1)
                    r = mid2;
                else
                    l = mid1;
            }
            long long minAns = INF;
            int INDEX = 0;
            for(int j = l; j < r; j++){
                long long s1 = p[i] - p[j];
                long long ans1 = dp[_L - 1][j] + s1 * s1;
                minAns = min(ans1, minAns);
                if(ans1 == minAns)
                    INDEX = j;
            }
            dp[_L][i] = minAns;
            dpPos[_L][i] = INDEX;
        }

    }
    cout << (p[n] * 1LL * p[n] - dp[k][n])/2 << endl;
    vector<int> ans;
    for(int i = dpPos[k][n], ps = k; i > 0; i = dpPos[--ps][i]){
        ans.push_back(i);
    }
    sort(ans.begin(), ans.end());
    for(auto & i : ans)
        cout << i << ' ';

    return 0;
}

