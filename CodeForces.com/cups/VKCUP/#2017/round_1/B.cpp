#include<iostream>
#include<vector>

using namespace std;


struct Graph
{
    int sz;
    vector<vector<int> > e{(size_t)sz};
    vector<int> used{vector<int>(sz, 0)};

    Graph(int n) : sz(n) {};

    pair<int,int> dfs(int v)
    {
        if(used[v])
            return {0,0};
        used[v]  = 1;

        pair<int, int> tmp;
        int _n = 1, _m = e[v].size();
        for(auto i : e[v])
        {
            tmp = dfs(i);
            _n+=tmp.first;
            _m+=tmp.second;
        }

        return {_n, _m};
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;

    cin >> n >> m;
    Graph G(n);

    for(int i = 0; i<m; i++)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        G.e[x].push_back(y);
        G.e[y].push_back(x);
    }

    for(int i = 0; i<n; i++)
    {
        pair<int,int> tmp = G.dfs(i);

        long long a = tmp.first, b = tmp.second;
        if(tmp.first*(tmp.first-1) != tmp.second)
        {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";


    return 0;
}
