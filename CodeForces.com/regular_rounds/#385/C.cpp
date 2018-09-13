#include<iostream>
#include<string>
#include<set>
#include<vector>

using namespace std;


pair<int,int> dfs(int v, vector<vector<int>> & edges, vector<char> &  used)
{
    used[v] = 1;

    pair<int,int> ans = {1,edges[v].size()};

    for(auto i : edges[v])
    if(!used[i])
    {
        auto tmp = dfs(i, edges,used);
        ans.first+=tmp.first;
        ans.second+=tmp.second;
    }

    return ans;
}



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int cities, edges, cap;

    cin >> cities >> edges >> cap;

    vector<int> capitals(cap);

    for(auto & i : capitals)
        cin >> i;


    vector<vector<int> > e(cities);

    for(int i = 0; i<edges; i++)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        e[x].push_back(y);
        e[y].push_back(x);
    }


    vector<char> used(cities,0);

    int ans = 0;

    int maxComponent = 0;

    int usedEdges = 0;
    int usedCities = 0;

    for(auto i : capitals)
    {
        auto res = dfs(i-1,e,used);

        ans+=(res.first*(res.first-1) - res.second)/2;
        usedEdges+=res.second/2;
        usedCities+=res.first;

        maxComponent = max(maxComponent, res.first);
    }

    ans-=edges-usedEdges;

    for(int i = usedCities; i<cities; i++)
    {
        ans+=maxComponent;
        maxComponent++;
    }

    cout << ans;




    return 0;
}
