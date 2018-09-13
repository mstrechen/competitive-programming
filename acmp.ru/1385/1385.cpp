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
    int get(int i){
        if(i == p[i])
            return i;
        return p[i] = get(p[i]);
    }
    bool unite(int i, int j){
        i = get(i);
        j = get(j);
        if(i == j)
            return 0;
        p[i] = j;
        return 1;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    dsu d(n);

    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        if(d.unite(x-1, y-1))
            cout << x << ' ' << y << '\n';
    }


    return 0;
}
