#include<iostream>
#include<vector>

using namespace std;

struct SegmentTree
{
    vector<long long> sums, add;
    int _size;
    int n;

    SegmentTree(istream & in)
    {
        in >> n;

        _size = 1;
        while(_size<n)
            _size*=2;

        sums.assign(_size*2, 0);
        add.assign(_size*2, 0);
        for(int i = 0; i<n; i++)
            in >> sums[i+_size];
        for(int i = _size-1; i>0; i--)
        {
            sums[i] = sums[i*2] + sums[i*2+1];
        }
    }

    long long _add(int l, int r, int minL, int maxR, int _i, long long val)
    {
        if(l>r)
            return sums[_i] + add[_i]*(maxR-minL+1);

        if(l==minL && r==maxR)
        {
            add[_i]+=val;
            return sums[_i] + add[_i]*(r-l+1);
        }
        int mid = (minL + maxR)/2;
        return (sums[_i] = _add(l, min(r,mid), minL, mid, _i*2, val) +
                          _add(max(l,mid+1), r, mid+1, maxR, _i*2+1, val)
                ) + add[_i]*(maxR-minL+1);
    }

    void change(int l, int r, long long val)
    {
        _add(l, r, 1, _size, 1, val);
    }

    long long _get(int l, int r, int minL, int maxR, int _i)
    {
        if(l>r)
            return 0;
        if(l==minL && r ==maxR)
            return sums[_i] + add[_i]*(r-l+1);

        int mid = (minL+maxR)/2;

        return add[_i]*(r-l+1) +
                _get(l, min(mid,r), minL, mid, _i*2)+
                _get(max(l,mid+1), r, mid+1, maxR, _i*2+1);

    }
    long long get(int l, int r)
    {
        return _get(l,r,1,_size,1);
    }

};


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    SegmentTree ST(cin);

    vector<long long> saved(400,0);


    int q;
    cin >> q;

    while(q--)
    {
        int qType;
        cin >> qType;
        if(qType == 1)
        {
            int l, r;
            long long val;
            cin >> l >> r >> val;
            ST.change(l,r,val);
        }
        else
        if(qType == 2)
        {
            int d;
            long long val;
            cin >> d >> val;
            if(d<400)
                saved[d]+=val;
            else
            {
                for(int i = d; i<=ST.n; i+=d)
                    ST.change(i,i,val);
            }
        }
        else
        {
            int l, r;
            long long ans;
            cin >> l >> r;
            ans = ST.get(l,r);

            for(int i = 1; i<400; i++)
                ans+=saved[i]*(r/i-(l-1)/i);
            cout << ans << '\n';
        }
    }

    return 0;
}
