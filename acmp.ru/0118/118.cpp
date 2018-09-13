#include<iostream>
#include<vector>

using namespace std;

struct SegmentTree
{
    vector<int> zeros;
    int _size;

    SegmentTree(int n)
    {
        _size = 1;
        while(_size < n)
            _size*=2;

        zeros.assign(_size*2, 0);

        for(int i = 0; i<n; i++)
            zeros[i+_size] = 1;

        for(int i = _size-1; i>0; i--)
            zeros[i] = zeros[i*2] + zeros[i*2+1];
    }

    int _get(int l, int r, int minL, int maxR, int _i)
    {
        if(l==minL && r == maxR)
            return zeros[_i];
        if(l>r)
            return 0;

        int mid = (minL + maxR)/2;

        return _get(l, min(r, mid), minL, mid, _i*2)+
               _get(max(l,mid+1), r, mid+1, maxR, _i*2+1);

    }

    int get(int l, int r)
    {
        return _get(l, r, 1, _size, 1);
    }

    int _set(int i, int minL, int maxR, int _i)
    {
        if(minL==maxR)
            if(i==minL)
                return zeros[_i] = 0;
            else
                return zeros[_i];
        if(i<minL || maxR < i)
            return zeros[_i];

        int mid = (minL + maxR)/2;

        return zeros[_i] = _set(i, minL, mid, _i*2) +
                           _set(i, mid+1, maxR, _i*2+1);
    }

    void set(int i)
    {
        _set(i, 1, _size, 1);
    }

    int _getKth(int l, int r, int k, int minL, int maxR, int _i)
    {
        if(minL == maxR)
            return _i;

        int mid = (minL + maxR)/2;
        int tmp = get(l,min(mid,r));

        if(tmp >= k)
            return _getKth(l, min(mid, r), k, minL, mid, _i*2);
        else
            return _getKth(max(mid+1,l), r, k-tmp, mid+1, maxR, _i*2+1);
    }

    int getKth(int l, int r, int k)
    {
        return _getKth(l,r,k, 1, _size, 1) - _size + 1;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;

    cin >> n >> k;

    SegmentTree st(n);

    int last = 1;
    for(int i = n; i>1; i--)
    {
        int kCur = k%i;
        if(kCur==0)
            kCur+=i;
        int tmpSum = st.get(last, n);

        if(tmpSum < kCur)
        {
            kCur-=tmpSum;
            last = 1;
        }
        last = st.getKth(last, n, kCur);
        st.set(last);

    }

    cout << st.getKth(1, n, 1);


    return 0;
}
