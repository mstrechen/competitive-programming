#include<iostream>
#include<vector>
#include<set>

using namespace std;

vector<int> edges[200500];
int color[200500];


void DFS(int _i, vector<int> & dist, int currDist = 1)
{
    dist[_i] = currDist;
    for(auto i: edges[_i])
        if(!dist[i])
            DFS(i,dist,currDist+(color[_i]!=color[i]));
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for(int i = 0; i<n; i++)
        cin >> color[i];


    int x, y;
    for(int i = 1; i<n; i++)
    {
        cin >> x >> y;
        x--;
        y--;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }

    vector<int> dist(n,0);
    int tmp = 0;

    DFS(0,dist);
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

