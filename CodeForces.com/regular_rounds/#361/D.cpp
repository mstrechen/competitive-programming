#include<iostream>
#include<map>



using namespace std;

int a[100500*2],b[100500*2];


const int inf = 1000000007;


struct segmentTree
{
    int _s;
    int _min[262144+1], _max[262144+1];
    segmentTree()
    {
        _s = 262144/2;
        for(int i = 0; i<=262144; i++)
        {
            _min[i] = inf;
            _max[i] = -inf;
        }
    }
    void update(int i, int val, bool mode) //0 - min, 1 - max
    {

        if(mode)
            _update1(1, i, 1, _s,val);
        else
            _update0(1, i, 1, _s,val);

    }
    void _update0(int _i, int i, int l, int r, int val)
    {
        if(l==r)
            _min[_i] = val;
        else
        {
            int mid = (l+r)/2;
            _min[_i] = min(_min[_i], val);
            if(i<=mid)
            {
                _update0(_i*2, i, l, mid, val);
            }
            else
            {
                _update0(_i*2+1, i,  mid+1,r , val);
            }

        }
    }
    void _update1(int _i, int i, int l, int r, int val)
    {
        if(l==r)
            _max[_i] = val;
        else
        {
            int mid = (l+r)/2;
            _max[_i] = max(_max[_i], val);
            if(i<=mid)
            {
                _update1(_i*2, i, l, mid, val);
            }
            else
            {
                _update1(_i*2+1, i,  mid+1,r , val);
            }

        }
    }
    int get(int l, int r, int mode)
    {
        if(mode == 0)
        {
            if(l>r)
                return 100500;
            return get0(1, l, r, 1, _s);
        }
        else
        {
            if(l>r)
                return 1005001;
            return get1(1, l, r, 1, _s);
        }
    }
    int get0(int _i, int l, int r, int minL, int maxR)
    {
        int mid = (minL+maxR)/2;
        if(l==minL&&maxR==r)
            return _min[_i];
        if(l>mid)
        {
            return get0(_i*2+1, l,r, mid+1, maxR);
        }
        else
        if(r<=mid)
        {
            return get0(_i*2, l,r, minL, mid);
        }
        else
        {
            return min(get0(_i*2, l,mid, minL, mid),get0(_i*2+1, mid+1,r, mid+1, maxR));
        }
    }
    int get1(int _i, int l, int r, int minL, int maxR)
    {
        int mid = (minL+maxR)/2;
        if(l==minL&&maxR==r)
            return _max[_i];
        if(l>mid)
        {
            return get1(_i*2+1, l,r, mid+1, maxR);
        }
        else
        if(r<=mid)
        {
            return get1(_i*2, l,r, minL, mid);
        }
        else
        {
            return max(get1(_i*2, l,mid, minL, mid),get1(_i*2+1, mid+1,r, mid+1, maxR));
        }
    }


} _ST;


int main()
{
    ios::sync_with_stdio(false);
    int n;

    cin >> n;
    long long ans = 0;
    for(int i = 0; i<n; i++)
    {
        cin>> a[i];
        _ST.update(i+1, a[i], 1);
    }
    for(int i = 0; i<n; i++)
    {
        cin>> b[i];
        _ST.update(i+1, b[i], 0);
    }
    int l = 0;

    for(int i = 0; i<n; i++)
    {
        int r = i, l = 0;
        for(;l<r-1;)
        {
            int mid = (l+r)/2;
            if(_ST.get(mid+1, i+1,0)!=_ST.get(mid+1, i+1,1))
                l = mid;
            else
                r = mid;
        }
        if(_ST.get(r+1, i+1,0)!=_ST.get(r+1, i+1,1))
            r++;
        cout << r << endl;
        ans+=max(i-r+1,0);
    }
    cout << ans;

    return 0;
}
