#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;


struct segmentTree
{
    vector<int> inc;
    int _size;

    segmentTree(int sz = 0)
    {
        _size = 1;
        while(_size<sz)
            _size*=2;

        inc.resize(_size*2, 0);

    }
    void _add(int l, int r, int val, int minL, int maxR, int _i)
    {
        if(l>r)
            return;
        if(l==minL && r == maxR)
        {
            inc[_i]+=val;
            return;
        }
        int mid = (minL+maxR)/2;
        _add(l, min(r,mid), val, minL, mid, _i*2);
        _add(max(l,mid+1),r, val, mid+1, maxR, _i*2+1);
    }

    int _get(int i, int minL, int maxR, int _i)
    {
        if(minL==maxR)
            return inc[_i];

        int mid = (minL+maxR)/2;

        if(i<=mid)
            return _get(i, minL, mid, _i*2)     + inc[_i];
        else
            return _get(i, mid+1, maxR, _i*2+1) + inc[_i];
    }

    void add(int l, int r, int val)
    {
        _add(l, r, val, 1, _size, 1);
    }

    int get(int i)
    {
        return  _get(i, 1, _size, 1);
    }
};


struct HLD
{
    vector<vector<int> > edges;
    vector<int> tokens,
                parents,
                depth,
                chains,
                sizeOfSubtree;
    vector<pair<int,int> > chainsBorders;
    segmentTree ST;

    HLD(istream & inStream)
    {
        int n, k;
        inStream >> n >> k;

        edges.resize(n);
        tokens.resize(n,0);
        parents.resize(n,0);
        depth.resize(n,0);
        chains.resize(n,0);
        sizeOfSubtree.resize(n,0);

        for(int i = 0; i+1<n; i++)
        {
            int x,y;
            inStream >> x >> y;
            x--;
            y--;
            edges[x].push_back(y);
            edges[y].push_back(x);
        }
        preparation(0, -1, 0);
        vector<int> base;
        buildHL(0,-1, 1, base);
        ST = segmentTree(base.size());


        for(int i = 0; i<k; i++)
        {
            int x, y;
            cin >> x >> y;
            ST.add(x,y,1);
        }
    }

    int preparation(int v, int from, int currentDepth)
    {
        parents[v] = from;

        depth[v] = currentDepth;
        currentDepth++;

        int subtreeSize = 1;

        for(auto i : edges[v])
            if(i!=from)
            {
                subtreeSize+=preparation(i, v, currentDepth);
            }
        return sizeOfSubtree[v] = subtreeSize;
    }

    void buildHL(int v, int from, bool makeNew, vector<int> & base)
    {
        base.push_back(0);
        tokens[v] = (int)base.size();

        if(makeNew)
        {
            chainsBorders.push_back(make_pair(v,0));
        }
        chains[v] = (int)chainsBorders.size() - 1;

        if(edges[v].size()==1 && v!=0)
            chainsBorders[chains[v]].second = v;
        else
        {
            int maxSon = -1;

            for(auto i : edges[v])
                if(i!=from)
                {
                    if(maxSon==-1||sizeOfSubtree[i]>sizeOfSubtree[maxSon])
                        maxSon = i;
                }

            buildHL(maxSon, v, 0, base);
            for(auto i : edges[v])
                if(i!=from && i!=maxSon)
                {
                    buildHL(i, v, 1, base);
                }
        }
    }

    void get(int from, int to)
    {
        from--;
        to--;



        while(chains[from]!=chains[to])
        {
            int f = chainsBorders[chains[from]].first, t = chainsBorders[chains[to]].first;

            if(depth[f] > depth[t])
            {
                ST.add(tokens[f],tokens[from],1);
                from = parents[f];
            }
            else
            {
                ST.add(tokens[t], tokens[to],1);
                to = parents[t];
            }

        }
        if(depth[from]>depth[to])
            swap(from,to);
        ST.add(tokens[from]+1, tokens[to],1);
    }
};


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--)
    {
        HLD myHLD(cin);
        int ans = 0;
        for(int i = 1; i<myHLD.parents.size(); i++)
            ans = myHLD.ST.get(myHLD.tokens[i]);

    }



}
