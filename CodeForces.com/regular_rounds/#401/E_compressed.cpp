#include<iostream>
#include<algorithm>
#include<vector>


using namespace std;


const long long nothing = 0;


struct SegmentTree
{
    int size;
    vector<long long> mx{};

    SegmentTree(int n) : size(n)
    {
        while(size&(size-1))
            size&=(size-1);

        if(n!=size)
            size*=2;
        mx.assign(size*2, 0);
    }

    long long _get(int l, int r, int minL, int maxR, int _i)
    {
        if(l>r)
            return nothing;
        if(minL == l && maxR == r)
            return mx[_i];

        int mid = (minL+maxR)/2;

        return max(_get(l, min(r,mid), minL, mid, _i*2),
                   _get(max(l, mid+1), r, mid+1, maxR, _i*2 + 1));
    }

    long long get(int l, int r)
    {
        return _get(l, r, 1, size, 1);
    }

    long long _set(int i, int minL, int maxR, int _i, long long val)
    {
        if(i<minL || i>maxR)
            return mx[_i];

        if(minL == maxR)
            return mx[_i] = max(mx[_i], val);

        int mid = (minL+maxR)/2;

        mx[_i] = max(_set(i, minL, mid, _i*2, val),
                     _set(i, mid+1, maxR, _i*2+1, val));
        return mx[_i];
    }

    void set(int pos, long long val)
    {
        _set(pos, 1, size, 1, val);
    }
};

struct disk
{
    int a, b, h;
};

bool operator < (const disk & a, const disk & b)
{
    if(a.b!=b.b)
        return a.b > b.b;
    else
        return a.a > b.a;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    SegmentTree ST(100*1000 + 100);

    int n;
    cin >> n;

    vector<disk> a(n);
    vector<int> possibleValues;

    for(auto & i : a)
    {
        cin >> i.a >> i.b >> i.h;
        possibleValues.push_back(i.a);
    }

    sort(possibleValues.begin(), possibleValues.end());
    sort(a.begin(),a.end());


    long long maxH = 0;
    for(auto & i : a)
    {
        auto it = lower_bound(possibleValues.begin(),
                              possibleValues.end(), i.b);

        long long curH = ST.get(1, it - possibleValues.begin()) + i.h;
        maxH = max(curH, maxH);

        it = lower_bound(possibleValues.begin(),
                         possibleValues.end(), i.a);

        ST.set(it - possibleValues.begin() + 1, curH);
    }

    cout << maxH;


    return 0;
}

