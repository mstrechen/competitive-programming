#include<iostream>
#include<vector>

using namespace std;

struct SegmentTree
{
    vector<int> sum;
    vector<char> xored;
    int _size;

    SegmentTree(const vector<int> & seq, int bitToRead)
    {
        _size = 1;
        while(_size < (int)seq.size())
            _size*=2;

        sum.assign(_size*2, 0);
        xored.assign(_size*2, 0);

        for(int i = 0; i<(int)seq.size(); i++)
            sum[i + _size] = (seq[i] >> bitToRead)&1;

        for(int i = _size - 1; i>0; i--)
            sum[i] = sum[i*2] + sum[i*2 + 1];
    }

    int _xorApply(int l, int r, int minL, int maxR, int _i)
    {
        if(l == minL && r == maxR)
        {
            xored[_i]^=1;

            if(xored[_i])
                return maxR - minL + 1 - sum[_i];
            return sum[_i];
        }

        if(l>r)
        {
            if(xored[_i])
                return maxR - minL + 1 - sum[_i];
            return sum[_i];
        }

        int mid = (minL + maxR)/2;

        sum[_i] = _xorApply(l, min(r, mid), minL, mid, _i*2) +
                  _xorApply(max(l, mid+1), r, mid+1, maxR, _i*2 + 1);

        if(xored[_i])
            return maxR - minL + 1 - sum[_i];
        return sum[_i];
    }

    void xorApply(int l, int r)
    {
        _xorApply(l, r, 1, _size, 1);
    }

    int _getSum(int l, int r, int minL, int maxR, int _i) const
    {
        if(l == minL && r == maxR)
        {
            if(xored[_i])
                return maxR - minL + 1 - sum[_i];
            return sum[_i];
        }

        if(l>r)
            return 0;

        int mid = (minL + maxR)/2;

        if(xored[_i])
        {
            return  r - l + 1
                   - (_getSum(l, min(r, mid), minL, mid, _i*2) +
                      _getSum(max(l,mid+1), r, mid+1, maxR, _i*2 + 1));
        }

        return    _getSum(l, min(r, mid), minL, mid, _i*2) +
                  _getSum(max(l,mid+1), r, mid+1, maxR, _i*2 + 1);

    }
    long long getSum(int l, int r) const
    {
        return _getSum(l, r, 1, _size, 1);
    }
};

struct BigSegmentTree
{
    vector<SegmentTree> STs;
    int len;

    BigSegmentTree(const vector<int> & source, int len = 20) : len(len)
    {
        for(int i = 0; i<len; i++)
            STs.emplace_back(source, i);
    }

    void xorApply(int num, int l, int r)
    {
        for(int i = 0; i<len; i++)
            if((num>>i)&1)
                STs[i].xorApply(l,r);
    }

    long long getSum(int l, int r) const
    {
        long long ans = 0;
        for(int i = 0; i < len; i++)
        {
            ans += (STs[i].getSum(l,r) << (long long)i);
        }

        return ans;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> nums(n);

    for(auto & i : nums)
        cin >> i;

    BigSegmentTree ST(nums);


    int q;
    cin >> q;

    for(int i = 0; i<q; i++)
    {
        int type, l, r, toXor;
        cin >> type >> l >> r;

        if(type == 1)
        {
            cout << ST.getSum(l,r) << '\n';
        }
        else
        {
            cin >> toXor;
            ST.xorApply(toXor, l, r);
        }
    }


    return 0;
}
