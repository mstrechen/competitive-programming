#include <iostream>
#include <map>
#include <vector>

using namespace std;

#define BIT(x,i) ((x >> i) & 1) 
#define POW2(i) (1 << i)
#define ONES(i) ((1 << i) - 1)

struct genious_tree{
    map<int, int> keys;
    using iter_t = map<int, int>::iterator; 

    int get_best_key(int val){
        auto it_l = keys.begin(),
             it_r = keys.end();

        int prefix = 0;
        for(int i = 29; i >= 0; i--){
            auto mid = keys.upper_bound(prefix + ONES(i) );
            if(mid == it_r){
                continue;
            }
            if(mid == it_l){
                prefix += POW2(i);
                continue;
            }

            if(BIT(val, i))
                it_l = mid, 
                prefix += POW2(i);
            else
                it_r = mid; 
        }

        int ans = it_l->first;
        it_l->second--;
        if(it_l->second == 0)
            keys.erase(it_l);
        return ans;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for(auto & i : a)
        cin >> i;

    genious_tree GT;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        GT.keys[x]++;
    }
    for(auto & i : a){
        cout << (GT.get_best_key(i) ^ i) << ' ';
    }

    return 0;
}