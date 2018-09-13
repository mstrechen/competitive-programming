#include<iostream>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

struct Graph
{
    int n;
    vector<vector<pair<int,int> > > e{vector<vector<pair<int,int> > >(n)};
    vector<int> bridges{};
    vector<int> timeIn{}, minUp{};
    Graph(int n) : n(n){}

    void addEdge(int x, int y, int id)
    {
        --x;
        --y;
        e[x].push_back({y, id});
        e[y].push_back({x, id});
    }

    int timer{};

    void dfs(int i, int father = -1)
    {
        timeIn[i] = timer++;
        minUp[i] = timeIn[i];
        for(auto & p : e[i])
        {
            int j = p.first;
            int id = p.second;
            if(id == father)
                continue;
            if(timeIn[j])
            {
                minUp[i] = min(minUp[i], timeIn[j]);
            }
            else
            {
                dfs(j,id);
                minUp[i] = min(minUp[i], minUp[j]);
                if(minUp[j] > timeIn[i])
                    bridges.push_back(id);
            }
        }
    }

    vector<int> getBridges()
    {
        bridges.clear();
        timeIn.assign(n, 0);
        minUp.assign(n, 0);
        timer = 1;
        int k = 0;
        for(int i = 0; i<n; i++)
            if(!timeIn[i])
            {
                dfs(i);
                k++;
            }

        return bridges;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    Graph G(n);
    set<pair<int,int>>S;
    for(int i = 0; i<m; i++)
    {
        int x, y;
        cin >> x >> y;
        if(x>y)
            swap(x, y);

        G.addEdge(x, y, i+1);
    }
    auto tmp = G.getBridges();
    sort(tmp.begin(), tmp.end());
    cout << tmp.size() << '\n';
    for(auto i : tmp)
        cout << i << ' ';

    return 0;
}
