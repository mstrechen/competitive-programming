#include<iostream>
#include<vector>

using namespace std;


struct edge
{
    int to, cost;
};


int dfs(int v, int be, int from,vector<char> & used, vector<vector<edge> > & E, int maxE = 0, int minE= 2*1000*1000*1000)
{
    used[v] = 1;
    if(v == be && from != -1)
    {
        return minE+maxE;
    }

    int ans = 0;
    for(auto & i : E[v])
        if( from!=i.to && ((!used[i.to]) || (i.to == be)) )
        {
            ans = max(ans, dfs(i.to, be, v, used, E, max(maxE, i.cost), min(minE, i.cost)));
        }
    used[v] = 0;
    return ans;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<edge> > E(n);


    for(int i = 0; i<m; i++)
    {
        int from, to, cost;
        cin >> from >> to >> cost;
        from--;
        to--;
        E[from].push_back({to,cost});
        E[to].push_back({from,cost});
    }

    int maxAns = 0;

    vector<char> used;


    for(int i = 0; i<n; i++)
    {
        used.assign(n,0);
        maxAns = max(maxAns, dfs(i,i,-1, used, E) );
    }


    cout << maxAns;

    return 0;
}

