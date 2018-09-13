#include<iostream>
#include<vector>
#include<algorithm>
#include<cassert>

using namespace std;

const int NO_ANSWER = -(1000*1000);


struct SegmentTree
{
    vector<int> maxes;
    int _size;


    SegmentTree(const vector<int> & source)
    {
        _size = 1;

        while(_size<source.size())
            _size*=2;

        maxes.assign(_size*2,NO_ANSWER);

        for(int i = 0; i<source.size(); i++)
            maxes[i+_size] = source[i];
        for(int i = _size-1; i>0; i--)
            maxes[i] = _f(maxes[i*2],maxes[i*2+1]);
    }

    SegmentTree(int size = 0)
    {
        _size = 1;

        while(_size<size)
            _size*=2;

        maxes.assign(_size*2,NO_ANSWER);
    }

    static int _f(int a, int b)
    {
        return max(a,b);
    }

    int _get(int l, int r, int minL, int maxR, int _i)
    {
        if(l>r)
            return +NO_ANSWER;
        if(l==minL && r == maxR)
            return maxes[_i];

        int mid = (minL+maxR)/2;

        return _f(_get(l,min(r,mid), minL, mid, _i*2),
                 _get(max(mid+1, l), r, mid+1, maxR, _i*2 + 1));
    }

    int _change(int i, int val, int minL, int maxR, int _i)
    {
        if(i<minL||maxR<i)
            return maxes[_i];
        if(minL==maxR)
            return (maxes[_i] = val);

        int mid = (minL+maxR)/2;

        if(i<=mid)
            return maxes[_i] = _f(_change(i, val, minL, mid, _i*2),
                                  maxes[_i*2+1]);
        else
            return maxes[_i] = _f(maxes[_i*2],
                              _change(i, val, mid+1,maxR, _i*2 + 1));
    }

    int get(int l, int r)
    {
        return _get(l,r, 1, _size, 1);
    }

    void change(int i, int val)
    {
        _change(i, val, 1, _size, 1);
    }

    void apply(const SegmentTree & left, const SegmentTree & right, int x)
    {
        assert(left.maxes.size()==right.maxes.size() && maxes.size() == right.maxes.size());
        x+=_size-1;
        while(x>0)
        {
            maxes[x] = _f(left.maxes[x], right.maxes[x]);
            x/=2;
        }
    }

};


SegmentTree operator + (const SegmentTree & left, const SegmentTree & right)
{
    assert(left.maxes.size()==right.maxes.size());

    SegmentTree res = left;

    for(int i = 0; i<right.maxes.size(); i++)
        res.maxes[i] = right._f(right.maxes[i], left.maxes[i]);

    return res;
}

struct SegmentTree2D
{
    vector<SegmentTree> maxes;
    int _size;

    SegmentTree2D(const vector<vector<int> > & source)
    {
        _size = 1;
        while(_size<source.size())
            _size*=2;
        maxes.assign(_size*2, SegmentTree(source[0].size()));

        for(int i = 0; i<source.size(); i++)
            maxes[i+_size] = SegmentTree(source[i]);


        for(int i = _size-1; i>0; i--)
            maxes[i] = maxes[i*2] + maxes[i*2+1];
    }

    static int _f(int a, int b)
    {
        return max(a,b);
    }

    int _get(int l, int r, int minL, int maxR, int _i, int hL, int hR)
    {
        if(l>r)
            return NO_ANSWER;
        if(l == minL && r == maxR)
            return maxes[_i].get(hL, hR);

        int mid = (minL+maxR)/2;
        return _f(_get(l, min(r,mid), minL, mid, _i*2, hL, hR),
                  _get(max(l,mid+1), r, mid+1, maxR, _i*2+1, hL, hR));
    }

    int get(int vL, int vR, int hL, int hR)
    {
        return _get(vL, vR, 1, _size, 1, hL, hR);
    }

    void _change(int x, int val, int minL, int maxR, int _i, int y)
    {
        if(x < minL || maxR < x)
            return;
        if(minL == maxR)
        {
            maxes[_i].change(y,val);
            return;
        }
        int mid = (minL + maxR)/2;

        if(x<=mid)
            _change(x, val, minL, mid, _i*2, y);
        else
            _change(x, val, mid+1, maxR, _i*2+1, y);

        maxes[_i].apply(maxes[_i*2],maxes[_i*2 + 1], y);
    }

    void change(int x, int y, int val)
    {
        _change(x, val, 1, _size, 1, y);
    }
};


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<int>> field(n, vector<int>(m));

    for(int i = 0; i<n; i++)
        for(int j = 0; j<m; j++)
            cin >> field[i][j];

    SegmentTree2D ST(field);


    while(q--)
    {
        char qType;
        cin >> qType;
        if(qType=='?')
        {
            int xV, yV, xH, yH;
            cin >> xV >> yV >> xH >> yH;
            cout << ST.get(xV, yV, xH, yH) << '\n';
        }
        else
        {
            int x, y, val;
            cin >> x >> y >> val;
            ST.change(x,y,val);
        }
    }


    return 0;
}
