
#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(2 * n);
    for(auto & i : a)
        cin >> i;
    sort(a.begin(), a.end());
    long long minAns = (a[n - 1] - a[0]) * 1LL * (a[2*n - 1] - a[n]);
    for(int i = 1; i < n; i++){
        minAns = min(minAns, (a[2 * n - 1] - a[0]) * 1LL * (a[n - 1 + i] - a[i]));
    }

G
    for(int i = 0; i < n; i++){
        b[a[i]]++;
    }
    
    cout << minAns;

    return 0;
}