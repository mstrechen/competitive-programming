#include<iostream>
#include<vector>
#include<algorithm>
#include<tuple>


using namespace std;

struct DSU{
    int size;
    vector<int> p;
    DSU(int n) : size(n), p(size){
        for(int i = 0; i < n; i++)
            p[i] = i;
    }

    int get(int i){
        if(p[i] == i)
            return i;
        return p[i] = get(p[i]);
    }
    int unite(int x, int y){
        x = get(x);
        y = get(y);
        p[x] = y;
        return (x != y);
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<tuple<int,int,int> > e(m);
    for(auto & i : e){
        cin >> get<1>(i);
        cin >> get<2>(i);
        cin >> get<0>(i);
    }

    sort(e.begin(), e.end());

    DSU D(n);
    int ans = 0;
    for(auto & i : e){
        ans += D.unite(get<1>(i) - 1, get<2>(i) - 1) * get<0>(i);
    }
    cout << ans;


    return 0;
}
