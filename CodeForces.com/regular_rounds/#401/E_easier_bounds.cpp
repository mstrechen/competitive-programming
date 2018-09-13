#include<iostream>
#include<algorithm>
#include<vector>


using namespace std;


const long long nothing = 0*0*0;

struct node
{
    node * left, * right;
    long long value;

    node(long long val = nothing) : left(nullptr), right(nullptr), value(val){}

    static long long getVal(node * nd)
    {
        if(nd == nullptr)
            return nothing;
        return nd->value;
    }
};

struct SegmentTree
{
    int size;

    node * root;

    SegmentTree(int n) : size(n), root(new node)
    {

    }

    long long _get(int l, int r, int minL, int maxR, node * cur)
    {
        if(cur == nullptr || l>r)
            return nothing;
        if(minL == l && maxR == r)
            return node::getVal(cur);

        int mid = minL/2 + maxR/2 + (minL%2 + maxR%2)/2;

        return max(_get(l, min(r,mid), minL, mid, cur->left),
                   _get(max(l, mid+1), r, mid+1, maxR, cur->right));
    }

    long long get(int l, int r)
    {
        return _get(l, r, 1, size, root);
    }

    node * _set(int i, int minL, int maxR, node * cur, long long val)
    {
        if(i<minL || i>maxR)
            return cur;

        if(cur == nullptr)
            cur = new node;

        if(minL == maxR)
        {
            cur->value = max(cur->value, val);
            return cur;
        }

        int mid = (minL+maxR)/2;

        cur->left = _set(i, minL, mid, cur->left, val);
        cur->right = _set(i, mid+1, maxR , cur->right, val);
        cur->value = max(node::getVal(cur->left),
                         node::getVal(cur->right));
        return cur;
    }

    void set(int pos, long long val)
    {
        _set(pos, 1, size, root, val);
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

    SegmentTree ST(1000*1000*1000 + 1);

    int n;
    cin >> n;

    vector<disk> a(n);

    for(auto & i : a)
        cin >> i.a >> i.b >> i.h;

    sort(a.begin(),a.end());


    long long maxH = 0;
    for(auto & i : a)
    {
        long long curH = ST.get(1, i.b - 1) + i.h;
        maxH = max(curH, maxH);

        ST.set(i.a, curH);
    }

    cout << maxH;


    return 0;
}
