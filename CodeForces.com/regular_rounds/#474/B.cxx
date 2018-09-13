#include<iostream>
#include<set>
#include<vector>
#include<functional>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, k, k1;
    cin >> n >> k >> k1;
    k += k1;
    vector<int> a(n);
    for(auto & i : a)
        cin >> i;
    for(auto & i : a){
        int tmp;
        cin >> tmp;
        i -= tmp;
    }

    multiset<int, greater<int> > ms;
    for(auto & i : a)
        ms.insert(abs(i));
    for(int i = 0; i < k; i++){
        auto it = ms.begin();
        ms.insert(abs(*it - 1));
        ms.erase(it);
    }
    long long ans = 0;
    for(auto & i : ms)
        ans += i*1LL*i;
    cout << ans;


    return 0;
}