#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;

struct edge{
    int x, y, val;
    edge(int x, int y, int val) : x(x), y(y), val(val) {}
};
bool operator < (const edge & a, const edge & b){
    return a.val < b.val;
}

int sqr(int a){
    return a*a;
}
int get_dist(const pair<int, int> & a, const pair<int, int> & b){
    return sqr(a.first - b.first) + sqr(a.second - b.second);
}

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
    cin >> n;
    dsu d(n);
    vector<pair<int, int> > points(n);
    vector<edge> e;

    for(int i = 0; i < n; i++)
        cin >> points[i].first >> points[i].second;

    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++)
            e.push_back(edge(i, j, get_dist(points[i], points[j])));

    cin >> m;
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        e.push_back(edge(x-1, y-1, 0));
    }
    sort(e.begin(), e.end());
    double minval = 0;
    for(int i = 0; i < (int)e.size(); i++){
        if(d.unite(e[i].x, e[i].y))
            minval += sqrt(e[i].val);
    }

    cout.precision(10);
    cout << (fixed) << minval;

    return 0;
}
