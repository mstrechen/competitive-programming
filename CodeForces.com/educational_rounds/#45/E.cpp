#include<iostream>
#include<vector>
#include<set>
#include<functional>

using namespace std;

int check(set<int, greater<int> > & allowed, int n, int k){
    if(allowed.count(0) == 0)
        return 0;
    int ans = 1;
    int cur = 0;
    while(cur + k < n){
        ans++;
        int tmp = *allowed.lower_bound(0 + k + 1);
        if(tmp == cur)
            return 0;
        cur = tmp;
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;
    set<int, greater<int> > allowed;
    for(int i = 0; i < n; i++)
        allowed.insert(i);
    for(int i = 0; i < m; i++){
        int x;
        cin >> x;
        allowed.erase(x);
    }
    if(check(allowed, n, k) == 0){
        cout << -1;
        return 0;
    }
    vector<int> costs(k);
    for(auto & i : costs)
        cin >> i;

    int l = 1, r = k + 1;

    while(l + 1 < r){
        int mid = (l + r)/2;
        if(check(allowed, n, mid) == 0)
            l = mid + 1;
        else
            r = mid + 1;
    }
    long long minAns = 1e18;

    for(int i = l; i <= k; i++){
        minAns = min(minAns,
        check(allowed, n, i) * 1LL * costs[i - 1]);
    }
    cout << minAns;

        
    


    return 0;
}