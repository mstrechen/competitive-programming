#include<iostream>
#include<vector>

using namespace std;

long long mod = 1000*1000*1000 + 7;

struct DSU
{
    vector<int> p, c;
    vector<char> isOk;

    DSU(int n)
    {
        p.assign(n, 0);
        c.assign(n, 1);
        isOk.assign(n,1);
        for(int i = 0; i<n; i++)
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

    void makeEnemies(int i, int j)
    {
        i = get(i);
        j = get(j);
        if(i==j)
            isOk[i] = 0;
    }

    int getCount(int i)
    {
        i = get(i);
        if(isOk[i])
            return c[get(i)];
        return 0;
    }

};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m1,m2;

    cin >> n >> m1;

    DSU dsu(n);

    for(int i = 0; i<m1; i++)
    {
        int u,v;
        cin >> u >> v;
        dsu.unite(u-1,v-1);
    }

    cin >> m2;
    for(int i = 0; i<m2; i++)
    {
        int u,v;
        cin >> u >> v;
        dsu.makeEnemies(u-1,v-1);
    }

    int ans = 0;
    for(int i = 0; i<n; i++)
        ans = max(ans, dsu.getCount(i));

    cout << ans;

    return 0;
}
