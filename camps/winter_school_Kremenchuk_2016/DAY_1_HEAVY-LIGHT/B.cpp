#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<cassert>

using namespace std;


struct student {
    string form, first_name, last_name, birthday;
};

bool operator < (const student & a, const student & b){
    if(a.form != b.form)
        return (a.form.size() < b.form.size())
            || (a.form.size() == b.form.size() && a.form < b.form);
    return a.last_name < b.last_name;
}

istream & operator >> (istream & in, student & to_read){
    in >> to_read.last_name >> to_read.first_name >> to_read.form >> to_read.birthday;
    return in;
}

ostream & operator << (ostream & out, const student & to_write){
    out << to_write.form << ' '
        << to_write.last_name << ' '
        << to_write.first_name << ' '
        << to_write.birthday;
        return out;
}






const int oo = 0;

struct segmentTree
{
    vector<int> _mx;
    int _size;

    segmentTree(int sz = 0) : _size(sz) {}
    segmentTree(const vector<int> & base)
    {
        _size = 1;
        while(_size<base.size())
            _size*=2;

        _mx.resize(_size*2, +oo);

        for(int i = 0; i<base.size(); i++)
            _mx[i+_size] = base[i];

        for(int i = _size-1; i>0; i--)
            _mx[i] = max(_mx[i*2], _mx[i*2+1]);

    }
    int _set(int i, int val, int minL, int maxR, int _i)
    {
        if(i < minL|| maxR < i)
            return _mx[_i];
        if(minL==maxR)
            return (_mx[_i] = val);
        else
        {
            int mid = (minL+maxR)/2;
            return (_mx[_i] = max(_set(i, val, minL, mid, _i*2),
                                 _set(i, val, mid+1, maxR, _i*2+1)));
        }
    }

    int _get(int l, int r, int minL, int maxR, int _i)
    {
        if(l>r)
            return +oo;
        if(minL==maxR)
            return _mx[_i];

        int mid = (minL+maxR)/2;
        return max(_get(l, min(r, mid), minL, mid, _i*2),
                   _get(max(l,mid+1),r, mid+1, maxR, _i*2+1));
    }

    void set(int i, int val)
    {
        _set(i, val, 1, _size, 1);
    }

    int get(int l, int r)
    {
        return  _get(l, r, 1, _size, 1);
    }
};


struct HLD
{
    vector<vector<pair<int,int> > > edges;
    vector<pair<int,int> > edgesInAnotherStyle;
    vector<int> tokens,
                parents,
                depth,
                chains,
                sizeOfSubtree;
    vector<pair<int,int> > chainsBorders;
    segmentTree ST;

    HLD(istream & inStream)
    {
        int n;
        inStream >> n;

        edges.resize(n);
        tokens.resize(n,0);
        parents.resize(n,0);
        depth.resize(n,0);
        chains.resize(n,0);
        sizeOfSubtree.resize(n,0);

        for(int i = 0; i+1<n; i++)
        {
            int x,y, val;
            inStream >> x >> y >> val;
            x--;
            y--;
            edgesInAnotherStyle.push_back(make_pair(x,y));
            edges[x].push_back(make_pair(y,val));
            edges[y].push_back(make_pair(x,val));
        }
        preparation(0, -1, 0);
        vector<int> base;
        buildHL(0,-1, 0, 1, base);
        ST = segmentTree(base);

    }

    int preparation(int v, int from, int currentDepth)
    {
        parents[v] = from;

        depth[v] = currentDepth;
        currentDepth++;

        int subtreeSize = 1;

        for(vector<pair<int,int> > :: iterator i = edges[v].begin(); i!=edges[v].end(); i++)
            if(i->first!=from)
            {
                subtreeSize+=preparation(i->first, v, currentDepth);
            }

        return sizeOfSubtree[v] = subtreeSize;
    }

    void buildHL(int v, int from, int cost, bool makeNew, vector<int> & base)
    {
        base.push_back(cost);
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
            pair<int,int> maxSon = make_pair(-1,0);


            for(vector<pair<int,int> >::iterator i = edges[v].begin(); i!=edges[v].end(); i++)
                if(i->first!=from)
                {
                    if(maxSon.first==-1||sizeOfSubtree[i->first]>sizeOfSubtree[maxSon.first])
                        maxSon = *i;
                }

            buildHL(maxSon.first, v, maxSon.second, 0, base);
            for(vector<pair<int,int> >::iterator i = edges[v].begin(); i!=edges[v].end(); i++)
                if(i->first!=from && *i!=maxSon)
                {
                    buildHL(i->first, v, i->second, 1, base);
                }
        }
    }

    int get(int from, int to)
    {
        from--;
        to--;


        int ans = +oo;

        while(chains[from]!=chains[to])
        {
            int f = chainsBorders[chains[from]].first, t = chainsBorders[chains[to]].first;

            if(depth[f] > depth[t])
            {
                ans = max(ans, ST.get(tokens[f],tokens[from]));
                from = parents[f];
            }
            else
            {
                ans = max(ans, ST.get(tokens[t], tokens[to]));
                to = parents[t];
            }

        }
        if(depth[from]>depth[to])
            swap(from,to);
        ans = max(ans, ST.get(tokens[from]+1, tokens[to]));
        return ans;
    }
    void set(int i, int val)
    {
        int x = edgesInAnotherStyle[i-1].first;
        int y = edgesInAnotherStyle[i-1].second;

        if(sizeOfSubtree[x]<sizeOfSubtree[y])
            swap(x,y);

        ST.set(tokens[y], val);
    }
};


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        HLD myHLD(cin);

        string qType;
        int val1, val2;

        do
        {
            cin >> qType;
            if(qType[0]!='D')
            {
                cin >> val1 >> val2;
                assert(val1 >=0 && val2>=0);
                if(qType[0]=='Q')
                    cout << myHLD.get(val1,val2) << '\n';
                else
                {
                    if(val1<myHLD.parents.size())
                        myHLD.set(val1,val2);
                }
            }
        }
        while(qType[0]!='D');

    }



}
