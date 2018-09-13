#include<iostream>
#include<vector>
#include<set>

using namespace std;

set<int> edges[200500];
int color[200500];

struct DSU
{
    vector<int> p;

    DSU(int n)
    {
        p.assign(n,0);
        for(int i = 0; i<n; i++)
            p[i] = i;
    }
    int get(int i)
    {
        if(i==p[i])
            return i;
        return (p[i] = get(p[i]));
    }
    void unite(int x, int y)
    {
        x = get(x);
        y = get(y);
        if(x!=y)
            p[x] = y;
    }

};

void DFS(int _i, vector<int> & dist, int currDist = 1)
{
    dist[_i] = currDist;
    for(auto i: edges[_i])
        if(!dist[i])
            DFS(i,dist,currDist+1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for(int i = 0; i<n; i++)
        cin >> color[i];

    DSU myDSU(n);

    int x, y;
    for(int i = 1; i<n; i++)
    {
        cin >> x >> y;
        x--;
        y--;
        if(color[x]==color[y])
            myDSU.unite(x,y);
        edges[x].insert(y);
        edges[y].insert(x);
    }

    int tmp;
    for(int i = 0; i<n; i++)
    if((tmp=myDSU.get(i))!=i)
    {
        for(auto it = edges[i].begin(); it!=edges[i].end();)
        {
            edges[*it].erase(i);
            edges[*it].insert(tmp);
            edges[tmp].insert(*it);
            edges[i].erase(it++);
        }
    }
    for(tmp = 0; myDSU.get(tmp)!=tmp; tmp++){};

    vector<int> dist(n,0);
    DFS(tmp,dist);
    for(int i = 0; i<n; i++)
    {
        if(dist[i]>dist[tmp])
            tmp = i;
    }
    dist.assign(n,0);
    DFS(tmp,dist);
    for(int i = 0; i<n; i++)
    {
        if(dist[i]>dist[tmp])
            tmp = i;
    }
    cout << dist[tmp]/2;


    return 0;
}

