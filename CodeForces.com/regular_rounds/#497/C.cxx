
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for(auto & i : a)
    cin >> i;

    sort(a.begin(), a.end());
    int ans = 0;
    int unused = 0;
    for(auto it = a.begin(); it != a.end(); it = upper_bound(a.begin(), a.end(), *it) ){
        int cnt = upper_bound(a.begin(), a.end(), *it) - it;
        ans += min(unused, cnt);
        unused += cnt - min(unused, cnt);
    }
    cout << ans;

    return 0;
}