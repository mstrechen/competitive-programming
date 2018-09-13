#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    map<int, int > cnt;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        cnt[x]++;
    }
    int ans = n;
    auto it = cnt.begin();
    for(it++; it != cnt.end(); it++){
        auto itprev = it;
        itprev--;
        if(itprev->first + k >= it->first){
            ans -= itprev->second;
        }
    }
    cout << ans;
    
    return 0;
}