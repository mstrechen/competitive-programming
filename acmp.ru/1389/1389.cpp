#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>

using namespace std;

struct edge{
    int x, y, cost;
    edge(int x, int y, int cost) : x(x), y(y), cost(cost){}
};

bool operator < (const edge & a, const edge & b){
    return a.cost < b.cost;
}

int operator + (const int & a, const edge & b){
    return a + b.cost;
}

struct dsu{
    int n, m;
    int size;
    vector<int> p;
    dsu(int n, int m) : n(n), m(m), size(n*m), p(size){
        for(int i = 0; i < size; i++)
            p[i] = i;
    }
    int encode(int x, int y){
        return x*m + y;
    }
    pair<int, int> encode(int i){
        return make_pair(i/m, i%m);
    }
    int get(int i){
        if(i == p[i])
            return i;
        return p[i] = get(p[i]);
    }
    bool unite(int x, int y){
        x = get(x);
        y = get(y);
        if(x == y)
            return 0;
        p[x] = y;
        return 1;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    dsu d(n, m);
    vector<edge> e;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            int val;
            cin >> val;
            if(val&1)
                e.push_back(edge(d.encode(i, j), d.encode(i + 1, j), 0));
            if(val>>1)
                e.push_back(edge(d.encode(i, j), d.encode(i, j + 1), 0));
        }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            if(i + 1 != n)
                e.push_back(edge(d.encode(i, j), d.encode(i + 1, j), 1));
            if(j + 1 != m)
                e.push_back(edge(d.encode(i, j), d.encode(i, j + 1), 2));
        }


    vector<edge> ans;

    sort(e.begin(), e.end());
    for(int i = 0; i < e.size(); i++){
        if(d.unite(e[i].x, e[i].y) && e[i].cost)
            ans.push_back(e[i]);
    }

    cout << ans.size() << ' ' << accumulate(ans.begin(), ans.end(), 0) << '\n';
    for(int i = 0; i < ans.size(); i++){
        pair<int, int> tmp = d.encode(ans[i].x);
        cout << tmp.first + 1 << ' ' << tmp.second + 1 << ' ' << 1 + (d.encode(ans[i].y).first == tmp.first) << '\n';

    }

    return 0;
}
