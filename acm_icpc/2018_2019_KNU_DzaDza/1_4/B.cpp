#include<iostream>
#include<vector>



using namespace std;

struct dsu{
    int size;
    vector<int> p;
    dsu(int n) : size(n), p(n){
        for(int i = 0; i < n; i++)
            p[i] = i;
    }

    int get(int x){
        if(x == p[x])
            return x;
        return p[x] = get(p[x]);
    }
    void unite(int x, int y){
        x = get(x); y = get(y);
        p[x] = y;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> nums(n);
    for(auto & i : nums)
        cin >> i;

    dsu D(n);
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        x--, y--;
        D.unite(x, y);
    }
    vector<vector<int> > v(n);
    for(int i = 0; i < n; i++)
        v[D.get(i)].push_back(i);


    int ans = 0;
    for(int bit = 30; bit >= 0; bit--){
        bool possible = true;
        for(auto & comp : v){
            int cnt0 = 0, cnt1 = 0;
            for(auto i : comp)
                if((nums[i] >> bit) & 1)
                    cnt1++;
                else
                    cnt0++;
            if(cnt0 == 0 && cnt1 + cnt0 != 0){
                possible = false;
                break;
            }
        }

        if(possible){
            for(auto & comp : v){
                for(int i = 0; i < comp.size(); ){
                    if((nums[comp[i]] >> bit) & 1){
                        swap(comp.back(), comp[i]);
                        comp.pop_back();
                    } else {
                        i++;
                    }
                }
            }
        } else {
            ans += (1 << bit);
        }
    }
    cout << ans;

    return 0;
}

