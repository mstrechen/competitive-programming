#include<iostream>
#include<vector>

using namespace std;

long long mod = 1000*1000*1000 + 7;

struct DSU
{
    vector<int> p, c;

    DSU(int n, int m)
    {
        p.assign(n+m, 0);
        c.assign(n+m, 1);

        for(int i = 0; i<n; i++)
            c[i] = 0;

        for(int i = 0; i<n+m; i++)
            p[i] = i;
    }

    int get(int i)
    {
        if(p[i]==i)
            return i;
        return p[i] = get(p[i]);
    }

    void unite(int i, int j)
    {
        i = get(i);
        j = get(j);
        if(i==j)
            return;

        p[i] = j;
        c[j]+=c[i];
        c[i] = 0;
    }

    int getCount(int i)
    {
        return c[get(i)];
    }

};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int men, women, m;

    cin >> men >> women;

    DSU dsu(men,women);

        cin >> m;
        for(int i = 0; i<m; i++)
        {
            int u,v;
            cin >> u >> v;
            dsu.unite(u-1,v-1);
        }

        cin >> m;
        for(int i = 0; i<m; i++)
        {
            int u,v;
            cin >> u >> v;
            dsu.unite(men+u-1,men+v-1);
        }

        cin >> m;
        for(int i = 0; i<m; i++)
        {
            int u,v;
            cin >> u >> v;
            dsu.unite(u-1,men+v-1);
        }

    long long ans = 0;

    for(int i = 0; i<men; i++)
    {
        ans+=women-dsu.getCount(i);
    }
    cout << ans;

    return 0;
}
