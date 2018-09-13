#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

void dfs(int v, int from, int dist, vector<vector<int>> & e, vector<int> & d)
{
    d[v] = dist;
    for(auto i : e[v])
        if(i!=from)
            dfs(i, v, dist+1, e, d);
}

int bfs_find(int v, int val, vector<vector<int>> & e, vector<int> & d)
{
    while(d[v]!=val)
    {
        int newV = -1;
        for(auto i : e[v])
            if(d[i] == d[v] - 1)
                newV = i;
        v = newV;
    }
    return v;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    cin >> n;

    vector<vector<int> > e(n);
    vector<int> dist(n);

    for(int i = 1; i<n; i++)
    {
        int f,t;
        cin >> f >> t;
        f--;
        t--;
        e[f].push_back(t);
        e[t].push_back(f);
    }

    dfs(0,-1, 0, e, dist);
    dfs(max_element(dist.begin(), dist.end()) - dist.begin(), -1, 0, e, dist);

    auto num = max_element(dist.begin(), dist.end()) - dist.begin();

    int diam = dist[num];
    cout << diam << endl;
    if(diam%2 == 0)
    {
        int newV =  bfs_find(num, diam/2, e, dist);
        dfs(newV, -1, 0, e, dist);
        int R = *max_element(dist.begin(), dist.end());
        for(int i = 0; i<n; i++)
            if((int)e[i].size()==1 && dist[i] != R)
            {
                cout << -1;
                return 0;
            }
        while((diam&1) == 0)
            diam/=2;
        cout << diam;
    }
    else
    {
        int newV1 = bfs_find(num, diam/2 + 1, e, dist);
        int newV2 = bfs_find(newV1, diam/2, e,dist);

        dfs(newV1, newV2, 0, e, dist);
        dfs(newV2, newV1, 0, e, dist);

        int R = *max_element(dist.begin(), dist.end());
        for(int i = 0; i<n; i++)
            if((int)e[i].size()==1 && dist[i] != R)
            {
                cout << -1;
                return 0;
            }
        cout << diam;
    }


    return 0;
}

