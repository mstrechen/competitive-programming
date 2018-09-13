#include<iostream>
#include<numeric>
#include<vector>
#include<queue>
#include<set>
#include<functional>
#include<cmath>

using namespace std;


struct Network
{
    int size;
    int be, en;
    vector<vector<long long> > c, f{};
    vector<int> h{};
    vector<long long> e{};

    Network(int n, int be, int en) : size(n), be(be), en(en),
                     c(size, vector<long long>(size, 0))
    {
    }

    using myQueue = set<pair<int,int>, greater<pair<int,int> > >;
    void init(myQueue & Q, vector<char> & used)
    {
        f.assign(size, vector<long long>(size, 0));
        e.assign(size, 0);
        h.assign(size, 0);
        h[be] = size;

        e[be] = 1e18;

        Q.emplace(h[be], be);
    }

    void addEdge(int x, int y, int val)
    {
        c[x][y]+=val;
    }

    void push(int x, int y)
    {
        long long delta = min(e[x], c[x][y] - f[x][y]);
        f[x][y] += delta;
        f[y][x] -= delta;
        e[x] -= delta;
        e[y] += delta;
    }


    long long findMaxFlow()
    {
        myQueue Q;
        vector<char> used(size, 0);
        init(Q, used);

        while(!Q.empty())
        {
            int I = Q.begin()->second;
            Q.erase(Q.begin());
            used[I] = 0;

            for(int J = 0; J<size; J++)
                if(c[I][J] - f[I][J] > 0 && e[I] && h[I] > h[J])
                {
                    push(I, J);
                    if(J!=be && J!=en && !used[J])
                    {
                        Q.emplace(h[J], J);
                        used[J] = 1;
                    }
                }

            if(I!=be && I!=en && e[I] != 0)
            {
                h[I]++;
                Q.emplace(h[I], I);
            }
        }

        return e[en];
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    Network NW(n, 0, n-1);

    for(int i = 0; i<m; i++)
    {
        int x, y, val;
        cin >> x >> y >> val;
        NW.addEdge(x-1,y-1,val);
    }

    cout << NW.findMaxFlow();


    return 0;
}
