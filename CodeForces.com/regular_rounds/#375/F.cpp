#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


struct DSU
{
    vector<int> p;
    DSU(int n = 0)
    {
        p.assign(n,0);
        for(int i = 0; i<n; i++)
            p[i] = i;
    }
    int get(int i)
    {
        if(p[i]==i)
            return i;
        return (p[i] = get(p[i]));
    }
    void unite(int i, int j,  vector<pair<int,int> > & result)
    {
        int i1 = i, i2 = j;
        i = get(i);
        j = get(j);
        if(i!=j)
        {
            p[i]=j;
            result.push_back({++i1,++i2});
        }
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;

    cin >> n >> m;
    vector<pair<int, pair<int, int> > > g;
    vector<pair<int, int> > result;
    DSU myDSU(n);
    g.assign(m,make_pair(0,make_pair(0,0)));

    for(int i = 0; i<m; i++)
    {
        cin >> g[i].second.first >> g[i].second.second;
        g[i].second.first--;
        g[i].second.second--;
    }
    int s,t,ds,dt;

    cin >> s >> t >> ds >> dt;
    int dt1 = dt, ds1 = ds;

    s--;
    t--;
    for(int i = 0; i<m; i++)
    {
        if((g[i].second.first==s&&g[i].second.second==t)||
           (g[i].second.first==t&&g[i].second.second==s))
        {
            g[i].first = 1001;
        }
        else
        if(g[i].second.first==s||g[i].second.first==t||
           g[i].second.second==s||g[i].second.second==t)
        {
            g[i].first = 1000;
        }
    }
    sort(g.begin(), g.end());

    int _i;
    for(_i = 0; _i<m&&g[_i].first==0; _i++)
    {
        if(myDSU.get(g[_i].second.first)!=myDSU.get(g[_i].second.second))
        {
            myDSU.unite(g[_i].second.first,g[_i].second.second, result);
        }
    }

    for(; _i<m; _i++)
    if(myDSU.get(g[_i].second.first)!=myDSU.get(g[_i].second.second) )
    {
        if(((g[_i].second.first==s&&g[_i].second.second==t)||
           (g[_i].second.second==s&&g[_i].second.first==t))&&dt>0&&ds>0)
        {
            g.push_back(g[_i]);
        }
        else
        if((g[_i].second.first==s||g[_i].second.second==s)&&ds>0)
        {
                if(ds>1)
                {
                    ds--;
                    myDSU.unite(g[_i].second.first,g[_i].second.second, result);
                }
                else
                {
                    g.push_back(g[_i]);
                }

        }
        else
        if(dt>0)
        {
            if(dt>1)
            {
                dt--;
                myDSU.unite(g[_i].second.first,g[_i].second.second, result);
            }
            else
            {
                g.push_back(g[_i]);
            }
        }
    }
    for(_i = m; _i<g.size(); _i++)
    {
        if(((g[_i].second.first==s&&g[_i].second.second==t)||
           (g[_i].second.second==s&&g[_i].second.first==t))&&dt>0&&ds>0)
        {
            dt--;
            ds--;
            myDSU.unite(s,t,result);
        }
        else
        if((g[_i].second.first==s||g[_i].second.second==s)&&ds>0)
        {
                    ds--;
                    myDSU.unite(g[_i].second.first,g[_i].second.second, result);
        }
        else
        if(dt>0)
        {
                dt--;
                myDSU.unite(g[_i].second.first,g[_i].second.second, result);
        }
    }
    int count = 0;
    for(int i = 0; i<n; i++)
        if(myDSU.p[i]==i)
            count++;
    if(count>1)
    {
        cout << "No";
    }
    else
    {
        cout << "Yes\n";
        for(auto i:result)
            cout << i.first << ' ' << i.second << '\n';
    }
    return 0;
}
