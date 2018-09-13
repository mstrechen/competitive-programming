#include<iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, a, b, c, t;
    cin >> n >> a >> b >> c >> t;
    long long ans = 0;

    for(int i = 0; i < n; i++){
        int t_i;
        cin >> t_i;
        ans += max<long long>(a, a + (c - b) * 1LL* (t - t_i));
    }
    cout << ans;

    return 0;
}