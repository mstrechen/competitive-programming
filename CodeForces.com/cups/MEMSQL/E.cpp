#include<iostream>

using namespace std;

const long long MOD = 1000*1000*1000 + 7;

struct office{
    int size;
    vector<int> a;
    office(int n) : size(n*2), a(size){}

    long long ans = 1;
    vector<int> cnt;
    vector<int> used;

    pair<int, int> dfs(int v){
        used[v] = 1;

        if(used[a[v]]){
            if(used[a[v]] == 1){
                return {a[v], 0};
            }
            else
                return {0, 0};
        }
        else{
            auto tmp = dfs(a[v]);
            if(tmp.first == 0 && tmp.second == 0)
                return {0,0};

        }

        used[v] = -1;

    }

    void calc(){
        cnt.assign(size, 0);
        used.assign(size, 0);
        for(auto & i : a)
            i--;

        for(auto & i : a)
            cnt[i]++;

        for(int i = 0; i < size; i++)
            if(cnt[i] == 0)
                dfs(i, )
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    office O(n);
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        O.a[x] = y;
    }



    return 0;
}
