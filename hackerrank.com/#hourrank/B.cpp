#include<iostream>
#include<cmath>
#include<functional>
#include<vector>
#include<algorithm>


using namespace std;

int a[3050];

vector<pair<int, pair<int,int>> > P;

struct dsu
{
    vector<int> p;
    vector<int> sizes;
    int k;

    dsu(int n, int k): k(max(k, n-k))
    {
        sizes = vector<int>(n,1);
        p = vector<int>(n,0);
        for(int i = 0; i<n; i++)
            p[i] = i;
    }
    int _getParent(int i)
    {
        if(p[i]==i)
            return i;
        return (p[i] = _getParent(p[i]));
    }
    void unite(int i, int j)
    {

        if(sizes[i]+sizes[j]<=k)
        {
            p[j] = i;
            sizes[i]+=sizes[j];
            sizes[j] = 0;
        }
    }
};

bool f(pair<int,pair<int,int> > a,pair<int,pair<int,int> > b)
{
    return a>b;
}

int main()
{
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;


    for(int i = 0; i<n; i++)
        cin >> a[i];

    dsu datBoi(n,k);
    for(int i = 0; i<n; i++)
    {
        for(int j = i+1; j<n; j++)
        {
            P.push_back({abs(a[i]-a[j]),{i,j} });
        }
    }
    sort(P.begin(), P.end(), f);

    for(auto i:P)
    {
        datBoi.unite(i.second.first, i.second.second);
    }
    long long dist = 0;
    for(int i = 0; i<n; i++)
    {
        for(int j = i+1; j<n; j++)
        {
            if(datBoi._getParent(i)!=datBoi._getParent(j))
                dist+=abs(a[i]-a[j]);
        }
    }
    cout << dist;
    return 0;
}
