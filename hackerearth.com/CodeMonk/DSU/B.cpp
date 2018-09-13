#include<iostream>
#include<vector>

using namespace std;

long long mod = 1000*1000*1000 + 7;

struct DSU
{
    vector<int> p, c;

    DSU(int n)
    {
        p.assign(n, 0);
        c.assign(n, 1);
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

    long long getCount(int i)
    {
        return c[get(i)];
    }

};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;

    cin >> n >> m;

    DSU dsu(n);

    for(int i = 0; i<m; i++)
    {
        int u,v;
        cin >> u >> v;
        dsu.unite(u-1,v-1);
    }

    long long ans = 1;
    for(int i = 0; i<n; i++)
    if(dsu.get(i) == i)
    {
        ans*=dsu.getCount(i);
        ans%=mod;
    }

    cout << ans;

    return 0;
}
