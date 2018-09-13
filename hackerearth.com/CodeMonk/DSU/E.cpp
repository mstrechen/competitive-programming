#include<iostream>
#include<vector>

using namespace std;

long long mod = 1000*1000*1000 + 7;

long long binpow(long long x, long long pow)
{
    if(pow==1)
        return x;
    if(pow&1)
    {
        return (binpow(x, pow-1)*x)%mod;
    }
    long long tmp = binpow(x, pow/2);
    return (tmp*tmp)%mod;
}

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

    int getCount()
    {
        int ans = 0;
        for(int i = 0; i<(int)p.size(); i++)
            ans+=(p[i]==i);
        return ans;
    }

};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;

    cin >> n >> q;

    DSU dsu(n);

    for(int i = 0; i<q; i++)
    {
        int u,v;
        cin >> u >> v;

        u--, v--;
        while(u<v)
        {
            dsu.unite(u,v);
            u++;
            v--;
        }
    }

    cout << binpow(10, dsu.getCount());

    return 0;
}
