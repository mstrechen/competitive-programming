#include<iostream>
#include<algorithm>
#include<map>
#include<vector>

using namespace std;

long long MAXN = 1000LL*1000LL*1000LL*1000LL*100 + 5;


bool dfs(int v, vector<vector<int>> & e0, vector<vector<int>> & e1, int curColor, vector<int> & colors)
{
    if(colors[v]!=-1)
        return colors[v] == curColor;

    bool res = 1;
    colors[v] = curColor;

    for(auto i : e0[v])
        res &= dfs(i, e0, e1, curColor, colors);
    for(auto i : e1[v])
        res &= dfs(i, e0, e1, !curColor, colors);
    return res;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int n, m;
    cin >> n >> m;

    vector<pair<int,int> > used(n, {-1,-1});
    vector<int> rooms(n);
    vector<int> group(m,-1);

    vector<vector<int> > e1(m), e0(m);

    for(int i = 0; i<n; i++)
        cin >> rooms[i];

    for(int i = 0; i<m; i++)
    {
        int x;
        cin >> x;
        for(int j = 0; j<x; j++)
        {
            int y;
            cin >> y;
            y--;
            if(used[y].first == -1)
                used[y].first = i;
            else
                used[y].second = i;
        }
    }

    for(int i = 0; i<n; i++)
    {
        int x = used[i].first;
        int y = used[i].second;
        if(rooms[i])
        {
            e0[x].push_back(y);
            e0[y].push_back(x);
        }
        else
        {
            e1[x].push_back(y);
            e1[y].push_back(x);
        }
    }

    for(int i = 0; i<m; i++)
    if(group[i] == -1)
    {
        if(!dfs(i, e0, e1, 0, group))
        {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";

    return 0;
}
