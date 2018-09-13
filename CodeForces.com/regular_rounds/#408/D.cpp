#include<stdio.h>
#include<vector>
#include<set>
#include<cassert>
#include<queue>
#include<algorithm>

using namespace std;

struct Edge
{
    int to, id;
};

struct Graph
{
    int n;
    vector<vector<Edge> > e{(size_t)n};
    vector<int> police{vector<int>(n, 0)};

    Graph(int n) : n(n)
    {
    }

    int curId{0};
    void addEdge(int i, int j)
    {
        e[i-1].push_back({j-1, ++curId});
        e[j-1].push_back({i-1, curId});
    }

    vector<int> stackIds{};
    vector<int> toDelete{};

    void findWhatToDelete()
    {
        queue<pair<int,int> > q;
        int color = 0;
        for(int i = 0; i<n; i++)
            if(police[i])
            {
                q.push({i, ++color});
                police[i] = color;
            }


        while(q.size())
        {
            int cur = q.front().first;
            color = q.front().second;
            q.pop();

            for(auto & j : e[cur])
            if(!police[j.to])
            {
                q.push({j.to, color});
                police[j.to] = color;
            }
            else
            {
                if(color != police[j.to])
                {
                    toDelete.push_back(j.id);
                }
            }
        }
        sort(toDelete.begin(), toDelete.end());
        auto last = unique(toDelete.begin(), toDelete.end());
        toDelete.resize(last - toDelete.begin());
    }
};


int main()
{
    int n, d, k;

    scanf("%d%d%d", &n, &d, &k);

    Graph G(n);
    for(int i = 0; i<d; i++)
    {
        int x;
        scanf("%d", &x);
        G.police[x-1] = 1;
    }
    for(int i = 1; i<n; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        G.addEdge(x, y);
    }

    G.findWhatToDelete();
    printf("%d\n", (int)G.toDelete.size());
    for(auto i : G.toDelete)
        printf("%d ", i);


    return 0;
}
