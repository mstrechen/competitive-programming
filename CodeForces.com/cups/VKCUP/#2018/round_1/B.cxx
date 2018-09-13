#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct snow{
    static vector<long long> process(vector<int> v, vector<int> t){
        int sizes = 0;
        map<long long, int> cnt;
        int dead_cnt = 0;

        long long prev_temp = 0;
        long long new_temp = 0;

        vector<long long> res;
        
        for(size_t i = 0; i < v.size(); i++){
            new_temp += t[i];
            cnt[v[i] + prev_temp]++;
            sizes += 1;

            auto it_b = cnt.lower_bound(prev_temp);
            auto it_e = cnt.upper_bound(new_temp);
            res.push_back(0);
            for(auto it = it_b; it != it_e; it++){
                res.back() += (it->first - prev_temp) * it->second;
                dead_cnt += it->second;
            }
            cnt.erase(it_b, it_e);
            res.back() += (sizes - dead_cnt) * (long long)t[i];
            prev_temp += t[i];
        }
        return res;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> v(n);
    vector<int> t(n);
    for(auto & i : v)
        cin >> i;
    for(auto & i : t)
        cin >> i;
    
    auto res = snow::process(v, t);
    
    for(auto i : res)
        cout << i << ' ';

    return 0;
}